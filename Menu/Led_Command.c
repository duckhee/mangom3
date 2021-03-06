#define LED_COMMAND_LOCAL

#include "Led_Command.h"


LED_COMMAND_DEF int command_led_main(int argc, char **argv);
LED_COMMAND_DEF int command_led_main_menu(void);

static unsigned short flag;

LED_COMMAND_DEF int command_led_main(int argc, char **argv)
{
    int key;

    if(argc > 1)
    {
        if(!StrCmp(argv[0], "ch1"))
        {
            printf("LED command menu ch1\n");
        }
        else if(!StrCmp(argv[1], "ch2"))
        {
            printf("LED command menu ch2\n");
        }
        else if(!StrCmp(argv[1], "on"))
        {
            printf("\nON %s\n", argv[1]);
            if(!StrCmp(argv[2], "ch1"))
            {
                printf("\non argv[2] : %s ch1\n", argv[2]);
            }
            else if(!StrCmp(argv[2], "ch2"))
            {
                printf("\non argv[2] : %s ch2\n", argv[2]);
            }
        }
        else if(!StrCmp(argv[1], "off"))
        {
            printf("\nOFF %s\n", argv[1]);
            if(!StrCmp(argv[2], "ch1"))
            {
                printf("\noff argv[2] : %s ch1\n", argv[2]);
            }
            else if(!StrCmp(argv[2], "ch2"))
            {
                printf("\noff argv[2] : %s ch2\n", argv[2]);
            }
        }
        else if(!StrCmp(argv[1], "state"))
        {
                printf("\nSTATE %s\n", argv[1]);
            if(!StrCmp(argv[2], "ch1"))
            {
                printf("\nstate argv[2] : %s ch1\n", argv[2]);
            }
            else if(!StrCmp(argv[2], "ch2"))
            {
                printf("\nstate argv[2] : %s ch2\n", argv[2]);
            }
        }
        return 0;
    }
    while((key = command_led_main_menu()) != 0)
    {
         switch(key)
        {
            case '1':
                printf("No.1\n");
                Red_On();
            break;

            case '2':
                printf("No.2\n");
                Red_Off();
            break;
            
            case '3':
                printf("No.3\n");
                Yellow_On();
            break;

            case '4':
                printf("No.4\n");
                Yellow_Off();
            break;
              
            case '5':
                printf("No.5\n");
                Blue_On();
            break;

            case '6':
                printf("No.6\n");
                Blue_Off();
            break;

            case '7':
                printf("No.7\n");
                Test_LED();
            break;

            case '8':
                printf("No.8\n");
                System_Information();
            break;

            case '9':
                printf("No.9\n");
                Led_AllOn();
            break;

            case '0':
                printf("No.0\n");
                Led_AllOff();
            break;

            case 'a':
                printf("No.a\n");
            
            break;

            case 'b':
                printf("No.b\n");
              
            break;

            case 'c':
                printf("No.c\n");
            
            break;

            case 'd':
                printf("No.d\n");
        
            break;

            case 'e':
                printf("No.e\n");
     
            break;

            case 'f':
                printf("No.f\n");

            break;

            case 'g':
                printf("No.g\n");
     
            break;

            case 'h':
                printf("No.h\n");
       
            break;

            case 'i':
                printf("No.i\n");

            break;

            case 'j':
                printf("No.j\n");

            break;

            case 'k':
                printf("No.k\n");

            break;

            case 'q':
                return 0;
        }
    }
    return 0;
}
LED_COMMAND_DEF int command_led_main_menu(void)
{
    int key;

    printf("\n\n");
    printf("-------------------------------------------------\n");
    printf("                 LED MAIN MENU\n");
    printf("-------------------------------------------------\n");
    printf(" 1. Red On                                         \n");
    printf(" 2. Red Off                                         \n");
    printf(" 3. Yellow On                                         \n");
    printf(" 4. Yellow Off                                         \n");
    printf(" 5. Blue On                                         \n");
    printf(" 6. Blue Off                                         \n");
    printf(" 7. Led Test                                         \n");
    printf(" 8. System_Information                                         \n");
    printf(" 9. Test                                         \n");
    printf(" 0. Test                                         \n");
    printf("-------------------------------------------------\n");
    printf(" q. LED Menu QUIT\n");
    printf("-------------------------------------------------\n");
    printf("\n\n");

    printf("SELECT THE COMMAND NUMBER : ");
    key=get_byte();
    
    return key;    
}


