#define MENU_COMMAND_LOCAL

#include "Menu_Command.h"

#define MAX_ARGS     20

typedef int bool;

#define true         1
#define false        0

#define NULL        ((void*)0)

typedef enum{
    VAR_LONG = 32,
    VAR_SHORT = 16,
    VAR_CHAR = 8
} VAR_TYPE;

char cmd[128];
int cmd_size;

//구조체 선언
struct _CMD_TBL{
    // 예약된 명령어
    char *cmd;
    // 함수 포인터, 이중포인터는 포인터 배열을 가리킨다.
    bool(*run)(struct _CMD_TBL *cptr, int argc, char **argv);
    // 해당되는 명령어의 사용법
    char *usage;
    // 해당되는 명령어의 도움말, 더 자세한 사용법
    char *help;
    char *help_more;
};

//초기화
#define CMD_TBL_TEST                  {"test", do_test, 0, 0, 0}
#define CMD_TBL_HELP                  {"help", do_print_help, 0, 0, 0}
//메뉴 정의 
#define CMD_TBL_LED                   {"led_menu",  do_led,  0, 0, 0}
#define CMD_TBL_KEY                   {"key_menu",  do_key,  0, 0, 0}
#define CMD_TBL_SEG                   {"seg_menu",  do_seg,  0, 0, 0}
#define CMD_TBL_BMA1600               {"bma1600_menu", do_bma1600, 0, 0, 0}
#define CMD_TBL_END                   {0,           0,       0, 0, 0}

//함수 프로토 타입 선언
void display_prompt(char *prompt);
bool do_print_help(int argc, char **argv);
int get_command(char *cmd, int len, int timeout);
int get_args(char *s, char **argv);

//대상이 되는 함수 원형, 구조체 내의 함수의 대상의 원형 선언
bool do_test(struct _CMD_TBL *cptr, int argc, char **argv);
bool do_led(struct _CMD_TBL *cptr, int argc, char **argv);
bool do_key(struct _CMD_TBL *cptr, int argc, char **argv);
bool do_seg(struct _CMD_TBL *cptr, int argc, char **argv);
bool do_bma1600(struct _CMD_TBL *cptr, int argc, char **argv)
//함수 대상 원형

//구조체를 배열로 할당(구조체 배열)
struct _CMD_TBL cmd_tbl[] =
{
    CMD_TBL_TEST,
    CMD_TBL_HELP,
    //추가 시작
    CMD_TBL_LED,
    CMD_TBL_KEY,
    CMD_TBL_SEG,
    CMD_TBL_BMA1600,
    //end는 0으로 되어있고 command에서 cptr이 0이면, for문은 빠져나오게 되어 있다.
    //end 밑에 추가하면 동작이 안된다.
    //추가 끝
    CMD_TBL_END
};



MENU_COMMAND_DEF void command_main(void)
{
    //키보드로 부터 받은 문자열을 저장하는 버퍼 생성
    int argc = 0;
    //문자열을 가르키는 포인터 배열 선언
    char *argv[MAX_ARGS];
    //_CMD_TBL 구조체를 가르키는 포인터 포인터 자신의 메모리를 할당 
    //stack 영역에 자리 잡는다.
    struct _CMD_TBL *cptr = NULL;

    for(;;)
    {
        //프론트를 만든다.
        display_prompt(">>> ");
        //키 입력을 받는다. 3번째 인자 : 최장 대기 시간
        get_command(cmd, 128, 3600);
        //argument를 분류한다. argv는 각가의 인자를 저장하는 포인터 배열로 cmd라는 버퍼에서 인자를 분리해서 argv라는 포인터 배열에 인자를 저장한다.
        if(!cmd || !cmd[0])
        {
            continue;
        }
        //argc는 인자의 갯수 return value는 인자의 갯수
        argc = get_args(cmd, argv);
        //들어온 명령을 받아서 처리하는 루틴 
        //cptr = cmdTbl : 포인터에 구조체 배열명(주소)을 대입 
        //cptrt++ : 다음 구조를 가르치는 것
        for(cptr = cmd_tbl; cptr->cmd; cptr++)
        {
            //argv[0] : arguement를 분리한 첫번째 인자(키보드로 입력된 명령어)
            //cptr->cmd : 예약된 명령어
            if(!StrCmp(argv[0], cptr->cmd))
            {
                //입력된 명령어와 예약된 명령어가 같으면 해당 명령어를 호출한다.
                if(cptr->run != 0)
                {
                    (cptr->run)(cptr, argc, argv);
                    break;
                }
            }
        }
        if(!StrCmp(argv[0], "help") || !StrCmp(argv[0], "?"))
        {
            do_print_help(argc, argv);
        }else if((!cptr->cmd))
        {
            printf("\n\t Unknown Command : %s \n", argv[0]);
        }
        if(!StrCmp(argv[0], "end"))
        {
            break;
        }
    }
}

void display_prompt(char *prompt)
{
    if(prompt == NULL)
    {
        printf(">>> ");
    }
    else
    {
        printf("%s\n", prompt);
    }
}

int get_command(char *cmd, int len, int timeout)
{
    char key;
    int i, rd_cnt, rd_max;
    rd_max = len-1;

    for (rd_cnt = 0, i = 0; rd_cnt < rd_max; )
    {
        key = get_byte();
        if((key == '\r') || (key == '\n'))
        {
            cmd[i++] = '\0';
            printf("\n");
            return rd_cnt;
        }
        else if(key == '\b')
        {
            if(i > 0)
            {
                i--;
                rd_cnt--;
                printf("\b \b");
            }
        }
        else if(key == '\0')
        {
            cmd[cmd_size] = '\0';
            printf("\n");
            return cmd_size;
        }
        else
        {
            cmd[i++] = key;
            rd_cnt++;
            printf("%c", key);
        }

    }
}

int get_args(char *s, char **argv)
{
    int args = 0;
    if(!s || *s == '\0')
    {
        return 0;
    }
     while (args < MAX_ARGS)
    {
        while ((*s == ' ') || (*s == '\t'))
        {
            s++;
        }

        if (*s == '\0')
        {
            argv[args] = 0;
            return args;
        }
        argv[args++]=s;
        while (*s && (*s != ' ') && (*s  != '\t'))
        {
            s++;
        }
        if (*s == '\0')
        {
            argv[args] = 0;
            return args;
        }
        *s++='\0';
    }
    return args;
}

bool do_print_help(int argc, char **argv)
{
    struct _CMD_TBL *cptr;

    if(argc == 1)
    {
        printf("\nThe following command are supported : \n");
        printf("Help : Help for commands. \n");

        for(cptr = cmd_tbl; cptr->cmd; cptr++)
        {
            if(cptr->help_more)
            {
                printf(cptr->help_more);
            }
        }
        printf("\n\n");
    }
    else
    {
        printf("\n\t Unknow command : %s\n", argv[0]);
    }

    return true;
}

bool do_test(struct _CMD_TBL *cptr, int argc, char **argv)
{
    printf("\nThis is test\n");
    return true;
}

bool do_led(struct _CMD_TBL *cptr, int argc, char **argv)
{
    printf("\nThis is led test\n");
    command_led_main(argc, argv);
    return true;
}

bool do_key(struct _CMD_TBL *cptr, int argc, char **argv)
{
    printf("\nThis is key test\n");
    command_key_main(argc, argv);
    return true;
}

bool do_seg(struct _CMD_TBL *cptr, int argc, char **argv)
{
    printf("\nThis is seg test\n");
    command_seg_main(argc, argv);
    return true;
}

bool do_bma1600(struct _CMD_TBL *cptr, int argc, char **argv)
{
    printf("\nThis is BMA1600 test\n");
    return true;
}