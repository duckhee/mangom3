#ifndef __SEG_COMMAND_H__
#define __SEG_COMMAND_H__

#include "menu.h"


#ifdef SEG_COMMAND_LOCAL
#define SEG_COMMAND_DEF
#else
#define SEG_COMMAND_DEF                  extern
#endif

SEG_COMMAND_DEF void command_seg_main(int argc, char **argv);
SEG_COMMAND_DEF void command_seg_main_menu(void);


#endif