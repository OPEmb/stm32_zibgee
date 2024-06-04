#ifndef GPIO_IF_H
#define GPIO_IF_H

#include <stdint.h>

typedef struct{
    int port;
    int pin;
} gpio_if_t;

void gpio_if_set_pin(gpio_if_t* gpio);
void gpio_if_clear_pin(gpio_if_t* gpio);

#endif /* GPIO_IF_H */