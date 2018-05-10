#ifndef __LED_COMMAND_H__
#define __LED_COMMAND_H__

#include "menu.h"

#ifdef LED_COMMAND_LOCAL
#define LED_COMMAND_DEF
#else
#define LED_COMMAND_DEF             extern
#endif

LED_COMMAND_DEF int command_led_main(int argc, char **argv);
LED_COMMAND_DEF int command_led_main_menu(void);


#endif
