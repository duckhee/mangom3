PREFIX = arm-none-eabi-
REMOVE_CMD = rm
#startup c file
STARTUP_C = Hw_StartUp.c
#build folder
OUTDIR = ./Build
#target image
TARGET = main
#include header file
EXTRAINCDIRS = ../LIB               \
               ../HW                \
			   ../HW/Hw_Core        \
			   ../Hw/Hw_Lib         \
			   ../AP                \
			   ../AP/Ap_Core        \
			   ../Menu              \
			   ../Main              \
			   ../AP/Ap_Lib         \

#src hardware c file
SRC_HW = ../HW/Hw_Core/$(STARTUP_C)                      \
		 ../HW/Hw_Core/Hw.c                              \
         ../HW/Hw_Core/Hw_Rcc.c                          \
		 ../HW/Hw_Core/Hw_GPIO.c                         \
		 ../HW/Hw_Core/Hw_Usart.c                        \
		 ../HW/Hw_Core/Hw_TIM.c                          \
		 ../HW/Hw_Core/Hw_EXTI.c                         \
		 ../HW/Hw_Core/Hw_IRQ.c                          \
		 ../HW/Hw_Core/Hw_NVIC.c                         \
		 ../Hw/Hw_Core/Hw_Flash.c                        \
		 ../HW/Hw_Core/Hw_ADC.c                          \
		 ../HW/Hw_Core/Hw_DMA.c                          \
		 ../HW/Hw_Core/Hw_SPI.c                          \
		 ../HW/Hw_Core/Hw_I2C.c                          \
		 #../HW/Hw_Core/Hw_SysTick.c                      \
		 
SRC_HWDRIVER = ../Hw/Hw_Lib/Hw_Led.c                    \


#src aplication c file
SRC_AP = ../Main/main.c                                  \
         #../AP/Ap_Core/Get_SysClock.c                    \
		 ../Ap/Ap_Core/Queue.c                           \
         #../AP


#src library c file
SRC_LIB = ../LIB/Ld_printf.c                          \
          ../LIB/Util.c


#src menu c file
SRC_MENU = ../Menu/Menu_Command.c                                 \
           ../Menu/Led_Command.c                                  \

#source file 
SRC =$(SRC_HW) $(SRC_LIB) $(SRC_MENU) $(SRC_AP) $(SRC_HWDRIVER)
#thumb mode
THUMB = -mthumb
#include header
INCLUDE = -I./include -I.

#C compiler option
CC = $(PREFIX)gcc
CPP = $(PREFIX)g++
OBJCOPY = $(PREFIX)objcopy
OBJDUMP = $(PREFIX)objdump
OBJNM = $(PREFIX)nm
SIZE = $(PREFIX)size
REMOVE = $(REMOVE_CMD) -rf

#$(subst a,b,text) : text에서 a를 b로 교체할 수 있어요.
#$(patsubst pattern,rep,text) : text에서 pattern을 찾아서 rep로 replace해요.
#$(strip string) : string안에서 공백문자들을 제거해요.
#$(addsuffix suffix,name) : name에다가 suffix를 뒤에 더 붙여 줘요.
#$(addprefix prefix,name) : name 앞에다가 prefix를 붙여주지요.
#$(findstring find,text) : text에서 find라는 string을 찾아요.
#$(dir name) : name에서 directory부분을 빼내주어요.
#$(notdir name) : name에서 directory가 아닌 부분을 빼내주어요. 보통 file name 뽑아낼 때 쓰죠.
#$(suffix name) : name에서 확장자를 추출해 내요.
#$(basename name) : name에서 확장자를 뺀 file이름을 빼내주지요.
#$(word n,text) : text중에서 n 번째 단어를 추출해 주어요.
#$(words text) : text가 몇 개 단어로 이루어져 있는지 봐주지요.
#$(wildcard pattern) : 지정된 Directory에서 pattern과 일치하는 file들을 가져오지요. 디렉토리를 지정하지 않으면 현재 dir이에요.
#$(shell command) : Shell 명령어를 실행해 주고 그 결과를 가져오지요.
#$(origin variable) : Macro가 어떻게 정의되었는지를 알려줘요. 이걸로 debugging을 하기도 해요.
#$(foreach var,words...,text) : var에 각각의 word를 넣고서 text에 적용하는 거에요. 말이 좀 어렵지만, 보통 text에는 $(var)에 관련된 내용이 같이 들어 있기 마련이죠. 어렵다.
# 몇 개 예만 들어 볼께요.
#보통 addprefix 같은 경우는 어디에 쓰이는가 보겠사옵니다.
#'
#OBJS :=  $(addprefix $(TARGETDIR)/, $(SOURCES:%.c= %.o))
# 
#이렇게 하면 SOURCES로 등록된 모든 c file의 확장자를 ,o로 바꾸고, 그 앞에다가는 특정 directory를 붙여 주겠죠. 그러면 일관된 directory에 ,o file들을 모아놓을 수 있답니다.
#
# Compiler flags.
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
#

# -mfloat-abi=name
#    Specifies which floating-point ABI to use.
#    "soft": Causes GCC to generate output containing library calls for
#            floating-point operations. Same as -msoft-float.
#    "softfp": Allows the generation of code using hardware floating-point
#            instructions, but still uses the soft-float calling conventions.
#    "hard": Allows generation of floating-point instructions and uses
#            FPU-specific calling conventions. Same as -mhard-float
#    Note that the hard-float and soft-float ABIs are not link-compatible;
#    you must compile your entire program with the same ABI, and link with a
#    compatible set of libraries.
#
# -msoft-float, -mhard-float: Use -mfloat-abi=name instead.
#
# -mfpu=fpv4-sp-d16
#    Specify which FPU is available. I think, this is clear from the
#    -mcpu= but OTOH, we explicitly link to fpv4-sp-d16 libraries, so let's
#    keep it in there to be sure.
#
# -fsingle-precision-constant
#    Ensure that 1.0 is treated as 1.0f. Avoids that intermediate DOUBLE
#    floats are generated. Writing the 'f' suffix is better but error-prone.
#
# -mfix-cortex-m3-ldrd
#    Is automatically enabled for Cortex-M3.
#
# -fno-common : unclear if needed
#
# -lm -lc
#    Required during linking for sqrtf() etc.
#

#Need to put this pack in CFLAGS????
#-D"assert_param(x)="
#float add ??? 
#CFLAGS  = -march=armv7-m -mthumb-interwork -gdwarf-2 -O2 -mfloat-abi=soft -msoft-float
#CPU_SPEC  += -mfloat-abi=soft
# Hardware float support
#CPU_SPEC  += -mfloat-abi=hard -mfpu=fpv4-sp-d16  -ffast-math
#CFLAGS += -fsingle-precision-constant -Wdouble-promotion
#CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard

# Flags for C and C++ (arm-elf-gcc/arm-elf-g++) -DSTM32F10X_MD는 칩의 사양을 선택하는 것 
CFLAGS  = -gdwarf-2 -O2 -mcpu=cortex-m3 -mthumb-interwork -DSTM32F10X_MD 
CFLAGS += $(INCLUDE) -mlong-calls -ffunction-sections -fdata-sections -Wall -Wextra -Wimplicit -Wcast-align -Wpointer-arith -Wredundant-decls 
CFLAGS += -Wshadow -Wcast-qual -Wcast-align -Wa,-adhlns=start_stm32f10x.lst -MD -MP -MF $(TARGET).elf.d

#header file path remove
CFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS))

#flag only for C
CONLYFLAGS += -Wnested-externs 

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
CONLYFLAGS += -std=gnu99

# Linker flags.
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
#LDFLAGS = -static -nostdlib -nostartfiles -u _printf_float --specs=nano.specs -lc -lnosys -Wl,-Map=$(TARGET).map,--cref,--gc-sections -L./ -lc  -lm  -lc -lgcc -T.//STM32F10x_flash.ld
#LDFLAGS += --specs=nano.specs -lc -lnosys
#LDFLAGS += -u _printf_float
#ELF32_LDFLAGS = -Wl,-T,stm32f10x.ld
#LDFLAGS = -Map=$(TARGET).map --cref
#이게 맞는지? 정적 파일과 lib 사용과 startfile 사용을 하지 않는다고 선언 하는 것 -nostdlib 라이브러리 사용 하지 않는다는 flag
LDFLAGS = -static -nostdlib -nostartfiles -Wl,-Map=$(TARGET).map,--cref,--gc-sections -L./ -lc  -lm  -lc -lgcc -T.//STM32F103x_flash.ld

#object file size get elf size
ELFSIZE = $(SIZE) -A $(TARGET).elf

# Define Messages
# English
MSG_LOAD_FILE = Creating load file:
MSG_EXTENDED_LISTING = Creating Extended Listing/Disassembly:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = ---- Linking :
MSG_CLEANING = Cleaning project:
MSG_ASMFROMC = "Creating asm-File from C-Source:"



#list all src file
ALLSRC     =  $(SRC)

#list of all source files without directory and file-extension. 기본 경로 삭제 ?
ALLSRCBASE = $(notdir $(basename $(ALLSRC)))
# Define all object files.
#ALLOBJ = $(addprefix $(OUTDIR)/, $(addsuffix .o, $(ALLSRCBASE)))
ALLOBJ = $(addsuffix .o, $(ALLSRCBASE))


#$@화면에 표출 

#define target
all: createdirs build sizeinfo gcc_version

elf: $(TARGET).elf
lss: $(TARGET).lss 
sym: $(TARGET).sym
hex: $(TARGET).hex
bin: $(TARGET).bin

build: elf hex bin lss sym

#size info command 
sizeinfo:
	@echo code size $@
	$(ELFSIZE)


#gcc version command
gcc_version:
	@echo gcc version make $@
	$(CC) --version

# Create output directories.
createdirs:
	-@md $(OUTDIR) >NUL 2>&1 || echo "" >NUL
	-@md $(OUTDIR)\dep >NUL 2>&1 || echo "" >NUL

# Create final output file (.hex) from ELF output file.
%.hex: %.elf
	@echo $(MSG_LOAD_FILE) $@
	$(OBJCOPY) -O ihex $< $@

# Create final output file (.bin) from ELF output file.
%.bin: %.elf
	@echo $(MSG_LOAD_FILE) $@
	$(OBJCOPY) -O binary $< $@


# Create extended listing file/disassambly from ELF output file.
# using objdump testing: option -C
%.lss: %.elf
	@echo $(MSG_EXTENDED_LISTING) $@
	$(OBJDUMP) -h -S -C -r $< > $@
#	$(OBJDUMP) -x -S $< > $@

# Create a symbol table from ELF output file.
%.sym: %.elf
	@echo $(MSG_SYMBOL_TABLE) $@
	$(OBJNM) -n $< > $@

# Link: create ELF output file from object files.
.SECONDARY : $(TARGET).elf
.PRECIOUS : $(ALLOBJ)
%.elf:  $(ALLOBJ)
	@echo $(MSG_LINKING) $@
	$(CC) $(THUMB) $(CFLAGS) $(ALLOBJ) --output $@ $(LDFLAGS)

# Compile: create object files from C source files.
define COMPILE_C_TEMPLATE
$(notdir $(basename $(1))).o : $(1)
	@echo $(MSG_COMPILING) $$< to $$@
	$(CC) -c $(THUMB) $$(CFLAGS) $$(CONLYFLAGS) $$< -o $$@ 
endef
$(foreach src, $(SRC), $(eval $(call COMPILE_C_TEMPLATE, $(src)))) 

# Compile: create assembler files from C source files. ARM/Thumb
$(SRC:.c=.s) : %.s : %.c
	@echo $(MSG_ASMFROMC) $< to $@
	$(CC) $(THUMB) -S $(CFLAGS) $(CONLYFLAGS) $< -o $@
	
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
# Define all listing files (used for make clean).
LSTFILES = $(addsuffix .lst, $(ALLSRCBASE))
# Define all depedency-files (used for make clean).
DEPFILES = $(addsuffix .o.d, $(ALLSRCBASE))


#target clean project
clean: clean_list

clean_list:
	@echo $(MSG_CLEANING)
	$(REMOVE) $(TARGET).map
	$(REMOVE) $(TARGET).elf
	$(REMOVE) $(TARGET).elf.d
	$(REMOVE) $(TARGET).hex
	$(REMOVE) $(TARGET).bin
	$(REMOVE) $(TARGET).sym
	$(REMOVE) $(TARGET).lss
	$(REMOVE) $(ALLOBJ)
	$(REMOVE) $(LSTFILES)
	$(REMOVE) $(DEPFILES)
	$(REMOVE) $(SRC:.c=.s)
	$(REMOVE) *.lst
	$(REMOVE) NUL


# Create object files directory
##$(shell mkdir $(OBJDIR) 2>/dev/null)

# Include the dependency files.
#-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)
-include $(wildcard dep/*)

# Listing of phony targets.
.PHONY : all finish \
build elf hex bin lss sym clean clean_list createdirs sizeinfo


