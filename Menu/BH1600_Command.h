#ifndef __BH1600_H_
#define __BH1600_H_

#include "menu.h"


#ifdef BH1600_COMMAND_LOCAL
#define BH1600_COMMAND_DEF
#else
#define BH1600_COMMAND_DEF             extern
#endif

BH1600_COMMAND_DEF void command_BH1600_main(int argc, char **argv);
BH1600_COMMAND_DEF void command_BH1600_main_menu(void);



#endif // ! __BH1600_H_
