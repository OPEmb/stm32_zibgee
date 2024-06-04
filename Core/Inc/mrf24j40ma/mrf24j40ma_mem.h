// Automatically generated file. DO NOT EDIT.

#ifndef MRF24J40MA_MEM_H
#define MRF24J40MA_MEM_H

#include "mrf24j40ma_short_regs.h"
#include "mrf24j40ma_long_regs.h"

typedef struct{
    uint8_t val;
}REG__t; // a hack for the macro to work, generic 8 bit register, important it has val as member

typedef union{
    struct{
        RXMCR_t                             RXMCR ; // 0x00
        REG__t                            PANIDL ; // 0x01
        REG__t                            PANIDH ; // 0x02
        REG__t                             SADRL ; // 0x03
        REG__t                             SADRH ; // 0x04
        REG__t                             EADR0 ; // 0x05
        REG__t                             EADR1 ; // 0x06
        REG__t                             EADR2 ; // 0x07
        REG__t                             EADR3 ; // 0x08
        REG__t                             EADR4 ; // 0x09
        REG__t                             EADR5 ; // 0x0A
        REG__t                             EADR6 ; // 0x0B
        REG__t                             EADR7 ; // 0x0C
        RXFLUSH_t                         RXFLUSH ; // 0x0D
        REG__t                                R0 ; // 0x0E
        REG__t                                R1 ; // 0x0F
        ORDER_t                             ORDER ; // 0x10
        TXMCR_t                             TXMCR ; // 0x11
        ACKTMOUT_t                       ACKTMOUT ; // 0x12
        ESLOTG1_t                         ESLOTG1 ; // 0x13
        SYMTICKL_t                       SYMTICKL ; // 0x14
        SYMTICKH_t                       SYMTICKH ; // 0x15
        PACON0_t                           PACON0 ; // 0x16
        PACON1_t                           PACON1 ; // 0x17
        PACON2_t                           PACON2 ; // 0x18
        REG__t                                R2 ; // 0x19
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
        REG__t                                R3 ; // 0x2B
        SECCON0_t                         SECCON0 ; // 0x2C
        SECCON1_t                         SECCON1 ; // 0x2D
        TXSTBL_t                           TXSTBL ; // 0x2E
        REG__t                                R4 ; // 0x2F
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
        REG__t                                R5 ; // 0x3D
        BBREG6_t                           BBREG6 ; // 0x3E
        CCAEDTH_t                         CCAEDTH ; // 0x3F
    }r;
    uint8_t regs[64];
} mrf24j40ma_short_control_regs_t;

typedef union{
    struct{
        RFCON0_t                           RFCON0 ; // 0x200
        RFCON1_t                           RFCON1 ; // 0x201
        RFCON2_t                           RFCON2 ; // 0x202
        RFCON3_t                           RFCON3 ; // 0x203
        REG__t                                R6 ; // 0x204
        RFCON5_t                           RFCON5 ; // 0x205
        RFCON6_t                           RFCON6 ; // 0x206
        RFCON7_t                           RFCON7 ; // 0x207
        RFCON8_t                           RFCON8 ; // 0x208
        SLPCAL0_t                         SLPCAL0 ; // 0x209
        SLPCAL1_t                         SLPCAL1 ; // 0x20A
        SLPCAL2_t                         SLPCAL2 ; // 0x20B
        REG__t                                R7 ; // 0x20C
        REG__t                                R8 ; // 0x20D
        REG__t                                R9 ; // 0x20E
        RFSTATE_t                         RFSTATE ; // 0x20F
        RSSI_t                               RSSI ; // 0x210
        SLPCON0_t                         SLPCON0 ; // 0x211
        REG__t                               R10 ; // 0x212
        REG__t                               R11 ; // 0x213
        REG__t                               R12 ; // 0x214
        REG__t                               R13 ; // 0x215
        REG__t                               R14 ; // 0x216
        REG__t                               R15 ; // 0x217
        REG__t                               R16 ; // 0x218
        REG__t                               R17 ; // 0x219
        REG__t                               R18 ; // 0x21A
        REG__t                               R19 ; // 0x21B
        REG__t                               R20 ; // 0x21C
        REG__t                               R21 ; // 0x21D
        REG__t                               R22 ; // 0x21E
        REG__t                               R23 ; // 0x21F
        SLPCON1_t                         SLPCON1 ; // 0x220
        REG__t                               R24 ; // 0x221
        WAKETIMEL_t                     WAKETIMEL ; // 0x222
        WAKETIMEH_t                     WAKETIMEH ; // 0x223
        REMCNTL_t                         REMCNTL ; // 0x224
        REMCNTH_t                         REMCNTH ; // 0x225
        MAINCNT0_t                       MAINCNT0 ; // 0x226
        MAINCNT1_t                       MAINCNT1 ; // 0x227
        MAINCNT2_t                       MAINCNT2 ; // 0x228
        MAINCNT3_t                       MAINCNT3 ; // 0x229
        REG__t                               R25 ; // 0x22A
        REG__t                               R26 ; // 0x22B
        REG__t                               R27 ; // 0x22C
        REG__t                               R28 ; // 0x22D
        REG__t                               R29 ; // 0x22E
        TESTMODE_t                       TESTMODE ; // 0x22F
        REG__t                          ASSOEADR0 ; // 0x230
        REG__t                          ASSOEADR1 ; // 0x231
        REG__t                          ASSOEADR2 ; // 0x232
        REG__t                          ASSOEADR3 ; // 0x233
        REG__t                          ASSOEADR4 ; // 0x234
        REG__t                          ASSOEADR5 ; // 0x235
        REG__t                          ASSOEADR6 ; // 0x236
        REG__t                          ASSOEADR7 ; // 0x237
        REG__t                          ASSOSADR0 ; // 0x238
        REG__t                          ASSOSADR1 ; // 0x239
        REG__t                                R30 ; // 0x23A
        REG__t                                R31 ; // 0x23B
        REG__t                                R32 ; // 0x23C
        REG__t                                R33 ; // 0x23D
        REG__t                                R34 ; // 0x23E
        REG__t                                R35 ; // 0x23F
        REG__t                           UPNONCE0 ; // 0x240
        REG__t                           UPNONCE1 ; // 0x241
        REG__t                           UPNONCE2 ; // 0x242
        REG__t                           UPNONCE3 ; // 0x243
        REG__t                           UPNONCE4 ; // 0x244
        REG__t                           UPNONCE5 ; // 0x245
        REG__t                           UPNONCE6 ; // 0x246
        REG__t                           UPNONCE7 ; // 0x247
        REG__t                           UPNONCE8 ; // 0x248
        REG__t                           UPNONCE9 ; // 0x249
        REG__t                          UPNONCE10 ; // 0x24A
        REG__t                          UPNONCE11 ; // 0x24B
        REG__t                          UPNONCE12 ; // 0x24C
    }r;
    uint8_t regs[77];
} mrf24j40ma_long_control_regs_t;

#endif /* MRF24J40MA_MEM_H */