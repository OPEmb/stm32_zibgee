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

#define RETURN_ON_ERR(x)  do {             \
        int rc_err = (x);                     \
        if (rc_err != 0) {          \
            return rc_err;                    \
        }                                  \
    } while(0)

#define NOT_IMPL return (-1)

STATIC int reset(void){
    NOT_IMPL;   
}

STATIC int test_interrupt(void){
    NOT_IMPL;
}

STATIC int test_spi(void){
    NOT_IMPL;
}

STATIC int perform_testing(void){
    RETURN_ON_ERR(test_spi());
    RETURN_ON_ERR(test_interrupt());
    NOT_IMPL;
}

STATIC int init(void){
    NOT_IMPL;
}

void mrf24_create_dev(mrf24j40ma_dev_t* dev,gpio_if_t* reset_pin,spi_if_t* spi,mrf24j40ma_delay_us_fn delay_us){
    assert(dev && spi && delay_us);
    memset(dev,0,sizeof(*dev));
    dev->spi = spi;
    dev->delay_us = delay_us;
    dev->reset_pin = reset_pin;

    dev->init = init;
}




