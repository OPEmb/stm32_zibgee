/*
 * real_main.c
 *
 *  Created on: May 22, 2024
 */
#include "main.h"
#include "usbd_cdc_if.h"
#include "mrfj24_defs.h"
#include "stm32h7xx_hal.h"

// [1] MRF24J40 IEEE 802.15.4 2.4GHz RF Transceiver

static SPI_HandleTypeDef* spi;
extern uint8_t UserRxBufferFS[APP_RX_DATA_SIZE];
extern uint8_t UserTxBufferFS[APP_TX_DATA_SIZE];
uint32_t usb_rx_len;
volatile uint8_t usb_rx_flag;

static void delay_1ms(void){
	HAL_Delay(1);
}

static void delay_2ms(void){
	HAL_Delay(2);
}

static void mrf24j0_cs_pin(uint8_t state){
	HAL_GPIO_WritePin(MRF_CS_GPIO_Port,MRF_CS_Pin,state);
}

static void mrf24j0_reset(void){
	HAL_GPIO_WritePin(MRF_RST_GPIO_Port,MRF_RST_Pin,0);
	HAL_GPIO_WritePin(MRF_RST_GPIO_Port,MRF_RST_Pin,1);
	delay_2ms(); // Section 3.0
}

static void cs_low(void){
	mrf24j0_cs_pin(0);
}

static void cs_high(void){
	mrf24j0_cs_pin(1);
}

static uint8_t read_short(uint8_t addr){


	// 7 6 5 4 3 2 1 0
	// 0 x x x x x x 0
	// 7th bit is short addressing,
	// xxxxxx is address,
	// 0th bit is 0 for read operation

	uint32_t status = HAL_OK;

	// we should only need to shift it once, if you pass wrong value to this function your own problem
	addr <<= 1;
	cs_low();
	status = HAL_SPI_Transmit(spi,&addr,1, 1);
	if(status != HAL_OK){
		asm ("nop");
	}
	uint8_t data = 1;
	status = HAL_SPI_Receive(spi, &data, 1, 1);

	if(status != HAL_OK){
		asm ("nop");
	}

	cs_high();
	return data;
}

static void write_short(uint8_t addr,uint8_t data){
	uint32_t status = HAL_OK;

	addr = addr << 1 | 0x01;

	uint8_t tx[2] = {addr,data};
	cs_low();
	status = HAL_SPI_Transmit(spi,tx,2, 1);
	if(status != HAL_OK){
		asm ("nop");
	}

	cs_high();
}



static void read_long_l(uint16_t addr,uint8_t* data,uint16_t size){
	uint32_t status = HAL_OK;

	uint8_t high = 0x80 | (addr >> 3);
	uint8_t low = addr << 5;
	uint8_t u8_addr[2] = {high,low};

	cs_low();
	status = HAL_SPI_Transmit(spi,u8_addr,2, 1);
	if(status != HAL_OK){
		asm ("nop");
	}

	status = HAL_SPI_Receive(spi,data,size,1);

	cs_high();
}

static void read_long(uint16_t addr,uint8_t* data){
	read_long_l(addr,data,1);
}

static void write_long_l(uint16_t addr,uint8_t* data,uint16_t size){
	uint32_t status = HAL_OK;

	uint8_t high = 0x80 | (addr >> 3);
    uint8_t low =  0x10 | addr << 5;
    uint8_t u8_addr[2] = {high,low};

	cs_low();
	status = HAL_SPI_Transmit(spi,u8_addr,2, 1);
	if(status != HAL_OK){
		__NOP();
	}

	status = HAL_SPI_Receive(spi,data,size,1);

	cs_high();
}

static void write_long(uint16_t addr,uint8_t data){
	write_long_l(addr,&data,1);
}



typedef union{
	struct{
		uint8_t b1 : 1;
		uint8_t b2 : 1;
		uint8_t b3 : 1;
		uint8_t b4 : 1;
		uint8_t b5 : 1;
		uint8_t b6 : 1;
		uint8_t b7 : 1;
	}b;
	struct{
		uint8_t b1 : 1;
		uint8_t b2 : 1;
		uint8_t b3 : 1;
		uint8_t b4 : 1;
		uint8_t b5 : 1;
		uint8_t b6 : 1;
		uint8_t b7 : 1;
	}r;
	uint8_t val;
} reg_t;

typedef union{
struct{
	uint8_t PROMI    : 1;
	uint8_t COORD    : 1;
	uint8_t PANCOORD : 1;
	uint8_t          : 1;
	uint8_t NOACKRSP : 1;
	uint8_t          : 1;
	uint8_t          : 1;
};
uint8_t val;
} RXMCR_REG_t;

void set_interrupts(void) {
  // interrupts for rx and tx normal complete
  write_short(MRF_INTCON, 0b11110110);
}

void set_channel(uint8_t channel) {
  //  (((channel - 11) << 4) | 0x03));
  write_long(MRF_RFCON0, (((channel - 11) << 4) | 0x03));
}

void init(void) {
    /*
    // Seems a bit ridiculous when I use reset pin anyway
    write_short(MRF_SOFTRST, 0x7); // from manual
    while (read_short(MRF_SOFTRST) & 0x7 != 0) {
        ; // wait for soft reset to finish
    }
    */
    write_short(MRF_PACON2, 0x98); // – Initialize FIFOEN = 1 and TXONTS = 0x6.
    write_short(MRF_TXSTBL, 0x95); // – Initialize RFSTBL = 0x9.

    write_long(MRF_RFCON0, 0x03); // – Initialize RFOPT = 0x03.
    write_long(MRF_RFCON1, 0x01); // – Initialize VCOOPT = 0x02.
    write_long(MRF_RFCON2, 0x80); // – Enable PLL (PLLEN = 1).
    write_long(MRF_RFCON6, 0x90); // – Initialize TXFIL = 1 and 20MRECVR = 1.
    write_long(MRF_RFCON7, 0x80); // – Initialize SLPCLKSEL = 0x2 (100 kHz Internal oscillator).
    write_long(MRF_RFCON8, 0x10); // – Initialize RFVCO = 1.
    write_long(MRF_SLPCON1, 0x21); // – Initialize CLKOUTEN = 1 and SLPCLKDIV = 0x01.

    //  Configuration for nonbeacon-enabled devices (see Section 3.8 “Beacon-Enabled and
    //  Nonbeacon-Enabled Networks”):
    write_short(MRF_BBREG2, 0x80); // Set CCA mode to ED
    write_short(MRF_CCAEDTH, 0x60); // – Set CCA ED threshold.
    write_short(MRF_BBREG6, 0x40); // – Set appended RSSI value to RXFIFO.
    set_interrupts();
    set_channel(11);
    // max power is by default.. just leave it...
    // Set transmitter power - See “REGISTER 2-62: RF CONTROL 3 REGISTER (ADDRESS: 0x203)”.
    write_short(MRF_RFCTL, 0x04); //  – Reset RF state machine.
    write_short(MRF_RFCTL, 0x00); // part 2
    delay_1ms();
}

void set_pan(uint16_t panid) {
    write_short(MRF_PANIDH, panid >> 8);
    write_short(MRF_PANIDL, panid & 0xff);
}

static int int_triggered;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	int_triggered++;
	uint8_t last_interrupt = read_short(MRF_INTSTAT);
	uint8_t tmp = read_short(MRF_TXSTAT);
	__NOP();
}

void send(char* data){
	int i = 0;
	int len = strlen(data);
	uint8_t ignoreBytes = 0;

	uint8_t bytes_MHR = 15;
	write_long(i++, bytes_MHR); // header length
	// +ignoreBytes is because some module seems to ignore 2 bytes after the header?!.
	// default: ignoreBytes = 0;


	//bytes_MHR = 2 Frame control + 1 sequence number + 2 panid + 8 shortAddr Destination + 8 shortAddr Source
	write_long(i++, bytes_MHR+ignoreBytes+len);

	// 0 | pan compression | ack | no security | no data pending | data frame[3 bits]
	write_long(i++, 0x61); // first byte of Frame Control
	// 16 bit source, 802.15.4 (2003), 16 bit dest,
	write_long(i++, 0x8c); // second byte of frame control
	write_long(i++, 1);  // sequence number 1


	write_long(i++, 0x2323 & 0xff);  // dest panid
	write_long(i++, 0x2323 >> 8);

	// Dest
	write_long(i++, 0x57);
	write_long(i++, 0xeb);
	write_long(i++, 0x1c);
	write_long(i++, 0xe4);
	write_long(i++, 0xd6);
	write_long(i++, 0x2c);
	write_long(i++, 0x55);
	write_long(i++, 0xd6);
	//write_long(i++, dest16 & 0xff);  // dest16 low
	//write_long(i++, dest16 >> 8); // dest16 high

	// Source
	write_long(i++, 0xb2);
	write_long(i++, 0x94);


	//write_long(i++, src16 & 0xff); // src16 low
	//write_long(i++, src16 >> 8); // src16 high

	// All testing seems to indicate that the next two bytes are ignored.
	//2 bytes on FCS appended by TXMAC
	i+=ignoreBytes;
	for (int q = 0; q < len; q++) {
		write_long(i++, data[q]);
	}
	// ack on, and go!
	write_short(MRF_TXNCON, (1<<MRF_TXNACKREQ | 1<<MRF_TXNTRIG));
}

void real_main(SPI_HandleTypeDef* hspi){

	spi = hspi;
	RXMCR_REG_t rxmcr = {};

	mrf24j0_reset();

	uint8_t waketimel = 0;
	read_long(0x222,&waketimel);

	uint8_t data[] = {1,2,3,4};
	write_long_l(0,data,4);
	read_long_l(0,data,4);

	init();
	while(1){
		send("PIFLAR");
		HAL_Delay(100);
	}


	asm ("nop");
}
