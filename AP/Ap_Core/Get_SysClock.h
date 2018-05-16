#ifndef __GET_SYSCLOCK_H__
#define __GET_SYSCLOCK_H__

#include "Ap.h"

#ifdef GET_SYSCLOCK_LOCAL
#define GET_SYSCLOCK_DEF
#else
#define GET_SYSCLOCK_DEF                   extern
#endif

GET_SYSCLOCK_DEF void System_Information(void);


#endif