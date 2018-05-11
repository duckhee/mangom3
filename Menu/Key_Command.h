#ifndef __KEY_COMMAND_H__
#define __KEY_COMMAND_H__


#include "menu.h"



#ifdef KEY_COMMAND_LOCAL
#define KEY_COMMAND_DEF
#else
#define KEY_COMMAND_DEF            extern
#endif


KEY_COMMAND_DEF void command_key_main(int argc , char **argv);
KEY_COMMAND_DEF void command_key_main_menu(void);

#endif