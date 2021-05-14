#ifndef __I2C_CAN_DFS_H__
#define __I2C_CAN_DFS_H__

#include <avr/io.h>

// watch dog
#define WD_SET(val,...)                                 \
    __asm__ __volatile__(                               \
        "in __tmp_reg__,__SREG__"           "\n\t"      \
        "cli"                               "\n\t"      \
        "wdr"                               "\n\t"      \
        "sts %[wdreg],%[wden]"              "\n\t"      \
        "sts %[wdreg],%[wdval]"             "\n\t"      \
        "out __SREG__,__tmp_reg__"          "\n\t"      \
        :                                               \
        : [wdreg] "M" (&WDTCSR),                        \
          [wden]  "r" ((uint8_t)(0x18)),                \
          [wdval] "r" ((uint8_t)(val|(__VA_ARGS__+0)))  \
        : "r0"                                          \
)

#define WDTO_15MS               0
#define WDTO_30MS               1
#define WDTO_60MS               2
#define WDTO_120MS              3
#define WDTO_250MS              4
#define WDTO_500MS              5
#define WDTO_1S                 6
#define WDTO_2S                 7
#define WDTO_4S                 0x20
#define WDTO_8S                 0x21

#define WD_RST                  8
#define WDR()                   __asm__ __volatile__("wdr")

#define DEFAULT_I2C_ADDR    0X25

#define REG_ADDR        0X01
#define REG_DNUM        0x02
#define REG_BAUD        0X03
#define REG_MASK0       0X60
#define REG_MASK1       0X65
#define REG_FILT0       0X70
#define REG_FILT1       0X80
#define REG_FILT2       0X90
#define REG_FILT3       0XA0
#define REG_FILT4       0XB0
#define REG_FILT5       0XC0

#define REG_SEND        0X30
#define REG_RECV        0X40

#define REG_ADDR_SET    0X51

#endif

// END FILE