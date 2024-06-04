#ifndef APP_CLI_H
#define APP_CLI_H

#include "embedded_cli.h"

typedef void (*app_cli_write_char_fn)(char c);
typedef struct EmbeddedCli app_cli_t;

typedef struct{
    const char* name;
    void (*cb)(app_cli_t* cli,char* args,void* ctx);
} app_cli_cb_t;

typedef struct{
    app_cli_cb_t* cbs;
    size_t len;
    app_cli_write_char_fn write_char;
} app_cli_init_t;

void app_cli_init(app_cli_init_t* init);
void app_cli_rx_char(char c);
void app_cli_process(void);

#endif /* APP_CLI_H */