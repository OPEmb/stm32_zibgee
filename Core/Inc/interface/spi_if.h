#ifndef SPI_F_H
#define SPI_F_H

#include <stdint.h>
#include "gpio_if.h"

typedef struct spi_if_t spi_if_t;

// return 0 indicates success
typedef int (*spi_tx_fn)(spi_if_t* spi_if,const uint8_t* data,uint16_t len);
typedef int (*spi_rx_fn)(spi_if_t* spi_if,uint8_t* data,uint16_t len);

struct spi_if_t {
    uint8_t cs;
    spi_tx_fn spi_tx;
    spi_rx_fn spi_rx; 
    gpio_if_t* cs_pin;
};

static inline spi_if_t spi_if_init(spi_tx_fn spi_tx,spi_rx_fn spi_rx,uint8_t cs,gpio_if_t* cs_pin){
    return (spi_if_t){
        .cs = cs,
        .spi_tx = spi_tx,
        .spi_rx = spi_rx,
        .cs_pin = cs_pin,
    };
}

#endif /* SPI_F_H */