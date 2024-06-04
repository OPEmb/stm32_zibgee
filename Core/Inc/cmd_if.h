#ifndef CMD_IF
#define CMD_IF

#include <stdint.h>

typedef enum{
    CMD_ID_SPI_TX,         // do SPI TX with given payload
    CMD_ID_SPI_RX,         // read RX amount of bytes
    CMD_ID_INTERRUPT,      // interrupt occured, payload has more info
    CMD_ID_INTERRUPT_CTRL, // interrupt control
} cmd_id_t;

typedef union __attribute__((packed)){
    uint8_t id;
    struct{
        uint16_t len;
    } spi_rx,spi_tx;
    struct{
        uint16_t line;
    } I,I_CTRL; 
    // for CMD_ID_INTERRUPT, line represents which interrupt occured
    // for CMD_ID_INTERRUPT_CTRL, line represents mask of enable/disable interrupt
} cmd_t; 

#endif /* CMD_IF */