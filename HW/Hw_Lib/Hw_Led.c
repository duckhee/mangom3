#define HW_LED_LOCAL

#include "Hw_Led.h"


HW_LED_DEF void Led_Init(void);
HW_LED_DEF void Led_AllOn(void);
HW_LED_DEF void Led_AllOff(void);
HW_LED_DEF void Red_On(void);
HW_LED_DEF void Red_Off(void);
HW_LED_DEF void Yellow_On(void);
HW_LED_DEF void Yellow_Off(void);
HW_LED_DEF void Blue_On(void);
HW_LED_DEF void Blue_Off(void);
HW_LED_DEF void Test_LED(void);
HW_LED_DEF void TEST_Check(void);
HW_LED_DEF void LED_MULT(uint32_t count);




HW_LED_DEF void Led_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = HW_LED_RED | HW_LED_YELLOW | HW_LED_BLUE;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(HW_LED_PORT, &GPIO_InitStructure);

    Led_AllOff();
}

HW_LED_DEF void Led_AllOn(void)
{
    Red_On();
    Yellow_On();
    Blue_On();
}

HW_LED_DEF void Led_AllOff(void)
{
    Red_Off();
    Yellow_Off();
    Blue_Off();
}

HW_LED_DEF void Red_On(void)
{
    HW_LED_PORT->BRR |= HW_LED_RED;
}

HW_LED_DEF void Red_Off(void)
{
    HW_LED_PORT->BSRR |= HW_LED_RED;
}

HW_LED_DEF void Yellow_On(void)
{
    HW_LED_PORT->BRR |= HW_LED_YELLOW;
}

HW_LED_DEF void Yellow_Off(void)
{
    HW_LED_PORT->BSRR |= HW_LED_YELLOW;
}

HW_LED_DEF void Blue_On(void)
{
    HW_LED_PORT->BRR |= HW_LED_BLUE;
}

HW_LED_DEF void Blue_Off(void)
{
    HW_LED_PORT->BSRR |= HW_LED_BLUE;
}

HW_LED_DEF void Test_LED(void)
{
    #if 0
        Led_AllOn();
        Hw_1_second();
        Led_AllOff();
        Hw_1_second();
        Led_AllOn();
    #else
        LED_MULT(30);
        Led_AllOff();
    #endif
}

HW_LED_DEF void LED_MULT(uint32_t count)
{
    for(;count > 0; count--)
    {
        Red_Off();
        Yellow_On();
        Blue_On();
        Hw_1_second();

        Red_On();
        Yellow_Off();
        Blue_On();
        Hw_1_second();

        Red_On();
        Yellow_On();
        Blue_Off();
        Hw_1_second();
        
    }
}

HW_LED_DEF void TEST_Check(void)
{

}
