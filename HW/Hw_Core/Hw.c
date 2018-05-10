#define HW_INIT_LOCAL

#include "Hw.h"


HW_INIT_DEF void HW_Init(void);

HW_INIT_DEF void HW_Init(void)
{
    HSI_Init();
}