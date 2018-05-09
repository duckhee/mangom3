#include "Hw.h"

typedef void (*const intfunc)(void);
// Private define ----------------------------------------------------------------------------------------
//#define WEAK __attribute__ ((weak))


//-- init value for the stack pointer. defined in linker script 
extern unsigned long _estack;
extern unsigned long _sidata;    /*!< Start address for the initialization 
                                      values of the .data section.            */
extern unsigned long _sdata;     /*!< Start address for the .data section     */    
extern unsigned long _edata;     /*!< End address for the .data section       */    
extern unsigned long _sbss;      /*!< Start address for the .bss section      */
extern unsigned long _ebss;      /*!< End address for the .bss section        */      
extern void 	     _eram;      /*!< End address for ram                     */

//--------  Private function prototypes ------------------------------------------------------------------
void Reset_Handler(void) __attribute__((__interrupt__));
extern int main();
void Init_Data();
void Default_Handler(void);

//--------  Next declaration of the default fault handlers.  ---------------------------------------------

//	mthomas void WEAK Reset_Handler(void);
void WEAK NMI_Handler(void);					// 01
void WEAK HardFault_Handler(void);				// 02
void WEAK MemManage_Handler(void);				// 03
void WEAK BusFault_Handler(void);				// 04
void WEAK UsageFault_Handler(void);				// 05

//	mthomas void WEAK MemManage_Handler(void);
void WEAK SVC_Handler(void);					// 06
void WEAK DebugMon_Handler(void);				// 07
void WEAK PendSV_Handler(void);					// 08
void WEAK SysTick_Handler(void);				// 09

//	External Interrupts	//
void WEAK WWDG_IRQHandler(void);				// 10
void WEAK PVD_IRQHandler(void);					// 11
void WEAK TAMPER_IRQHandler(void);				// 12
void WEAK RTC_IRQHandler(void);					// 13
void WEAK FLASH_IRQHandler(void);				// 14
void WEAK RCC_IRQHandler(void);					// 15
void WEAK EXTI0_IRQHandler(void);				// 16
void WEAK EXTI1_IRQHandler(void);				// 17
void WEAK EXTI2_IRQHandler(void);				// 18
void WEAK EXTI3_IRQHandler(void);				// 19
void WEAK EXTI4_IRQHandler(void);				// 20
void WEAK DMA1_Channel1_IRQHandler(void);		// 21
void WEAK DMA1_Channel2_IRQHandler(void);		// 22
void WEAK DMA1_Channel3_IRQHandler(void);		// 23
void WEAK DMA1_Channel4_IRQHandler(void);		// 24
void WEAK DMA1_Channel5_IRQHandler(void);		// 25
void WEAK DMA1_Channel6_IRQHandler(void);		// 26
void WEAK DMA1_Channel7_IRQHandler(void);		// 27
void WEAK ADC1_2_IRQHandler(void);				// 28
void WEAK USB_HP_CAN1_TX_IRQHandler(void);		// 29
void WEAK USB_LP_CAN1_RX0_IRQHandler(void);		// 30
void WEAK CAN1_RX1_IRQHandler(void);			// 31
void WEAK CAN1_SCE_IRQHandler(void);			// 32
void WEAK EXTI9_5_IRQHandler(void);				// 33
void WEAK TIM1_BRK_IRQHandler(void);			// 34
void WEAK TIM1_UP_IRQHandler(void);				// 35
void WEAK TIM1_TRG_COM_IRQHandler(void);		// 36
void WEAK TIM1_CC_IRQHandler(void);				// 37
void WEAK TIM2_IRQHandler(void);				// 38
void WEAK TIM3_IRQHandler(void);				// 39
void WEAK TIM4_IRQHandler(void);				// 40
void WEAK I2C1_EV_IRQHandler(void);				// 41
void WEAK I2C1_ER_IRQHandler(void);				// 42
void WEAK I2C2_EV_IRQHandler(void);				// 43
void WEAK I2C2_ER_IRQHandler(void);				// 44
void WEAK SPI1_IRQHandler(void);				// 45
void WEAK SPI2_IRQHandler(void);				// 46
void WEAK USART1_IRQHandler(void);				// 47
void WEAK USART2_IRQHandler(void);				// 48
void WEAK USART3_IRQHandler(void);				// 49
void WEAK EXTI15_10_IRQHandler(void);			// 50
void WEAK RTCAlarm_IRQHandler(void);			// 51
void WEAK USBWakeUp_IRQHandler(void);			// 52

// =======================================================================================================
//
//	mthomas: If been built with VECT_TAB_RAM this creates two tables:
//
//	(1) a minimal table (stack-pointer, reset-vector) used during startup before relocation of the 
//	    vector table using SCB_VTOR
//	(2) a full table which is copied to RAM and used after vector relocation (NVIC_SetVectorTable)
//
//	If been built without VECT_TAB_RAM the following comment from STM is valid:
//	The minimal vector table for a Cortex M3. Note that the proper constructs must be placed on this 
//	to ensure that it ends up at physical address 0x0000.0000.
//
// =======================================================================================================

// -------  isr_vactor table are located in Flash  -------------------------------------------------------



__attribute__((section(".isr_vectorsflash")))
//__attribute__(()) 붙여서 해야한다.

void (*g_pfnVectors[])(void) = 
{
	(intfunc)((unsigned long)&_estack),	
    // (intfunc)((unsigned long)&_ld_stack_address), //the stack pointer after relocation flass 영역에 위치한 링크 스크립트 가르치는 것이다. data section을 가르치는 것?
    Reset_Handler,						//  2.Reset Handler
	NMI_Handler,						//  3.NMI Handler
	HardFault_Handler,					//  4.Hard Fault Handler
	MemManage_Handler,					//  5.MPU Fault Handler
	BusFault_Handler,					//  6.Bus Fault Handler
	UsageFault_Handler,					//  7.Usage Fault Handler
	0,									//  8.Reserved
	0,									//  9.Reserved
	0,									// 10.Reserved
	0,									// 11.Reserved
	SVC_Handler,						// 12.SVCall Handler
	DebugMon_Handler,					// 13.Debug Monitor Handler
	0,									// 14.Reserved
	PendSV_Handler,						// 15.PendSV Handler
	SysTick_Handler,					// 16.SysTick Handler
	// External Interrupts //
	WWDG_IRQHandler,					//  1.Window Watchdog
	PVD_IRQHandler,						//  2.PVD through EXTI Line detect
	TAMPER_IRQHandler,					//  3.Tamper
	RTC_IRQHandler,						//  4.RTC
	FLASH_IRQHandler,					//  5.Flash
	RCC_IRQHandler,						//  6.RCC
	EXTI0_IRQHandler,					//  7.EXTI Line 0
	EXTI1_IRQHandler,					//  8.EXTI Line 1
	EXTI2_IRQHandler,					//  9.EXTI Line 2
	EXTI3_IRQHandler, 					// 10.EXTI Line 3
	EXTI4_IRQHandler,					// 11.EXTI Line 4
	DMA1_Channel1_IRQHandler,			// 12.DMA1 Channel 1
	DMA1_Channel2_IRQHandler,			// 13.DMA1 Channel 2
	DMA1_Channel3_IRQHandler,			// 14.DMA1 Channel 3
	DMA1_Channel4_IRQHandler,			// 15.DMA1 Channel 4
	DMA1_Channel5_IRQHandler,			// 16.DMA1 Channel 5
	DMA1_Channel6_IRQHandler,			// 17.DMA1 Channel 6
	DMA1_Channel7_IRQHandler,			// 18.DMA1 Channel 7
	ADC1_2_IRQHandler,					// 19.ADC1 & ADC2
	USB_HP_CAN1_TX_IRQHandler,			// 20.USB High Priority or CAN1 TX
	USB_LP_CAN1_RX0_IRQHandler,			// 21.USB Low  Priority or CAN1 RX
	CAN1_RX1_IRQHandler,				// 22.CAN1 RX1
	CAN1_SCE_IRQHandler,				// 23.CAN1 SCE
	EXTI9_5_IRQHandler,					// 24.EXTI Line 9..5
	TIM1_BRK_IRQHandler,				// 25.TIM1 Break
	TIM1_UP_IRQHandler,					// 26.TIM1 Update
	TIM1_TRG_COM_IRQHandler,			// 27.TIM1 Trigger and Commutation
	TIM1_CC_IRQHandler,					// 28.TIM1 Capture Compare
	TIM2_IRQHandler,					// 29.TIM2
	TIM3_IRQHandler,					// 30.TIM3
	TIM4_IRQHandler,		 			// 31.TIM4
	I2C1_EV_IRQHandler,					// 32.I2C1 Event
	I2C1_ER_IRQHandler,					// 33.I2C1 Error
	I2C2_EV_IRQHandler,					// 34.I2C2 Event
	I2C2_ER_IRQHandler,					// 35.I2C2 Error
	SPI1_IRQHandler,					// 36.SPI1
	SPI2_IRQHandler,					// 37.SPI2
	USART1_IRQHandler,					// 38.USART1
	USART2_IRQHandler,					// 39.USART2
	USART3_IRQHandler,					// 40.USART3
	EXTI15_10_IRQHandler,				// 41.EXTI Line 15..10
	RTCAlarm_IRQHandler,				// 42.RTC Alarm through EXTI Line
	USBWakeUp_IRQHandler,				// 43.USB Wakeup from suspend
	0,0,0,0,0,0,0,						// 44.,45.,46.,47.,48.,49.

//	(intfunc)0xF108F85F					// @0x108.ThisisforbootinRAMmodeforSTM32F10xMediumDensity devices.
};

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called.
 * @param  None
 * @retval : None
*/

void Reset_Handler(void)
{

      
	/* Zero fill the bss segment.  This is done with inline assembly since this
	   will clear the value of pulDest if it is not kept in a register. */
		unsigned long *pulSrc, *pulDest;	
	
		// Copy the data segment initializers from flash to SRAM
	pulSrc = &_sidata;

	for(pulDest = &_sdata; pulDest < &_edata; )
	{
		*(pulDest++) = *(pulSrc++);
	}
		__asm("  ldr     r0, =_sbss\n"
          "  ldr     r1, =_ebss\n"
          "  mov     r2, #0\n"
          "  .thumb_func\n"
          "zero_loop:\n"
          "    cmp     r0, r1\n"
          "    it      lt\n"
          "    strlt   r2, [r0], #4\n"
          "    blt     zero_loop");
        	
	
  
    main(); //jump main function

    #if 0

        printf("failed load ..");

    #endif

}



// =======================================================================================================
//	Provide weak aliases for each Exception handler to the Default_Handler.
//	As they are weak aliases, any function with the same name will override this definition.
// =======================================================================================================
#pragma weak MMI_Handler = Default_Handler
#pragma weak MemManage_Handler = Default_Handler
#pragma weak BusFault_Handler = Default_Handler
#pragma weak UsageFault_Handler = Default_Handler
#pragma weak SVC_Handler = Default_Handler
#pragma weak DebugMon_Handler = Default_Handler
#pragma weak PendSV_Handler = Default_Handler
#pragma weak SysTick_Handler = Default_Handler
#pragma weak WWDG_IRQHandler = Default_Handler
#pragma weak PVD_IRQHandler = Default_Handler
#pragma weak TAMPER_IRQHandler = Default_Handler
#pragma weak RTC_IRQHandler = Default_Handler
#pragma weak FLASH_IRQHandler = Default_Handler
#pragma weak RCC_IRQHandler = Default_Handler
#pragma weak EXTI0_IRQHandler = Default_Handler
#pragma weak EXTI1_IRQHandler = Default_Handler
#pragma weak EXTI2_IRQHandler = Default_Handler
#pragma weak EXTI3_IRQHandler = Default_Handler
#pragma weak EXTI4_IRQHandler = Default_Handler
#pragma weak DMA1_Channel1_IRQHandler = Default_Handler
#pragma weak DMA1_Channel2_IRQHandler = Default_Handler
#pragma weak DMA1_Channel3_IRQHandler = Default_Handler
#pragma weak DMA1_Channel4_IRQHandler = Default_Handler
#pragma weak DMA1_Channel5_IRQHandler = Default_Handler
#pragma weak DMA1_Channel6_IRQHandler = Default_Handler
#pragma weak DMA1_Channel7_IRQHandler = Default_Handler
#pragma weak ADC1_2_IRQHandler = Default_Handler
#pragma weak USB_HP_CAN1_TX_IRQHandler = Default_Handler
#pragma weak USB_LP_CAN1_RX0_IRQHandler = Default_Handler
#pragma weak CAN1_RX1_IRQHandler = Default_Handler
#pragma weak CAN1_SCE_IRQHandler = Default_Handler
#pragma weak EXTI9_5_IRQHandler = Default_Handler
#pragma weak TIM1_BRK_IRQHandler = Default_Handler
#pragma weak TIM1_UP_IRQHandler = Default_Handler
#pragma weak TIM1_TRG_COM_IRQHandler = Default_Handler
#pragma weak TIM1_CC_IRQHandler = Default_Handler
#pragma weak TIM2_IRQHandler = Default_Handler
#pragma weak TIM3_IRQHandler = Default_Handler
#pragma weak TIM4_IRQHandler = Default_Handler
#pragma weak I2C1_EV_IRQHandler = Default_Handler
#pragma weak I2C1_ER_IRQHandler = Default_Handler
#pragma weak I2C2_EV_IRQHandler = Default_Handler
#pragma weak I2C2_ER_IRQHandler = Default_Handler
#pragma weak SPI1_IRQHandler = Default_Handler
#pragma weak SPI2_IRQHandler = Default_Handler
#pragma weak USART1_IRQHandler = Default_Handler
#pragma weak USART2_IRQHandler = Default_Handler
#pragma weak USART3_IRQHandler = Default_Handler
#pragma weak EXTI15_10_IRQHandler = Default_Handler
#pragma weak RTCAlarm_IRQHandler = Default_Handler
#pragma weak USBWakeUp_IRQHandler = Default_Handler
#pragma weak SPI3_IRQHandler = Default_Handler


// =======================================================================================================
//	This is the code that gets called when the processor receives an unexpected interrupt. 
//	This simply enters an infinite loop, preserving the system state for examination by a debugger.
// =======================================================================================================

void Default_Handler(void)
{
	/* Go into an infinite loop. */
	while (1)
	{
	}
}
