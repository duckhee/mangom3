#define HW_SEGMENT_LOCAL

#include "Hw_Segment.h"



SEG_DEF void Power_SEG_On(void);
SEG_DEF void Power_SEG_Off(void);
SEG_DEF void On_7SEG_OnePin(uint16_t PinNum);
SEG_DEF void Off_7SEG_OnePin(uint16_t PinNum);
SEG_DEF void All_7SEG_On(void);
SEG_DEF void All_7SEG_Off(void);
SEG_DEF void Output_7SEG_Number(unsigned int Num);
SEG_DEF void Seven_SEG_TEST(void);


SEG_DEF void Power_SEG_On(void)
{
    GPIO_7_SEG->BRR |= GPIO_7_SEG_POWER_PIN;
}

SEG_DEF void Power_SEG_Off(void)
{
    GPIO_7_SEG->BSRR |= GPIO_7_SEG_POWER_PIN;
}

SEG_DEF void On_7SEG_OnePin(uint16_t PinNum)
{
    GPIO_7_SEG->BRR |= PinNum;
}

SEG_DEF void Off_7SEG_OnePin(uint16_t PinNum)
{
    GPIO_7_SEG->BSRR |= PinNum;
}

SEG_DEF void All_7SEG_On(void)
{
    On_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_F_PIN |GPIO_7_SEG_E_PIN | GPIO_7_SEG_G_PIN | GPIO_7_SEG_DP_PIN);
}

SEG_DEF void All_7SEG_Off(void)
{
        Off_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN | GPIO_7_SEG_DP_PIN);
}

SEG_DEF void Output_7SEG_Number(unsigned int Num)
{
    All_7SEG_Off();
    switch(Num)
    {
        case 0:
            On_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_G_PIN);
        break;
        case 1:
            On_7SEG_OnePin(GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN);
        break;
        case 2:
            On_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_G_PIN);
        break;
        case 3:
            On_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_G_PIN);
        break;
        case 4:
            On_7SEG_OnePin(GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;
        case 5:
            On_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;
        case 6:
            On_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;
        case 7:
            On_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_F_PIN);
        break;
        case 8:
            On_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;
        case 9:
            On_7SEG_OnePin(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;
        default:
            printf("not number\n");
        break;
    }
}
SEG_DEF void Seven_SEG_TEST(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    int i;
    printf("Seven Segment Test\n");
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_7_SEG_POWER_PIN | GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN |GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_F_PIN |GPIO_7_SEG_G_PIN | GPIO_7_SEG_DP_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIO_7_SEG, &GPIO_InitStructure);

    Power_SEG_On();
    Hw_1_second();

    All_7SEG_Off();
    On_7SEG_OnePin(GPIO_7_SEG_A_PIN);
    Hw_1_second();
    On_7SEG_OnePin(GPIO_7_SEG_B_PIN);
    Hw_1_second();
    On_7SEG_OnePin(GPIO_7_SEG_C_PIN);
    Hw_1_second();
    On_7SEG_OnePin(GPIO_7_SEG_D_PIN);
    Hw_1_second();
    On_7SEG_OnePin(GPIO_7_SEG_E_PIN);
    Hw_1_second();
    On_7SEG_OnePin(GPIO_7_SEG_F_PIN);
    Hw_1_second();
    On_7SEG_OnePin(GPIO_7_SEG_G_PIN);
    Hw_1_second();
    On_7SEG_OnePin(GPIO_7_SEG_DP_PIN);
    Hw_1_second();

    for(i = 0; i < 10; i++)
    {
        Output_7SEG_Number(i);
        Hw_1_second();
    }    
}
