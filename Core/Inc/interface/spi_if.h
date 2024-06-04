#ifndef SPI_F_H
#define SPI_F_H

#include <stdint.h>
#include "gpio_if.h"

typedef struct spi_if_t spi_if_t;

// return 0 indicates success
typedef int (*spi_tx_fn)(spi_if_t* spi_if,const uint8_t* data,uint16_t len);
typedef int (*spi_rx_fn)(spi_if_t* spi_if,uint8_t* data,uint16_t len);
typedef int (*spi_tx_rx_fn)(spi_if_t* spi_if,const uint8_t* tx_data,uint16_t tx_len,
		uint8_t* rx_data,uint16_t rx_len);

struct spi_if_t {
    spi_tx_fn tx;
    spi_rx_fn rx;
    spi_tx_rx_fn tx_rx;
    void* ctx;
};

#endif /* SPI_F_H */
