#ifndef TRACE_H
#define TRACE_H

#include <stdint.h>

// very original
#define TRACE_MODULE_START (UL0xDEADBEEFBADCOFFE)
#define TRACE_MODULE_END (UL0xBADCOFFEDEADBEEF)

// archaic logging ways but what can you do, I'm but one man
typedef enum{
    TRACE_MODULE_MRF,
    TRACE_MODULE_MAIN,

} trace_module_t;

typedef struct{
    uint64_t start_marker;
    uint64_t module;
    uint64_t args;
    uint64_t end_marker;
} trace_packet_t;

#endif /* TRACE_H */