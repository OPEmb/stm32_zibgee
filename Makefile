# Build directory
BUILD_DIR := ./build

# Compiler - Note this expects you are using MinGW version of GCC
CXX := g++
CC := gcc
CFLAGS := -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -Wcast-qual -D_WIN32_WINNT=0x0601

ifeq ($(COVERAGE_TEST),1)
  CFLAGS += -DprojCOVERAGE_TEST=1
else
  CFLAGS += -DprojCOVERAGE_TEST=0
endif

# Linker - Note this expects you are using MinGW version of GCC
LD :=  g++
LDFLAGS := -Xlinker

# Executable Targets
EXE := $(BUILD_DIR)/main.exe

# FreeRTOS Kernel
FREERTOS_KERNEL_DIR := FreeRTOS/Source
FREERTOS_KERNEL_INCLUDES :=
FREERTOS_KERNEL_SOURCES :=
FREERTOS_KERNEL_INCLUDE_DIRS :=
FREERTOS_KERNEL_OBJS :=
FREERTOS_KERNEL_BUILD_DIR := $(BUILD_DIR)/FreeRTOS-Kernel

## FreeRTOS Kernel includes
FREERTOS_KERNEL_INCLUDES += $(wildcard $(FREERTOS_KERNEL_DIR)/include/*.h)
FREERTOS_KERNEL_INCLUDE_DIRS += -I $(FREERTOS_KERNEL_DIR)/include

## FreeRTOS Kernel sources
FREERTOS_KERNEL_SOURCES += $(wildcard $(FREERTOS_KERNEL_DIR)/*.c)
FREERTOS_KERNEL_SOURCES += $(FREERTOS_KERNEL_DIR)/portable/MemMang/heap_4.c

## FreeRTOS Kernel Windows port includes
FREERTOS_KERNEL_INCLUDES += $(FREERTOS_KERNEL_DIR)/portable/MSVC-MingW/portmacro.h
FREERTOS_KERNEL_INCLUDE_DIRS += -I $(FREERTOS_KERNEL_DIR)/portable/MSVC-MingW

## FreeRTOS Kernel Windows port sources
FREERTOS_KERNEL_SOURCES += $(FREERTOS_KERNEL_DIR)/portable/MSVC-MingW/port.c

## FreeRTOS Kernel configuration includes
FREERTOS_KERNEL_INCLUDES += ./FreeRTOSConfig.h
FREERTOS_KERNEL_INCLUDE_DIRS += -I .

# FreeRTOS Kernel objects
FREERTOS_KERNEL_SOURCES_NAMES :=$(notdir $(FREERTOS_KERNEL_SOURCES))
FREERTOS_KERNEL_OBJS := $(FREERTOS_KERNEL_SOURCES_NAMES:%.c=$(FREERTOS_KERNEL_BUILD_DIR)/%.o)

# Trace Recorderss
FREERTOS_PLUS_TRACE_DIR := FreeRTOS/FreeRTOS-Plus/Source/FreeRTOS-Plus-Trace
FREERTOS_PLUS_TRACE_INCLUDES :=
FREERTOS_PLUS_TRACE_SOURCES :=
FREERTOS_PLUS_TRACE_INCLUDE_DIRS :=
FREERTOS_PLUS_TRACE_OBJS :=
FREERTOS_PLUS_TRACE_BUILD_DIR := $(BUILD_DIR)/FreeRTOS-Plus-Trace

## Trace Recorder includes
FREERTOS_PLUS_TRACE_INCLUDES += $(wildcard $(FREERTOS_PLUS_TRACE_DIR)/Include/*.h)
FREERTOS_PLUS_TRACE_INCLUDE_DIRS += -I $(FREERTOS_PLUS_TRACE_DIR)/Include

## Trace Recorder sources
FREERTOS_PLUS_TRACE_SOURCES += $(wildcard $(FREERTOS_PLUS_TRACE_DIR)/*.c)

## Trace Recorder configuration includes
FREERTOS_PLUS_TRACE_INCLUDES += $(wildcard ./FreeRTOS/Trace_Recorder_Configuration/*.h)
FREERTOS_PLUS_TRACE_INCLUDE_DIRS += -I ./FreeRTOS/Trace_Recorder_Configuration

# Trace Recoder objects
FREERTOS_PLUS_TRACE_SOURCES_NAMES :=$(notdir $(FREERTOS_PLUS_TRACE_SOURCES))
FREERTOS_PLUS_TRACE_OBJS := $(FREERTOS_PLUS_TRACE_SOURCES_NAMES:%.c=$(FREERTOS_PLUS_TRACE_BUILD_DIR)/%.o)


# Includes
VENDOR  			 := vendor
CORE_INC     		 := Core/Inc
IF_INC_DIR   		 := $(CORE_INC)/interface
MRF_INC_DIR  		 := $(CORE_INC)/mrfj40ma
UTIL_INC_DIR 		 := $(CORE_INC)/util
EMBEDDED_CLI_INC_DIR := $(VENDOR)/embedded-cli

# Sources
CORE_SRC := Core/Src

# Main
MAIN_INC_DIR := $(CORE_INC)
MAIN_INC_DIR += $(IF_INC_DIR)
MAIN_INC_DIR += $(MRF_INC_DIR)
MAIN_INC_DIR += $(UTIL_INC_DIR)
MAIN_INC_DIR += $(UTIL_INC_DIR)
MAIN_INC_DIR += $(EMBEDDED_CLI_INC_DIR)

MAIN_SRC_DIR := Core/Src/app


MAIN_INCLUDES := $(foreach dir,$(MAIN_INC_DIR),$(wildcard $(MAIN_INC_DIR)/*.h))
MAIN_SOURCES := $(MAIN_SRC_DIR)/app_main.c $(MAIN_SRC_DIR)/app_freertos_win.c $(MAIN_SRC_DIR)/app_cli.c
MAIN_INCLUDE_DIRS := -I. $(foreach dir,$(MAIN_INC_DIR),-I$(dir))
$(info $(MAIN_INCLUDE_DIRS) $(MAIN_INC_DIR))

MAIN_BUILD_DIR := $(BUILD_DIR)/main

## Main includes

## Main sources
MAIN_SOURCES += $(wildcard $(MAIN_DIR)/*.c)
MAIN_SOURCES += FreeRTOS/Run-time-stats-utils.c

## Main objects
MAIN_SOURCES_NAMES :=$(notdir $(MAIN_SOURCES))
MAIN_OBJS := $(MAIN_SOURCES_NAMES:%.c=$(MAIN_BUILD_DIR)/%.o)

$(EXE) : $(MAIN_OBJS) $(FREERTOS_KERNEL_OBJS) $(FREERTOS_DEMOS_OBJS) $(FREERTOS_PLUS_TRACE_OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ -lwinmm

test: $(EXE)
	$(EXE)

# Main objects rules
$(MAIN_OBJS): %.o: $(MAIN_SOURCES) $(MAIN_INCLUDES) $(FREERTOS_KERNEL_INCLUDES)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(MAIN_INCLUDE_DIRS) $(FREERTOS_KERNEL_INCLUDE_DIRS) $(FREERTOS_PLUS_TRACE_INCLUDE_DIRS) -o $@ $(filter %$(notdir $(patsubst %.o, %.c, $@)), $^) $(filter %$(notdir $(patsubst %.o, %.cpp, $@)), $^)

# FreeRTOS Kernel objects rules
$(FREERTOS_KERNEL_OBJS): %.o: $(FREERTOS_KERNEL_SOURCES) $(FREERTOS_KERNEL_INCLUDES) $(FREERTOS_PLUS_TRACE_INCLUDES)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(FREERTOS_KERNEL_INCLUDE_DIRS) $(FREERTOS_PLUS_TRACE_INCLUDE_DIRS) -o $@ $(filter %$(notdir $(patsubst %.o, %.c, $@)), $^) 

# FreeRTOS Demos objects rules
$(FREERTOS_DEMOS_OBJS): %.o: $(FREERTOS_DEMOS_SOURCES) $(FREERTOS_DEMOS_INCLUDES) $(FREERTOS_KERNEL_INCLUDES) $(FREERTOS_PLUS_TRACE_INCLUDES)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(FREERTOS_DEMOS_INCLUDE_DIRS) $(FREERTOS_KERNEL_INCLUDE_DIRS) $(FREERTOS_PLUS_TRACE_INCLUDE_DIRS) -o $@ $(filter %$(notdir $(patsubst %.o, %.c, $@)), $^)

# Trace Recorder object filess
$(FREERTOS_PLUS_TRACE_OBJS): %.o: $(FREERTOS_PLUS_TRACE_SOURCES) $(FREERTOS_PLUS_TRACE_INCLUDES) $(FREERTOS_KERNEL_INCLUDES)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(FREERTOS_PLUS_TRACE_INCLUDE_DIRS) $(FREERTOS_KERNEL_INCLUDE_DIRS) -o $@ $(filter %$(notdir $(patsubst %.o, %.c, $@)), $^)

.PHONY: test

# Clean rule
clean:
	rm -rf $(BUILD_DIR)


