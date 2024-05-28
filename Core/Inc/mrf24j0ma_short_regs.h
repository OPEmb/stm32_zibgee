// Automatically generated file. DO NOT EDIT.

#include <stdint.h>


// 0x00
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t NOACKRSP   :1;
      uint8_t            :1;
      uint8_t PANCOORD   :1;
      uint8_t COORD      :1;
      uint8_t ERRPKT     :1;
      uint8_t PROMI      :1;
    };
    uint8_t val;
} RXMCR_t;

// 0x0D
typedef union{
    struct{
      uint8_t            :1;
      uint8_t WAKEPOL    :1;
      uint8_t WAKEPAD    :1;
      uint8_t            :1;
      uint8_t CMDONLY    :1;
      uint8_t DATAONLY   :1;
      uint8_t BCNONLY    :1;
      uint8_t RXFLUSH    :1;
    };
    uint8_t val;
} RXFLUSH_t;

// 0x10
typedef union{
    struct{
      uint8_t BO3        :1;
      uint8_t BO2        :1;
      uint8_t BO1        :1;
      uint8_t BO0        :1;
      uint8_t SO3        :1;
      uint8_t SO2        :1;
      uint8_t SO1        :1;
      uint8_t SO0        :1;
    };
    uint8_t val;
} ORDER_t;

// 0x11
typedef union{
    struct{
      uint8_t NOCSMA     :1;
      uint8_t BATLIFEXT  :1;
      uint8_t SLOTTED    :1;
      uint8_t MACMINBE1  :1;
      uint8_t MACMINBE0  :1;
      uint8_t CSMABF2    :1;
      uint8_t CSMABF1    :1;
      uint8_t CSMABF0    :1;
    };
    uint8_t val;
} TXMCR_t;

// 0x12
typedef union{
    struct{
      uint8_t DRPACK     :1;
      uint8_t MAWD6      :1;
      uint8_t MAWD5      :1;
      uint8_t MAWD4      :1;
      uint8_t MAWD3      :1;
      uint8_t MAWD2      :1;
      uint8_t MAWD1      :1;
      uint8_t MAWD0      :1;
    };
    uint8_t val;
} ACKTMOUT_t;

// 0x13
typedef union{
    struct{
      uint8_t GTS1_3     :1;
      uint8_t GTS1_2     :1;
      uint8_t GTS1_1     :1;
      uint8_t GTS1_0     :1;
      uint8_t CAP3       :1;
      uint8_t CAP2       :1;
      uint8_t CAP1       :1;
      uint8_t CAP0       :1;
    };
    uint8_t val;
} ESLOTG1_t;

// 0x14
typedef union{
    struct{
      uint8_t TICKP7     :1;
      uint8_t TICKP6     :1;
      uint8_t TICKP5     :1;
      uint8_t TICKP4     :1;
      uint8_t TICKP3     :1;
      uint8_t TICKP2     :1;
      uint8_t TICKP1     :1;
      uint8_t TICKP0     :1;
    };
    uint8_t val;
} SYMTICKL_t;

// 0x15
typedef union{
    struct{
      uint8_t TXONT6     :1;
      uint8_t TXONT5     :1;
      uint8_t TXONT4     :1;
      uint8_t TXONT3     :1;
      uint8_t TXONT2     :1;
      uint8_t TXONT1     :1;
      uint8_t TXONT0     :1;
      uint8_t TICKP8     :1;
    };
    uint8_t val;
} SYMTICKH_t;

// 0x16
typedef union{
    struct{
      uint8_t PAONT7     :1;
      uint8_t PAONT6     :1;
      uint8_t PAONT5     :1;
      uint8_t PAONT4     :1;
      uint8_t PAONT3     :1;
      uint8_t PAONT2     :1;
      uint8_t PAONT1     :1;
      uint8_t PAONT0     :1;
    };
    uint8_t val;
} PACON0_t;

// 0x17
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t PAONTS3    :1;
      uint8_t PAONTS2    :1;
      uint8_t PAONTS1    :1;
      uint8_t PAONTS0    :1;
      uint8_t PAONT8     :1;
    };
    uint8_t val;
} PACON1_t;

// 0x18
typedef union{
    struct{
      uint8_t FIFOEN     :1;
      uint8_t            :1;
      uint8_t TXONTS3    :1;
      uint8_t TXONTS2    :1;
      uint8_t TXONTS1    :1;
      uint8_t TXONTS0    :1;
      uint8_t TXONT8     :1;
      uint8_t TXONT7     :1;
    };
    uint8_t val;
} PACON2_t;

// 0x1A
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t TXBSECEN   :1;
      uint8_t TXBTRIG    :1;
    };
    uint8_t val;
} TXBCON0_t;

// 0x1B
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t FPSTAT     :1;
      uint8_t INDIRECT   :1;
      uint8_t TXNACKREQ  :1;
      uint8_t TXNSECEN   :1;
      uint8_t TXNTRIG    :1;
    };
    uint8_t val;
} TXNCON_t;

// 0x1C
typedef union{
    struct{
      uint8_t TXG1RETRY1 :1;
      uint8_t TXG1RETRY0 :1;
      uint8_t TXG1SLOT2  :1;
      uint8_t TXG1SLOT1  :1;
      uint8_t TXG1SLOT0  :1;
      uint8_t TXG1ACKREQ :1;
      uint8_t TXG1SECEN  :1;
      uint8_t TXG1TRIG   :1;
    };
    uint8_t val;
} TXG1CON_t;

// 0x1D
typedef union{
    struct{
      uint8_t TXG2RETRY1 :1;
      uint8_t TXG2RETRY0 :1;
      uint8_t TXG2SLOT2  :1;
      uint8_t TXG2SLOT1  :1;
      uint8_t TXG2SLOT0  :1;
      uint8_t TXG2ACKREQ :1;
      uint8_t TXG2SECEN  :1;
      uint8_t TXG2TRIG   :1;
    };
    uint8_t val;
} TXG2CON_t;

// 0x1E
typedef union{
    struct{
      uint8_t GTS3_3     :1;
      uint8_t GTS3_2     :1;
      uint8_t GTS3_1     :1;
      uint8_t GTS3_0     :1;
      uint8_t GTS2_3     :1;
      uint8_t GTS2_2     :1;
      uint8_t GTS2_1     :1;
      uint8_t GTS2_0     :1;
    };
    uint8_t val;
} ESLOTG23_t;

// 0x1F
typedef union{
    struct{
      uint8_t GTS5_3     :1;
      uint8_t GTS5_2     :1;
      uint8_t GTS5_1     :1;
      uint8_t GTS5_0     :1;
      uint8_t GTS4_3     :1;
      uint8_t GTS4_2     :1;
      uint8_t GTS4_1     :1;
      uint8_t GTS4_0     :1;
    };
    uint8_t val;
} ESLOTG45_t;

// 0x20
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t GTS6_3     :1;
      uint8_t GTS6_2     :1;
      uint8_t GTS6_1     :1;
      uint8_t GTS6_0     :1;
    };
    uint8_t val;
} ESLOTG67_t;

// 0x21
typedef union{
    struct{
      uint8_t MLIFS5     :1;
      uint8_t MLIFS4     :1;
      uint8_t MLIFS3     :1;
      uint8_t MLIFS2     :1;
      uint8_t MLIFS1     :1;
      uint8_t MLIFS0     :1;
      uint8_t GTSSWITCH  :1;
      uint8_t FPACK      :1;
    };
    uint8_t val;
} TXPEND_t;

// 0x22
typedef union{
    struct{
      uint8_t IMMWAKE    :1;
      uint8_t REGWAKE    :1;
      uint8_t INTL5      :1;
      uint8_t INTL4      :1;
      uint8_t INTL3      :1;
      uint8_t INTL2      :1;
      uint8_t INTL1      :1;
      uint8_t INTL0      :1;
    };
    uint8_t val;
} WAKECON_t;

// 0x23
typedef union{
    struct{
      uint8_t OFFSET7    :1;
      uint8_t OFFSET6    :1;
      uint8_t OFFSET5    :1;
      uint8_t OFFSET4    :1;
      uint8_t OFFSET3    :1;
      uint8_t OFFSET2    :1;
      uint8_t OFFSET1    :1;
      uint8_t OFFSET0    :1;
    };
    uint8_t val;
} FRMOFFSET_t;

// 0x24
typedef union{
    struct{
      uint8_t TXNRETRY1  :1;
      uint8_t TXNRETRY0  :1;
      uint8_t CCAFAIL    :1;
      uint8_t TXG2FNT    :1;
      uint8_t TXG1FNT    :1;
      uint8_t TXG2STAT   :1;
      uint8_t TXG1STAT   :1;
      uint8_t TXNSTAT    :1;
    };
    uint8_t val;
} TXSTAT_t;

// 0x25
typedef union{
    struct{
      uint8_t TXBMSK     :1;
      uint8_t WU_BCN     :1;
      uint8_t RSSINUM1   :1;
      uint8_t RSSINUM0   :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} TXBCON1_t;

// 0x26
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t GTSON      :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} GATECLK_t;

// 0x27
typedef union{
    struct{
      uint8_t TURNTIME3  :1;
      uint8_t TURNTIME2  :1;
      uint8_t TURNTIME1  :1;
      uint8_t TURNTIME0  :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} TXTIME_t;

// 0x28
typedef union{
    struct{
      uint8_t HSYMTMR7   :1;
      uint8_t HSYMTMR6   :1;
      uint8_t HSYMTMR5   :1;
      uint8_t HSYMTMR4   :1;
      uint8_t HSYMTMR3   :1;
      uint8_t HSYMTMR2   :1;
      uint8_t HSYMTMR1   :1;
      uint8_t HSYMTMR0   :1;
    };
    uint8_t val;
} HSYMTMRL_t;

// 0x29
typedef union{
    struct{
      uint8_t HSYMTMR15  :1;
      uint8_t HSYMTMR14  :1;
      uint8_t HSYMTMR13  :1;
      uint8_t HSYMTMR12  :1;
      uint8_t HSYMTMR11  :1;
      uint8_t HSYMTMR10  :1;
      uint8_t HSYMTMR09  :1;
      uint8_t HSYMTMR08  :1;
    };
    uint8_t val;
} HSYMTMRH_t;

// 0x2A
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t RSTPWR     :1;
      uint8_t RSTBB      :1;
      uint8_t RSTMAC     :1;
    };
    uint8_t val;
} SOFTRST_t;

// 0x2C
typedef union{
    struct{
      uint8_t SECIGNORE  :1;
      uint8_t SECSTART   :1;
      uint8_t RXCIPHER2  :1;
      uint8_t RXCIPHER1  :1;
      uint8_t RXCIPHER0  :1;
      uint8_t TXNCIPHER2 :1;
      uint8_t TXNCIPHER1 :1;
      uint8_t TXNCIPHER0 :1;
    };
    uint8_t val;
} SECCON0_t;

// 0x2D
typedef union{
    struct{
      uint8_t            :1;
      uint8_t TXBCIPHER2 :1;
      uint8_t TXBCIPHER1 :1;
      uint8_t TXBCIPHER0 :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t DISDEC     :1;
      uint8_t DISENC     :1;
    };
    uint8_t val;
} SECCON1_t;

// 0x2E
typedef union{
    struct{
      uint8_t RFSTBL3    :1;
      uint8_t RFSTBL2    :1;
      uint8_t RFSTBL1    :1;
      uint8_t RFSTBL0    :1;
      uint8_t MSIFS3     :1;
      uint8_t MSIFS2     :1;
      uint8_t MSIFS1     :1;
      uint8_t MSIFS0     :1;
    };
    uint8_t val;
} TXSTBL_t;

// 0x30
typedef union{
    struct{
      uint8_t            :1;
      uint8_t UPSECERR   :1;
      uint8_t BATIND     :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t SECDECERR  :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} RXSR_t;

// 0x31
typedef union{
    struct{
      uint8_t SLPIF      :1;
      uint8_t WAKEIF     :1;
      uint8_t HSYMTMRIF  :1;
      uint8_t SECIF      :1;
      uint8_t RXIF       :1;
      uint8_t TXG2IF     :1;
      uint8_t TXG1IF     :1;
      uint8_t TXNIF      :1;
    };
    uint8_t val;
} INTSTAT_t;

// 0x32
typedef union{
    struct{
      uint8_t SLPIE      :1;
      uint8_t WAKEIE     :1;
      uint8_t HSYMTMRIE  :1;
      uint8_t SECIE      :1;
      uint8_t RXIE       :1;
      uint8_t TXG2IE     :1;
      uint8_t TXG1IE     :1;
      uint8_t TXNIE      :1;
    };
    uint8_t val;
} INTCON_t;

// 0x33
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t GPIO5      :1;
      uint8_t GPIO4      :1;
      uint8_t GPIO3      :1;
      uint8_t GPIO2      :1;
      uint8_t GPIO1      :1;
      uint8_t GPIO0      :1;
    };
    uint8_t val;
} GPIO_t;

// 0x34
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t TRISGP5    :1;
      uint8_t TRISGP4    :1;
      uint8_t TRISGP3    :1;
      uint8_t TRISGP2    :1;
      uint8_t TRISGP1    :1;
      uint8_t TRISGP0    :1;
    };
    uint8_t val;
} TRISGPIO_t;

// 0x35
typedef union{
    struct{
      uint8_t SLPACK     :1;
      uint8_t WAKECNT6   :1;
      uint8_t WAKECNT5   :1;
      uint8_t WAKECNT4   :1;
      uint8_t WAKECNT3   :1;
      uint8_t WAKECNT2   :1;
      uint8_t WAKECNT1   :1;
      uint8_t WAKECNT0   :1;
    };
    uint8_t val;
} SLPACK_t;

// 0x36
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t WAKECNT8   :1;
      uint8_t WAKECNT7   :1;
      uint8_t RFRST      :1;
      uint8_t RFTXMODE   :1;
      uint8_t RFRXMODE   :1;
    };
    uint8_t val;
} RFCTL_t;

// 0x37
typedef union{
    struct{
      uint8_t UPDEC      :1;
      uint8_t UPENC      :1;
      uint8_t TXG2CIPHER2 :1;
      uint8_t TXG2CIPHER1 :1;
      uint8_t TXG2CIPHER0 :1;
      uint8_t TXG1CIPHER2 :1;
      uint8_t TXG1CIPHER1 :1;
      uint8_t TXG1CIPHER0 :1;
    };
    uint8_t val;
} SECCR2_t;

// 0x38
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t TURBO      :1;
    };
    uint8_t val;
} BBREG0_t;

// 0x39
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t RXDECINV   :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} BBREG1_t;

// 0x3A
typedef union{
    struct{
      uint8_t CCAMODE1   :1;
      uint8_t CCAMODE0   :1;
      uint8_t CCACSTH3   :1;
      uint8_t CCACSTH2   :1;
      uint8_t CCACSTH1   :1;
      uint8_t CCACSTH0   :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} BBREG2_t;

// 0x3B
typedef union{
    struct{
      uint8_t PREVALIDTH3 :1;
      uint8_t PREVALIDTH2 :1;
      uint8_t PREVALIDTH1 :1;
      uint8_t PREVALIDTH0 :1;
      uint8_t PREDETTH2  :1;
      uint8_t PREDETTH1  :1;
      uint8_t PREDETTH0  :1;
      uint8_t            :1;
    };
    uint8_t val;
} BBREG3_t;

// 0x3C
typedef union{
    struct{
      uint8_t CSTH2      :1;
      uint8_t CSTH1      :1;
      uint8_t CSTH0      :1;
      uint8_t PRECNT2    :1;
      uint8_t PRECNT1    :1;
      uint8_t PRECNT0    :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} BBREG4_t;

// 0x3E
typedef union{
    struct{
      uint8_t RSSIMODE1  :1;
      uint8_t RSSIMODE2  :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t RSSIRDY    :1;
    };
    uint8_t val;
} BBREG6_t;

// 0x3F
typedef union{
    struct{
      uint8_t CCAEDTH7   :1;
      uint8_t CCAEDTH6   :1;
      uint8_t CCAEDTH5   :1;
      uint8_t CCAEDTH4   :1;
      uint8_t CCAEDTH3   :1;
      uint8_t CCAEDTH2   :1;
      uint8_t CCAEDTH1   :1;
      uint8_t CCAEDTH0   :1;
    };
    uint8_t val;
} CCAEDTH_t;
