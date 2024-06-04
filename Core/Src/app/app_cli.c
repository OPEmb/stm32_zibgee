#include <stdio.h>
#include <Windows.h>
#include "FreeRTOS.h"
#include "task.h"
#include "app_main.h"
#include "app_cli.h"

#define EMBEDDED_CLI_IMPL
#include "embedded_cli.h"   

static EmbeddedCli* scli;

static void (*write_ch)(char c);

static void write_char(EmbeddedCli* cli, char c){
    write_ch(c);
}

void app_cli_init(app_cli_init_t* init){
    scli = embeddedCliNewDefault();
    assert(init->cbs);
    assert(init->len);
    assert(init->write_char);

    write_ch = init->write_char;
    scli->writeChar = write_char;
    printf("%p %p %p\n",write_ch,write_char,init->write_char);

    for(size_t i = 0; i < init->len;++i){
        
        embeddedCliAddBinding(scli,
            (CliCommandBinding){
                init->cbs[i].name,
                NULL,
                false,
                NULL,
                init->cbs[i].cb
            }
        );
    }

}

void app_cli_process(void)
{
    embeddedCliProcess(scli);
}

void app_cli_rx_char(char c){
    embeddedCliReceiveChar(scli,c);
}
