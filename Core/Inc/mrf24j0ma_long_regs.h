// Automatically generated file. DO NOT EDIT.

#include <stdint.h>


// 0x200
typedef union{
    struct{
      uint8_t CHANNEL3   :1;
      uint8_t CHANNEL2   :1;
      uint8_t CHANNEL1   :1;
      uint8_t CHANNEL0   :1;
      uint8_t RFOPT3     :1;
      uint8_t RFOPT2     :1;
      uint8_t RFOPT1     :1;
      uint8_t RFOPT0     :1;
    };
    uint8_t val;
} RFCON0_t;

// 0x201
typedef union{
    struct{
      uint8_t VCOOPT7    :1;
      uint8_t VCOOPT6    :1;
      uint8_t VCOOPT5    :1;
      uint8_t VCOOPT4    :1;
      uint8_t VCOOPT3    :1;
      uint8_t VCOOPT2    :1;
      uint8_t VCOOPT1    :1;
      uint8_t VCOOPT0    :1;
    };
    uint8_t val;
} RFCON1_t;

// 0x202
typedef union{
    struct{
      uint8_t PLLEN      :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} RFCON2_t;

// 0x203
typedef union{
    struct{
      uint8_t TXPWRL1    :1;
      uint8_t TXPWRL0    :1;
      uint8_t TXPWRS2    :1;
      uint8_t TXPWRS1    :1;
      uint8_t TXPWRS0    :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} RFCON3_t;

// 0x205
typedef union{
    struct{
      uint8_t BATTH3     :1;
      uint8_t BATTH2     :1;
      uint8_t BATTH1     :1;
      uint8_t BATTH0     :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} RFCON5_t;

// 0x206
typedef union{
    struct{
      uint8_t TXFIL      :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t _20MRECVR  :1;
      uint8_t BATEN      :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} RFCON6_t;

// 0x207
typedef union{
    struct{
      uint8_t SLPCLKSEL1 :1;
      uint8_t SLPCLKSEL0 :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t CLKOUTMODE1 :1;
      uint8_t CLKOUTMODE0 :1;
    };
    uint8_t val;
} RFCON7_t;

// 0x208
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t RFVCO      :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} RFCON8_t;

// 0x209
typedef union{
    struct{
      uint8_t SLPCAL7    :1;
      uint8_t SLPCAL6    :1;
      uint8_t SLPCAL5    :1;
      uint8_t SLPCAL4    :1;
      uint8_t SLPCAL3    :1;
      uint8_t SLPCAL2    :1;
      uint8_t SLPCAL1    :1;
      uint8_t SLPCAL0    :1;
    };
    uint8_t val;
} SLPCAL0_t;

// 0x20A
typedef union{
    struct{
      uint8_t SLPCAL15   :1;
      uint8_t SLPCAL14   :1;
      uint8_t SLPCAL13   :1;
      uint8_t SLPCAL12   :1;
      uint8_t SLPCAL11   :1;
      uint8_t SLPCAL10   :1;
      uint8_t SLPCAL9    :1;
      uint8_t SLPCAL8    :1;
    };
    uint8_t val;
} SLPCAL1_t;

// 0x20B
typedef union{
    struct{
      uint8_t SLPCALRDY  :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t SLPCALEN   :1;
      uint8_t SLPCAL19   :1;
      uint8_t SLPCAL18   :1;
      uint8_t SLPCAL17   :1;
      uint8_t SLPCAL16   :1;
    };
    uint8_t val;
} SLPCAL2_t;

// 0x20F
typedef union{
    struct{
      uint8_t RFSTATE2   :1;
      uint8_t RFSTATE1   :1;
      uint8_t RFSTATE0   :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
    };
    uint8_t val;
} RFSTATE_t;

// 0x210
typedef union{
    struct{
      uint8_t RSSI7      :1;
      uint8_t RSSI6      :1;
      uint8_t RSSI5      :1;
      uint8_t RSSI4      :1;
      uint8_t RSSI3      :1;
      uint8_t RSSI2      :1;
      uint8_t RSSI1      :1;
      uint8_t RSSI0      :1;
    };
    uint8_t val;
} RSSI_t;

// 0x211
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t INTEDGE    :1;
      uint8_t SLPCLKEN   :1;
    };
    uint8_t val;
} SLPCON0_t;

// 0x220
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t CLKOUTEN   :1;
      uint8_t SLPCLKDIV4 :1;
      uint8_t SLPCLKDIV3 :1;
      uint8_t SLPCLKDIV2 :1;
      uint8_t SLPCLKDIV1 :1;
      uint8_t SLPCLKDIV0 :1;
    };
    uint8_t val;
} SLPCON1_t;

// 0x222
typedef union{
    struct{
      uint8_t WAKETIME7  :1;
      uint8_t WAKETIME6  :1;
      uint8_t WAKETIME5  :1;
      uint8_t WAKETIME4  :1;
      uint8_t WAKETIME3  :1;
      uint8_t WAKETIME2  :1;
      uint8_t WAKETIME1  :1;
      uint8_t WAKETIME0  :1;
    };
    uint8_t val;
} WAKETIMEL_t;

// 0x223
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t WAKETIME10 :1;
      uint8_t WAKETIME9  :1;
      uint8_t WAKETIME8  :1;
    };
    uint8_t val;
} WAKETIMEH_t;

// 0x224
typedef union{
    struct{
      uint8_t REMCNT7    :1;
      uint8_t REMCNT6    :1;
      uint8_t REMCNT5    :1;
      uint8_t REMCNT4    :1;
      uint8_t REMCNT3    :1;
      uint8_t REMCNT2    :1;
      uint8_t REMCNT1    :1;
      uint8_t REMCNT0    :1;
    };
    uint8_t val;
} REMCNTL_t;

// 0x225
typedef union{
    struct{
      uint8_t REMCNT15   :1;
      uint8_t REMCNT14   :1;
      uint8_t REMCNT13   :1;
      uint8_t REMCNT12   :1;
      uint8_t REMCNT11   :1;
      uint8_t REMCNT10   :1;
      uint8_t REMCNT9    :1;
      uint8_t REMCNT8    :1;
    };
    uint8_t val;
} REMCNTH_t;

// 0x226
typedef union{
    struct{
      uint8_t MAINCNT7   :1;
      uint8_t MAINCNT6   :1;
      uint8_t MAINCNT5   :1;
      uint8_t MAINCNT4   :1;
      uint8_t MAINCNT3   :1;
      uint8_t MAINCNT2   :1;
      uint8_t MAINCNT1   :1;
      uint8_t MAINCNT0   :1;
    };
    uint8_t val;
} MAINCNT0_t;

// 0x227
typedef union{
    struct{
      uint8_t MAINCNT15  :1;
      uint8_t MAINCNT14  :1;
      uint8_t MAINCNT13  :1;
      uint8_t MAINCNT12  :1;
      uint8_t MAINCNT11  :1;
      uint8_t MAINCNT10  :1;
      uint8_t MAINCNT9   :1;
      uint8_t MAINCNT8   :1;
    };
    uint8_t val;
} MAINCNT1_t;

// 0x228
typedef union{
    struct{
      uint8_t MAINCNT23  :1;
      uint8_t MAINCNT22  :1;
      uint8_t MAINCNT21  :1;
      uint8_t MAINCNT20  :1;
      uint8_t MAINCNT19  :1;
      uint8_t MAINCNT18  :1;
      uint8_t MAINCNT17  :1;
      uint8_t MAINCNT16  :1;
    };
    uint8_t val;
} MAINCNT2_t;

// 0x229
typedef union{
    struct{
      uint8_t STARTCNT   :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t MAINCNT25  :1;
      uint8_t MAINCNT24  :1;
    };
    uint8_t val;
} MAINCNT3_t;

// 0x22F
typedef union{
    struct{
      uint8_t            :1;
      uint8_t            :1;
      uint8_t            :1;
      uint8_t RSSIWAIT1  :1;
      uint8_t RSSIWAIT0  :1;
      uint8_t TESTMODE2  :1;
      uint8_t TESTMODE1  :1;
      uint8_t TESTMODE0  :1;
    };
    uint8_t val;
} TESTMODE_t;
