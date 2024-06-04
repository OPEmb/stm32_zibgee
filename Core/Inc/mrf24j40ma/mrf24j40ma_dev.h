#ifndef MRF24J40MA_H
#define MRF24J40MA_H

#include "spi_if.h"
#include "mrf24j40ma_mem.h"
#include "mrf24j40ma_address_space.h"

typedef void (*mrf24j40ma_delay_us_fn)(uint16_t us);
typedef void (*mrf24j40ma_on_isr_fn)(void);

typedef int (*mrf24j40ma_generic_fn)(void);

typedef struct{
    spi_if_t* spi;
    gpio_if_t* reset_pin;

    mrf24j40ma_long_address_space_t LAS;
    mrf24j40ma_short_control_regs_t short_regs;

    mrf24j40ma_delay_us_fn delay_us;

    mrf24j40ma_generic_fn init;
    mrf24j40ma_generic_fn perform_testing;
} mrf24j40ma_dev_t;

void mrf24_create_dev(mrf24j40ma_dev_t* dev,gpio_if_t* reset_pin,spi_if_t* spi,mrf24j40ma_delay_us_fn delay_us);

#endif /* MRF24J40MA_H */