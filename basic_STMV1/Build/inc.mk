###########################################################
# GCC template makefile inc.mk
#
# On command line:
#
# make all = Make software.
# make clean = Clean out built project files.
#
# To rebuild project do "make clean" then "make all".
###########################################################

# model & sub model
MODEL = mango_test
SUBMODEL = mango_testing

PREFIX = arm-none-eabi-

REMOVE_CMD = rm

# Define programs and commands.
SHELL = sh
CC = $(PREFIX)gcc
CPP = $(PREFIX)g++
AR = $(PREFIX)ar
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
LD = $(PREFIX)ld
OBJCOPY = $(PREFIX)objcopy
OBJDUMP = $(PREFIX)objdump
SIZE = $(PREFIX)size
NM = $(PREFIX)nm
REMOVE = $(REMOVE_CMD)-rf
#hex file
HEX = $(OBJCOPY) -O ihex
BIN = $(OBJCOPY) -O binary -S

#cpu type set
CPU = -mcpu=armv7-m -mthumb -mthumb-interwork

#fpu

#float-abi
FLOAT-ABI = -mfloat-abi=soft

MCU = $(CPU) $(FLOAT-ABI)

#format set
FORMAT = binary

#opt
OPT = 2

DEBUG = -dwarf-2

#define set 
#RUN_MODE = 

#define flag
CDFLAG = -D $(RUN_MODE)

#include header
CINCS = 

#asm define set
ASDFLAG = -D $(RUN_MODE)

# Compiler flags.
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
#
# Flags for C and C++ (arm-elf-gcc/arm-elf-g++)
CFLAGS = -g $(DEBUG)
CFLAGS += $(CDFLAG) $(CINCS)
CFLAGS += -O$(OPT) $(MCU)
CFLAGS += 





# Define Messages
# English
MSG_LOAD_FILE = Creating load file:
MSG_EXTENDED_LISTING = Creating Extended Listing/Disassembly:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = ---- Linking :
MSG_CLEANING = Cleaning project:
MSG_ASMFROMC = "Creating asm-File from C-Source:"

