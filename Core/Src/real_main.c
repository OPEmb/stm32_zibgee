/*
 * real_main.c
 *
 *  Created on: May 22, 2024
 */
#include "main.h"
#include "usbd_cdc_if.h"
#include "mrf24j40ma_mem.h"
#include "stm32h7xx_hal.h"

/* Read/Write SPI Commands for Short and Long Address registers. */
#define MRF24J40_READSHORT(reg) ((reg) << 1)
#define MRF24J40_WRITESHORT(reg) ((reg) << 1 | 1)
#define MRF24J40_READLONG(reg) (1 << 15 | (reg) << 5)
#define MRF24J40_WRITELONG(reg) (1 << 15 | (reg) << 5 | 1 << 4)

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
	uint8_t data = 0;
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

	status = HAL_SPI_Transmit(spi,data,size,1);
	if(status != HAL_OK){
		__NOP();
	}

	cs_high();
}

static void write_long(uint16_t addr,uint8_t data){
	write_long_l(addr,&data,1);
}

static void write_tx_fifo(const uint8_t offset,const uint8_t* data,uint8_t size){
	uint32_t status = HAL_OK;
	const uint16_t addr = 128 * offset;
	uint8_t high = 0x80 | (addr >> 3);
	uint8_t low =  0x10 | addr << 5;
	uint8_t u8_addr[2] = {high,low};

	cs_low();
	status = HAL_SPI_Transmit(spi,u8_addr,2, 1);
	status = HAL_SPI_Transmit(spi,data,size,1 * size);
	cs_high();
}

static void read_tx_fifo(const uint8_t offset,uint8_t* data,uint8_t size){
	uint32_t status = HAL_OK;
	const uint16_t addr = 128 * offset;
	uint8_t high = 0x80 | (addr >> 3);
	uint8_t low =  addr << 5;
	uint8_t u8_addr[2] = {high,low};

	cs_low();
	status = HAL_SPI_Transmit(spi,u8_addr,2, 1);
	status = HAL_SPI_Receive(spi,data,size,1 * size);
	cs_high();
}

static void write_rx_fifo(uint8_t* data,uint8_t size){
	uint32_t status = HAL_OK;
	const uint16_t addr = 0x300;
	uint8_t high = 0x80 | (addr >> 3);
	uint8_t low =  0x10 | addr << 5;
	uint8_t u8_addr[2] = {high,low};

	cs_low();
	status = HAL_SPI_Transmit(spi,u8_addr,2, 1);
	status = HAL_SPI_Transmit(spi,data,size,1 * size);
	cs_high();
}

static void read_rx_fifo(uint8_t* data,uint8_t size){
	uint32_t status = HAL_OK;
	const uint16_t addr = 0x300;;
	uint8_t high = 0x80 | (addr >> 3);
	uint8_t low =  addr << 5;
	uint8_t u8_addr[2] = {high,low};

	cs_low();
	status = HAL_SPI_Transmit(spi,u8_addr,2, 1);
	status = HAL_SPI_Receive(spi,data,size,1 * size);
	cs_high();
}

void set_interrupts(void) {
  // interrupts for rx and tx normal complete
  write_short(MRF_INTCON, 0b11110110);
}

void set_channel(uint8_t channel) {
  //  (((channel - 11) << 4) | 0x03));
  uint8_t res = (((channel - 11) << 4) | 0x03);
  write_long(MRF_RFCON0, res);
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
    set_channel(12);
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
static int int_empty;
static volatile uint8_t interrupt;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	int_triggered++;
	interrupt = 1;
}

static uint32_t wait_int_until_timeout(uint32_t timeout){
	uint32_t tick_start = HAL_GetTick();
	uint32_t elapsed = 0;
	uint32_t ret = 0;
	while(!interrupt){
		elapsed = HAL_GetTick() - tick_start;
		if(timeout == 0 || elapsed > timeout){
			ret = 0;
			break;
		}
	}
	interrupt = 0;
	ret = elapsed;
	return elapsed;
}

void send_piflar(void){
	const char* p = "PIFLAR";
	int len = 6;
	uint8_t hdr[] = {
			0x09,
			0x09 + len,
			0x41,0x88,
			0x01,0x66,
			0x33,
			0xFF,0xFF,
			0x11,0x11,
	};
	uint8_t frame[sizeof(hdr) + len];
	memcpy(frame,hdr,sizeof(hdr));
	memcpy(frame + sizeof(hdr),p,len);
	write_tx_fifo(0,frame,sizeof(frame));
	write_short(MRF_TXNCON,  (1<<MRF_TXNACKREQ | 1<<MRF_TXNTRIG));
}

void send2(char* data){
	int len = strlen(data);
	uint8_t hdr[] = {
			0x0F,0x0F + len, // hdr len, hdr len + frame len
			0x41,0x8C, // FC
			0x01, // SN
			0x23,0x23, // dest PANID
			0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05, // dest
			0xB2,0x94 // src
	};
	uint8_t frame[sizeof(hdr) + len];
	memcpy(frame,hdr,sizeof(hdr));
	memcpy(frame + sizeof(hdr),data,len);
	write_tx_fifo(0,frame,sizeof(frame));
	write_short(MRF_TXNCON, (1<<MRF_TXNACKREQ | 1<<MRF_TXNTRIG));
}

int sent;
uint32_t timeout = 0;
void real_main(SPI_HandleTypeDef* hspi){

	spi = hspi;

	mrf24j0_reset();

	uint8_t waketimel = 0;
	while(waketimel != 10){ // default value at reset
		read_long(0x222,&waketimel);
	}
	init();

	set_pan(0xFFFF);

	while(1){
		send_piflar();
		sent++;
		timeout = wait_int_until_timeout(1000);
		uint8_t last_interrupt = read_short(MRF_INTSTAT);
		uint8_t tx_stat = read_short(MRF_TXSTAT);
		while(!last_interrupt){
			last_interrupt = read_short(MRF_INTSTAT);
			write_long(0x222,0xA);
			read_long(0x222,&waketimel);
			HAL_Delay(100);
			int_empty++;
		}


	}


	asm ("nop");
}
