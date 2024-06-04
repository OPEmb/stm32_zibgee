#ifndef MRF24J0MA_ADDRESS_SPACE_H
#define MRF24J0MA_ADDRESS_SPACE_H

#include "mrf24j40ma_long_regs.h"
#include "mrf24j40ma_short_regs.h"

// Long Address Memory Space 
typedef struct{
    // TX NORMAL FIFO
    uint8_t tx_norm_fifo[128];
    // TX BEACON FIFO
    uint8_t tx_beac_fifo[128];
    // TX GTS1 FIFO
    uint8_t tx_gts1_fifo[128];
    // TX GTS2 FIFO
    uint8_t tx_gts2_fifo[128];

    // Control registers
    union{
        uint8_t _LCR[128];
        mrf24j40ma_long_control_regs_t LCR;
    };
    
    // Security FIFO
    uint8_t sec_fifo[64];
    // reserved
    uint8_t reserved[64];
    // RX FIFO 
    uint8_t rx_fifo[144];
} mrf24j40ma_long_address_space_t;

// Short Adress Memory Space is just the short register definitions

#endif /* MRF24J0MA_ADDRESS_SPACE_H */