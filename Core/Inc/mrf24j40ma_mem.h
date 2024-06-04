// Automatically generated file. DO NOT EDIT.

#include <mrf24j40ma_long_regs.h>
#include <mrf24j40ma_short_regs.h>

typedef struct{
	uint8_t val;
} REG_t;

typedef union{
    struct{
        RXMCR_t                             RXMCR ; // 0x00
        REG_t                            PANIDL ; // 0x01
        REG_t                            PANIDH ; // 0x02
        REG_t                             SADRL ; // 0x03
        REG_t                             SADRH ; // 0x04
        REG_t                             EADR0 ; // 0x05
        REG_t                             EADR1 ; // 0x06
        REG_t                             EADR2 ; // 0x07
        REG_t                             EADR3 ; // 0x08
        REG_t                             EADR4 ; // 0x09
        REG_t                             EADR5 ; // 0x0A
        REG_t                             EADR6 ; // 0x0B
        REG_t                             EADR7 ; // 0x0C
        RXFLUSH_t                         RXFLUSH ; // 0x0D
        REG_t                                R0 ; // 0x0E
        REG_t                                R1 ; // 0x0F
        ORDER_t                             ORDER ; // 0x10
        TXMCR_t                             TXMCR ; // 0x11
        ACKTMOUT_t                       ACKTMOUT ; // 0x12
        ESLOTG1_t                         ESLOTG1 ; // 0x13
        SYMTICKL_t                       SYMTICKL ; // 0x14
        SYMTICKH_t                       SYMTICKH ; // 0x15
        PACON0_t                           PACON0 ; // 0x16
        PACON1_t                           PACON1 ; // 0x17
        PACON2_t                           PACON2 ; // 0x18
        REG_t                                R2 ; // 0x19
        TXBCON0_t                         TXBCON0 ; // 0x1A
        TXNCON_t                           TXNCON ; // 0x1B
        TXG1CON_t                         TXG1CON ; // 0x1C
        TXG2CON_t                         TXG2CON ; // 0x1D
        ESLOTG23_t                       ESLOTG23 ; // 0x1E
        ESLOTG45_t                       ESLOTG45 ; // 0x1F
        ESLOTG67_t                       ESLOTG67 ; // 0x20
        TXPEND_t                           TXPEND ; // 0x21
        WAKECON_t                         WAKECON ; // 0x22
        FRMOFFSET_t                     FRMOFFSET ; // 0x23
        TXSTAT_t                           TXSTAT ; // 0x24
        TXBCON1_t                         TXBCON1 ; // 0x25
        GATECLK_t                         GATECLK ; // 0x26
        TXTIME_t                           TXTIME ; // 0x27
        HSYMTMRL_t                       HSYMTMRL ; // 0x28
        HSYMTMRH_t                       HSYMTMRH ; // 0x29
        SOFTRST_t                         SOFTRST ; // 0x2A
        REG_t                                R3 ; // 0x2B
        SECCON0_t                         SECCON0 ; // 0x2C
        SECCON1_t                         SECCON1 ; // 0x2D
        TXSTBL_t                           TXSTBL ; // 0x2E
        REG_t                                R4 ; // 0x2F
        RXSR_t                               RXSR ; // 0x30
        INTSTAT_t                         INTSTAT ; // 0x31
        INTCON_t                           INTCON ; // 0x32
        GPIO_t                               GPIO ; // 0x33
        TRISGPIO_t                       TRISGPIO ; // 0x34
        SLPACK_t                           SLPACK ; // 0x35
        RFCTL_t                             RFCTL ; // 0x36
        SECCR2_t                           SECCR2 ; // 0x37
        BBREG0_t                           BBREG0 ; // 0x38
        BBREG1_t                           BBREG1 ; // 0x39
        BBREG2_t                           BBREG2 ; // 0x3A
        BBREG3_t                           BBREG3 ; // 0x3B
        BBREG4_t                           BBREG4 ; // 0x3C
        REG_t                                R5 ; // 0x3D
        BBREG6_t                           BBREG6 ; // 0x3E
        CCAEDTH_t                         CCAEDTH ; // 0x3F
    }r;
    uint8_t regs[64];
} mrf24j0ma_short_control_regs_t;

typedef union{
    struct{
        RFCON0_t                           RFCON0 ; // 0x200
        RFCON1_t                           RFCON1 ; // 0x201
        RFCON2_t                           RFCON2 ; // 0x202
        RFCON3_t                           RFCON3 ; // 0x203
        REG_t                                R6 ; // 0x204
        RFCON5_t                           RFCON5 ; // 0x205
        RFCON6_t                           RFCON6 ; // 0x206
        RFCON7_t                           RFCON7 ; // 0x207
        RFCON8_t                           RFCON8 ; // 0x208
        SLPCAL0_t                         SLPCAL0 ; // 0x209
        SLPCAL1_t                         SLPCAL1 ; // 0x20A
        SLPCAL2_t                         SLPCAL2 ; // 0x20B
        REG_t                                R7 ; // 0x20C
        REG_t                                R8 ; // 0x20D
        REG_t                                R9 ; // 0x20E
        RFSTATE_t                         RFSTATE ; // 0x20F
        RSSI_t                               RSSI ; // 0x210
        SLPCON0_t                         SLPCON0 ; // 0x211
        REG_t                               R10 ; // 0x212
        REG_t                               R11 ; // 0x213
        REG_t                               R12 ; // 0x214
        REG_t                               R13 ; // 0x215
        REG_t                               R14 ; // 0x216
        REG_t                               R15 ; // 0x217
        REG_t                               R16 ; // 0x218
        REG_t                               R17 ; // 0x219
        REG_t                               R18 ; // 0x21A
        REG_t                               R19 ; // 0x21B
        REG_t                               R20 ; // 0x21C
        REG_t                               R21 ; // 0x21D
        REG_t                               R22 ; // 0x21E
        REG_t                               R23 ; // 0x21F
        SLPCON1_t                         SLPCON1 ; // 0x220
        REG_t                               R24 ; // 0x221
        WAKETIMEL_t                     WAKETIMEL ; // 0x222
        WAKETIMEH_t                     WAKETIMEH ; // 0x223
        REMCNTL_t                         REMCNTL ; // 0x224
        REMCNTH_t                         REMCNTH ; // 0x225
        MAINCNT0_t                       MAINCNT0 ; // 0x226
        MAINCNT1_t                       MAINCNT1 ; // 0x227
        MAINCNT2_t                       MAINCNT2 ; // 0x228
        MAINCNT3_t                       MAINCNT3 ; // 0x229
        REG_t                               R25 ; // 0x22A
        REG_t                               R26 ; // 0x22B
        REG_t                               R27 ; // 0x22C
        REG_t                               R28 ; // 0x22D
        REG_t                               R29 ; // 0x22E
        TESTMODE_t                       TESTMODE ; // 0x22F
        REG_t                         ASSOEADR0 ; // 0x230
        REG_t                         ASSOEADR1 ; // 0x231
        REG_t                         ASSOEADR2 ; // 0x232
        REG_t                         ASSOEADR3 ; // 0x233
        REG_t                         ASSOEADR4 ; // 0x234
        REG_t                         ASSOEADR5 ; // 0x235
        REG_t                         ASSOEADR6 ; // 0x236
        REG_t                         ASSOEADR7 ; // 0x237
        REG_t                         ASSOSADR0 ; // 0x238
        REG_t                         ASSOSADR1 ; // 0x239
        REG_t                               R30 ; // 0x23A
        REG_t                               R31 ; // 0x23B
        REG_t                               R32 ; // 0x23C
        REG_t                               R33 ; // 0x23D
        REG_t                               R34 ; // 0x23E
        REG_t                               R35 ; // 0x23F
        REG_t                          UPNONCE0 ; // 0x240
        REG_t                          UPNONCE1 ; // 0x241
        REG_t                          UPNONCE2 ; // 0x242
        REG_t                          UPNONCE3 ; // 0x243
        REG_t                          UPNONCE4 ; // 0x244
        REG_t                          UPNONCE5 ; // 0x245
        REG_t                          UPNONCE6 ; // 0x246
        REG_t                          UPNONCE7 ; // 0x247
        REG_t                          UPNONCE8 ; // 0x248
        REG_t                          UPNONCE9 ; // 0x249
        REG_t                         UPNONCE10 ; // 0x24A
        REG_t                         UPNONCE11 ; // 0x24B
        REG_t                         UPNONCE12 ; // 0x24C
    }r;
    uint8_t regs[77];
} mrf24j0ma_long_control_regs_t;

#define S_ADDR(REG)\
(uintptr_t)(&(((mrf24j0ma_short_control_regs_t*)0)->r.REG))

#define L_ADDR(REG)\
((uintptr_t)(&(((mrf24j0ma_long_control_regs_t*)0)->r.REG)) + 0x200)

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
    	uint8_t _CR[128];
        mrf24j0ma_long_control_regs_t LCR;
    };
    
    // Security FIFO
    uint8_t sec_fifo[64];
    // reserved
    uint8_t reserved[64];
    // RX FIFO 
    uint8_t data[144];
} mrf24j0ma_LA_space_t;
