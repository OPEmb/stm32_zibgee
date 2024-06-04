#ifndef APP_MAIN_H
#define APP_MAIN_H

#include "spi_if.h"
#include "gpio_if.h"
#include "app_cli.h"

typedef struct{
    app_cli_write_char_fn write_char;
} app_ctx_t;

void app_main(void* arg);

#endif /* APP_MAIN_H */