#include "Windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "app_main.h"
#include "app_cli.h"

#define mainQUEUE_RECEIVE_TASK_PRIORITY        ( tskIDLE_PRIORITY + 2 )
#define mainQUEUE_SEND_TASK_PRIORITY           ( tskIDLE_PRIORITY + 1 )

#define mainNO_KEY_PRESS_VALUE                -1
#define mainOUTPUT_TRACE_KEY                  't'
#define mainINTERRUPT_NUMBER_KEYBOARD         3

#define mainTRACE_FILE_NAME                   "Trace.dump"

/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void );
void vApplicationIdleHook( void );
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vApplicationTickHook( void );
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize );

/*
 * Writes trace data to a disk file when the trace recording is stopped.
 * This function will simply overwrite any trace files that already exist.
 */
static void prvSaveTraceFile( void );

/*
 * Windows thread function to capture keyboard input from outside of the
 * FreeRTOS simulator. This thread passes data safely into the FreeRTOS
 * simulator using a stream buffer.
 */
static DWORD WINAPI prvWindowsKeyboardInputThread( void * pvParam );

/*
 * Interrupt handler for when keyboard input is received.
 */
static uint32_t prvKeyboardInterruptHandler( void );

/*
 * Keyboard interrupt handler for the blinky demo.
 */
extern void KeyboardInterruptHandler(INPUT_RECORD* record );

/*-----------------------------------------------------------*/

/* When configSUPPORT_STATIC_ALLOCATION is set to 1 the application writer can
use a callback function to optionally provide the memory required by the idle
and timer tasks.  This is the stack that will be used by the timer task.  It is
declared here, as a global, so it can be checked by a test that is implemented
in a different file. */
StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

/* Thread handle for the keyboard input Windows thread. */
static HANDLE xWindowsKeyboardInputThreadHandle = NULL;

/* This stores the last key pressed that has not been handled.
 * Keyboard input is retrieved by the prvWindowsKeyboardInputThread
 * Windows thread and stored here. This is then read by the idle
 * task and handled appropriately. */
static void* key = NULL;

app_ctx_t app_ctx;
void write_char(char c);

/*-----------------------------------------------------------*/

int main( void )
{

    /* Do not include trace code when performing a code coverage analysis. */
    #if( projCOVERAGE_TEST != 1 )
    {
        configASSERT( xTraceInitialize() == TRC_SUCCESS );

        fflush( stdout );
        fflush( stdin );
        configASSERT( xTraceEnable( TRC_START ) == TRC_SUCCESS );
    }
    #endif

                
    /* Set interrupt handler for keyboard input. */
    vPortSetInterruptHandler( mainINTERRUPT_NUMBER_KEYBOARD, prvKeyboardInterruptHandler );
    xWindowsKeyboardInputThreadHandle = CreateThread(
        NULL,                          
        0,                             
        prvWindowsKeyboardInputThread, 
        NULL,                          
        0,                             
        NULL);

    fflush( stdout );
    SetThreadAffinityMask( xWindowsKeyboardInputThreadHandle, ~0x01u );
   
    
    app_ctx.write_char = write_char;
    xTaskCreate(app_main,
                NULL,
                1024,
                &app_ctx,
                mainQUEUE_SEND_TASK_PRIORITY,
                NULL
                );
    
    

    vTaskStartScheduler();
    // entry point to application

    return 0;
}
/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
    vAssertCalled( __LINE__, __FILE__ );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{

}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
    /* This function will be called by each tick interrupt if
    configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
    added here, but the tick hook is called from an interrupt context, so
    code must not attempt to block, and only the interrupt safe FreeRTOS API
    functions can be used (those that end in FromISR()). */
}
/*-----------------------------------------------------------*/

void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
volatile uint32_t ulSetToNonZeroInDebuggerToContinue = 0;

    /* Called if an assertion passed to configASSERT() fails.  See
    http://www.freertos.org/a00110.html#configASSERT for more information. */

    /* Parameters are not used. */
    ( void ) ulLine;
    ( void ) pcFileName;


    taskENTER_CRITICAL();
    {
        printf("ASSERT! Line %ld, file %s, GetLastError() %ld\r\n", ulLine, pcFileName, GetLastError());
        fflush( stdout );

        #if( projCOVERAGE_TEST != 1 )
        {
            /* Stop the trace recording. */
            ( void ) xTraceDisable();
            prvSaveTraceFile();
        }
        #endif

        /* You can step out of this function to debug the assertion by using
        the debugger to set ulSetToNonZeroInDebuggerToContinue to a non-zero
        value. */
        while( ulSetToNonZeroInDebuggerToContinue == 0 )
        {
            __asm volatile( "NOP" );
            __asm volatile( "NOP" );
        }

        #if( projCOVERAGE_TEST != 1 )
        {
            /* Re-enable recording */
            ( void ) xTraceEnable( TRC_START );
        }
        #endif
    }
    taskEXIT_CRITICAL();
}
/*-----------------------------------------------------------*/

static void prvSaveTraceFile( void )
{
    /* Tracing is not used when code coverage analysis is being performed. */
    #if( projCOVERAGE_TEST != 1 )
    {
        FILE* pxOutputFile;
		
        pxOutputFile = fopen( mainTRACE_FILE_NAME, "wb");

        if( pxOutputFile != NULL )
        {
            fwrite( RecorderDataPtr, sizeof( RecorderDataType ), 1, pxOutputFile );
            fclose( pxOutputFile );
            printf( "\r\nTrace output saved to %s\r\n", mainTRACE_FILE_NAME );
            fflush( stdout );
        }
        else
        {
            printf( "\r\nFailed to create trace dump file\r\n" );
            fflush( stdout );
        }
    }
    #endif
}
/*-----------------------------------------------------------*/

/* configUSE_STATIC_ALLOCATION is set to 1, so the application must provide an
implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
used by the Idle task. */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
/* If the buffers to be provided to the Idle task are declared inside this
function then they must be declared static - otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

/*-----------------------------------------------------------*/

/* configUSE_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize )
{
/* If the buffers to be provided to the Timer task are declared inside this
function then they must be declared static - otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xTimerTaskTCB;

    /* Pass out a pointer to the StaticTask_t structure in which the Timer
    task's state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task's stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

/*-----------------------------------------------------------*/

/*
 * Interrupt handler for when keyboard input is received.
 */
static uint32_t prvKeyboardInterruptHandler( void )
{
    INPUT_RECORD* record = key;
    KeyboardInterruptHandler(record);
    /* This interrupt does not require a context switch so return pdFALSE */
    return pdFALSE;
}

/*-----------------------------------------------------------*/

/*
 * Windows thread function to capture keyboard input from outside of the
 * FreeRTOS simulator. This thread passes data into the simulator using
 * an integer.
 */
static DWORD WINAPI prvWindowsKeyboardInputThread( void * pvParam )
{
    ( void ) pvParam;
    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD record;
    key = &record;
    for ( ; ; )
    {
        /* Block on acquiring a key press */

        DWORD read;
        GetNumberOfConsoleInputEvents(hConsole, &read);

        if (read == 0) {
            Sleep(10);
            continue;
        }

        ReadConsoleInput(hConsole, &record, 1, &read);
        if (read > 0 && record.EventType == KEY_EVENT){
            KEY_EVENT_RECORD event = record.Event.KeyEvent;
            if (!event.bKeyDown || event.uChar.AsciiChar == 0)
                continue;
            vPortGenerateSimulatedInterrupt( mainINTERRUPT_NUMBER_KEYBOARD );
        }
    }

    /* Should not get here, report negative exit status. */
    return -1;
}

/*-----------------------------------------------------------*/

/* The below code is used by the trace recorder for timing. */
static uint32_t ulEntryTime = 0;

void vTraceTimerReset( void )
{
    ulEntryTime = xTaskGetTickCount();
}

uint32_t uiTraceTimerGetFrequency( void )
{
    return configTICK_RATE_HZ;
}

uint32_t uiTraceTimerGetValue( void )
{
    return( xTaskGetTickCount() - ulEntryTime );
}

void vApplicationDaemonTaskStartupHook( void )
{

}

void write_char(char c){
    printf("%c",c);
}

void KeyboardInterruptHandler(INPUT_RECORD* record){
    KEY_EVENT_RECORD event = record->Event.KeyEvent;
    WORD key = event.wVirtualKeyCode;
    if (key >= 37 && key <= 40) {
        // send as escape sequence
        app_cli_rx_char('\x1B');
        app_cli_rx_char('[');

        switch (key) {
        case 38:
            app_cli_rx_char('A');
            break;
        case 40:
            app_cli_rx_char('B');
            break;
        case 37:
            app_cli_rx_char('D');
            break;
        case 39:
            app_cli_rx_char('C');
            break;
        }
    }

    char aChar = event.uChar.AsciiChar;

    // escape code
    if (aChar == 27){
        abort(); // classic exit
        return;
    }

    if (aChar > 0){
        app_cli_rx_char(aChar);
    }

    app_cli_process();
}
