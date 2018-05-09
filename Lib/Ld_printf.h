#ifndef __LD_PRINTF_H__
#define __LD_PRINTF_H__

#include "Hw.h"

#ifdef LD_PRINTF_LOCAL
#define LD_PRINTF_DEF
#else
#define LD_PRINTF_DEF                extern
#endif

LD_PRINTF_DEF void printf(char *fmt, ...);
LD_PRINTF_DEF char check_byte(char *key);
LD_PRINTF_DEF char get_byte(void);



#endif