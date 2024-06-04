#ifndef UART_IF_H
#define UART_IF_H

#include <stdint.h>

typedef struct{
    int (*rx)(uint8_t* c,size_t len);
    int (*tx)(uint8_t* c,size_t len);
} uart_if_t;

#endif /* UART_IF_H */