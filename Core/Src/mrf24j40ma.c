#include <assert.h>
#include <string.h>
#include "mrf24j40ma_dev.h"

#if defined(TEST)
#define STATIC
#else
#define STATIC static
#endif

// Bit initializations, need to handle up to 8 for __VA_ARGS__
#define INIT_BIT(b) .(b) = 1
#define INIT_BIT_1(_1) INIT_BIT(_1)
#define INIT_BIT_2(_1,_2) INIT_BIT(_1),INIT_BIT(_2)
#define INIT_BIT_3(_1,_2,_3) INIT_BIT(_1),INIT_BIT(_2),INIT_BIT(_3)
#define INIT_BIT_4(_1,_2,_3,_4) INIT_BIT(_1),INIT_BIT(_2),INIT_BIT(_3),INIT_BIT(_4)
#define INIT_BIT_5(_1,_2,_3,_4,_5) INIT_BIT(_1),INIT_BIT(_2),INIT_BIT(_3),INIT_BIT(_4),\
INIT_BIT(_5)
#define INIT_BIT_6(_1,_2,_3,_4,_5,_6) INIT_BIT(_1),INIT_BIT(_2),INIT_BIT(_3),INIT_BIT(_4),\
INIT_BIT(_5),INIT_BIT(_6)
#define INIT_BIT_7(_1,_2,_3,_4,_5,_6,_7) INIT_BIT(_1),INIT_BIT(_2),INIT_BIT(_3),INIT_BIT(_4),\
INIT_BIT(_5),INIT_BIT(_6),INIT_BIT(_7)
#define INIT_BIT_8(_1,_2,_3,_4,_5,_6,_7,_8) INIT_BIT(_1),INIT_BIT(_2),INIT_BIT(_3),INIT_BIT(_4),\
INIT_BIT(_5),INIT_BIT(_6),INIT_BIT(_7),INIT_BIT(_8)

// Cast type to NULL, this is only useful for referencing to certain struct members, see offsetof for more details
#define NULL_CAST(T) ((T*)0)

// Get type of short register
#define SHORT_REG_TYPE(reg)\
typeof(NULL_CAST(mrf24j0ma_short_control_regs_t)->r.reg)

// Get type of long register
#define LONG_REG_TYPE(reg)\
typeof(NULL_CAST(mrf24j40ma_long_control_regs_t)->r.reg)

// Generate value of short register with certain bits set
// Example usage:
// SHORT_REG(CCAEDTH,CCAEDTH0)
// which expands to (CCAEDTH_t){.CCAEDTH0 = 1}.val
#define SHORT_REG(reg,...) ((SHORT_REG_TYPE(reg)){PP_CAT2(INIT_BIT_,PP_VA_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)}).val

// Same as above, but for long registers
#define LONG_REG(reg,...) ((LONG_REG_TYPE(reg)){PP_CAT2(INIT_BIT_,PP_VA_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)}).val

// As per datasheet, addresses need to be adjusted based on address space and operation
#define MRF24J40_READSHORT_A(reg) ((reg) << 1)
#define MRF24J40_WRITESHORT_A(reg) ((reg) << 1 | 1)
#define MRF24J40_READLONG_A(reg) (1 << 15 | (reg) << 5)
#define MRF24J40_WRITELONG_A(reg) (1 << 15 | (reg) << 5 | 1 << 4)

#define DELAY_CONSTANT_US (192) // from datasheet

#define RETURN_ON_ERR(x)  do {      \
        int rc_err = (x);           \
        if (rc_err != 0) {          \
            return rc_err;          \
        }                           \
    } while(0)

#define NOT_IMPL return (-1)

STATIC int read_short_l(mrf24j40ma_dev_t* dev,uint8_t addr,uint8_t* value,uint16_t len){
	//dev->spi->tx_rx(dev->spi,&addr,)
}

STATIC int read_short(mrf24j40ma_dev_t* dev,uint8_t addr,uint8_t* value){

}

STATIC int read_long_l(mrf24j40ma_dev_t* dev,uint8_t addr,uint8_t* value,uint16_t len){

}

STATIC int read_long(mrf24j40ma_dev_t* dev,uint8_t addr,uint8_t* value){

}


STATIC int write_short_l(mrf24j40ma_dev_t* dev,uint8_t addr,uint8_t* value,uint16_t len){

}

STATIC int write_short(mrf24j40ma_dev_t* dev,uint8_t addr,uint8_t value){

}

STATIC int write_long_l(mrf24j40ma_dev_t* dev,uint8_t addr,uint8_t* value,uint16_t len){

}

STATIC int write_long(mrf24j40ma_dev_t* dev,uint8_t addr,uint8_t value){

}


STATIC int reset(mrf24j40ma_dev_t* dev){
	gpio_if_set_pin(dev->reset_pin);
    return 0;
}

STATIC int test_interrupt(mrf24j40ma_dev_t* dev){
    NOT_IMPL;
}

STATIC int test_spi(mrf24j40ma_dev_t* dev){
	uint8_t wakel = 0;

	return 0;
}

STATIC int perform_testing(mrf24j40ma_dev_t* dev){
    RETURN_ON_ERR(test_spi(dev));
    RETURN_ON_ERR(test_interrupt(dev));
    NOT_IMPL;
}

STATIC void interrupt(mrf24j40ma_dev_t* dev){

}

STATIC int init(mrf24j40ma_dev_t* dev){

/*
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
*/
	return 0;
}

void mrf24_create_dev(mrf24j40ma_dev_t* dev,gpio_if_t* reset_pin,spi_if_t* spi,mrf24j40ma_delay_us_fn delay_us
		,mrf24j40ma_isr_fn enable_int,mrf24j40ma_isr_fn disable_int){
    assert(dev && spi && delay_us && enable_int && disable_int);
    memset(dev,0,sizeof(*dev));
    dev->spi = spi;
    dev->delay_us = delay_us;
    dev->reset_pin = reset_pin;

    dev->init = init;
    dev->int_callback = interrupt;


    if(!perform_testing(dev)){
    	Error_Handler();
    }


}




