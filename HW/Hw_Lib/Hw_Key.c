#define HW_KEY_LOCAL

#include "Hw_Key.h"


KEY_DEF void KEY_Init(void);
KEY_DEF void KEY_Test(void);



KEY_DEF void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_KEY1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIO_KEY, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_KEY2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIO_KEY, &GPIO_InitStructure);
}

KEY_DEF void KEY_Test(void)
{
    uint32_t i = 0;
    Led_Init();
    
    while(1)
    {
        Hw_1_second();
        if((i++ & 0x1) == 0x0)
        {
            Blue_On();
        }
        else
        {
            Blue_Off();
        }
        if(GPIO_ReadInputDataBit(GPIO_KEY, GPIO_KEY1_PIN) == Bit_SET)
        {
            Red_On();
        }
        else
        {
            Red_Off();
        }
        if(GPIO_ReadInputDataBit(GPIO_KEY, GPIO_KEY2_PIN) == Bit_SET)
        {
            Yellow_On();
        }
        else
        {
            Yellow_Off();
        }
    }
}
