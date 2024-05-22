/*
 * real_main.c
 *
 *  Created on: May 22, 2024
 */
#include "main.h"
#include "mrfj24_defs.h"
#include "stm32h7xx_hal.h"

static void delay_1ms(void){
	HAL_Delay(1);
}

static void mrf24j0_cs_pin(uint8_t state){
	HAL_GPIO_WritePin(MRF_CS_GPIO_Port,MRF_CS_Pin,state);
}

static void mrf24j0_reset(void){
	HAL_GPIO_WritePin(MRF_RST_GPIO_Port,MRF_RST_Pin,0);
	delay_1ms();
	HAL_GPIO_WritePin(MRF_RST_GPIO_Port,MRF_RST_Pin,1);
	delay_1ms();
}

static void cs_low(void){
	mrf24j0_cs_pin(0);
}

static void cs_high(void){
	mrf24j0_cs_pin(1);
}

static uint8_t read_short(SPI_HandleTypeDef* spi,uint8_t addr){


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

static void write_short(SPI_HandleTypeDef* spi,uint8_t addr,uint8_t data){
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

static void read_long(SPI_HandleTypeDef* spi,uint16_t addr,uint8_t* data,uint16_t size){
	uint32_t status = HAL_OK;

	addr = addr <<  1 | 0x800;
	uint8_t* u8_addr = &addr;

	cs_low();
	status = HAL_SPI_Transmit(spi,u8_addr,2, 1);
	if(status != HAL_OK){
		asm ("nop");
	}

	status = HAL_SPI_Receive(spi,data,size,1);

	cs_high();
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
    //set_interrupts(); TODO
    //set_channel(12); TODO
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

void real_main(SPI_HandleTypeDef* spi){

	RXMCR_REG_t rxmcr = {};

	mrf24j0_reset();

	rxmcr.PROMI = 1;
	uint8_t panidl = 0x23;
	uint8_t panidh = 0x65;

	write_short(spi,0x00,rxmcr.val);
	write_short(spi,0x01,panidl);
	write_short(spi,0x02,panidh);

	uint8_t val = read_short(spi,0x00);
	panidl = read_short(spi,0x01);
	panidh = read_short(spi,0x02);

	asm ("nop");
}
