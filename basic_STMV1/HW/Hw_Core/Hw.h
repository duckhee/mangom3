#ifndef __HW_H__
#define __HW_H__




#ifdef HW_LOCJAL
#deifne HW_DEF
#else
#define HW_DEF        extern
#endif


HW_DEF void Hw_Init(void);




#endif