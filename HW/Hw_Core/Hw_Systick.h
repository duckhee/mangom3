#ifndef __HW_SYSTICK_H__
#define __HW_SYSTICK_H__

#include "Hw.h"


#define SYSTICK_ENABLE              0                                          /* Config-Bit to start or stop the SysTick Timer                         */
#define SYSTICK_TICKINT             1                                          /* Config-Bit to enable or disable the SysTick interrupt                 */
#define SYSTICK_CLKSOURCE           2                                          /* Clocksource has the offset 2 in SysTick Control and Status Register   */
#define SYSTICK_MAXCOUNT       ((1<<24) -1)                                    /* SysTick MaxCount                                                      */



#ifdef HW_SYSTICK_LOCAL
#define SYSTICK_DEF
#else
#define SYSTICK_DEF                extern
#endif

static __IO uint8_t count_sys = 0;

SYSTICK_DEF uint32_t SysTick_Config(uint32_t ticks);
SYSTICK_DEF void SysTick_Handler(void);

/*

A. LOAD (0xE000 E014)

- 사용자가 설정하는 Timer Period Tick Count로 24Bit 사용가능하다. 즉 최대 값은 0x00FFFFFF 이된다.

Clock값이 72MHz라고 가정하면 233ms가 Timer 만료를 알려주는 최대 주기 시간이 된다.
 

B. VAL (0xE000 E018)

- System Counter의 현재 Tick Count값이다. 앞서 언급한 바와 같이 이 값은 Timer가 Enable 되어 있을 때 계속 증가하며, LOAD와 같은 값을 가지는 순간 Timer 만료 신호가 발생된다.


C. CTRL (0xE000 E010)

- Timer Control Register로 입력 Clock설정, Interrupt 사용 유무, 그리고 Timer의 동작 유무를 Control하며, Timer 만료여부를 확인할 수있는 1 Bit Status값을 가진다.

 - CTRL의 Bit Description


COUNTFLAG (16번째 Bit) : 0으로 되어 있다가 Timer가 만료되면 1로 설정된다. Interrupt를 사용하지 않을 경우 Timer 만료를 확인 할 수 있는 값이다.

CLKSOURCE(3번째 Bit) : Timer의 Tick Count를 증가 시키는 입력 Clock을 AHB 혹은 AHB/8 중에서 선택할 수 있다.

이를 이용하는 이유는 조금 긴시간의 Timer를 동작시키기 위해 사용된다.

72MHz 기준으로 최대값을 설정했을 때 AHB클럭을 사용할 경우 최대시간이 233ms (16777215 / 72000000) 가 된다. 그러나 AHB/8을 사용하면 최대 시간이 1.864s 까지 늘일 수 있다.

TICKINT(2번째 Bit) : Timer 만료시 Interrupt를 발생시킬지 여부를 결정한다. Interrupt를 사용할 경우 Timer 만료시 Vector Handler의 16번째 등록된 SysTick_Handler 함수가 호출된다.

ENABLE(1번째 Bit) : 가장 중요한 Timer 동작을 결정한다.


*/
#endif