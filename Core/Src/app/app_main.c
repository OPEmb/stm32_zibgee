#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "app_main.h"
#include "app_cli.h"
#include "macros.h"

#define CLI_COMMAND_NUM (5)


static void reset(app_cli_t* cli,char* args,void* ctx){
    (void)cli;
    (void)args;
    (void)ctx;
    printf("reset\n");
}

static void cli_init(app_ctx_t* ctx){
    #define CB_INIT(_cb) {.name = PP_STRINGIFY(_cb),.cb=_cb}
    static app_cli_cb_t cbs[] = {
        CB_INIT(reset),
    };

    app_cli_init_t* init = malloc(sizeof(*init));
    assert(init);
    init->cbs = cbs;
    init->len = ARR_SIZE(cbs);
    init->write_char = ctx->write_char;
    app_cli_init(init);
}

static void init(app_ctx_t* ctx){
    cli_init(ctx);
}

void app_main(void* arg){
    init(arg);
    
}