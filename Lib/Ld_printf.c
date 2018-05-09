

#define LD_PRINTF_LOCAL
#include "Ld_printf.h"

void print_byte(unsigned int c)
{
    if (c == '\n') print_byte('\r');
    while( !((*(volatile unsigned long *) 0x40013800) & 0x80) ) ;
    *(volatile unsigned long *) 0x40013804 = c;
}

LD_PRINTF_DEF char get_byte(void)
{
    while( !((*(volatile unsigned long *) 0x40013800) & 0x20) ) ;
    return (char) *(volatile unsigned long *) 0x40013804;
    
}


void SerialOutputString(const char *s);

void        printf(char *fmt, ...);
static void PrintChar(char *fmt, char c);
static void PrintDec(char *fmt, int value);
static void PrintHex(char *fmt, int value);
static void PrintString(char *fmt, char *cptr);
static int  Power(int num, int cnt);
#define SWAP8(A)                (A)
#define SWAP16(A)                ((((A)&0x00ff)<<8) | ((A)>>8))
#define SWAP32(A)                ((((A)&0x000000ff)<<24) | (((A)&0x0000ff00)<<8) | (((A)&0x00ff0000)>>8) | (((A)&0xff000000)>>24))

typedef int                        bool;
#define        true                        1
#define false                        0


// print in hex value.
// type= 8 : print in format "ff".
// type=16 : print in format "ffff".
// type=32 : print in format "ffffffff".
typedef enum {
        VAR_LONG=32,
        VAR_SHORT=16,
        VAR_CHAR=8
} VAR_TYPE;

typedef char *va_list;
#define va_start(ap, p)                (ap = (char *) (&(p)+1))
#define va_arg(ap, type)        ((type *) (ap += sizeof(type)))[-1]
#define va_end(ap)

// Write a null terminated string to the serial port.
void SerialOutputString(const char *s)
{
        while (*s != 0) 
        {
                print_byte(*s);
                // If \n, also do \r.
                if (*s == '\n') print_byte('\r');
                s++;        
        }
} // SerialOutputString.

// ���ڿ� s1, s2�� ���� len�� ���� �̳����� ��.
// return : 0 : equil                ret : s1 > s2                -ret : s1 < s2
int StrNCmp(char *s1, char *s2, int len){
        int i;


        for(i = 0; i < len; i++){
                if(s1[i] != s2[i])        return ((int)s1[i]) - ((int)s2[i]);
                if(s1[i] == 0)                return 0;
        }
        return 0;
} // StrNCmp.

// ���ڿ� s1, s2�� ��.
// return : 0 : equil                ret : s1 > s2                -ret : s1 < s2
int StrCmp(char *s1, char *s2){
        for (; *s1 && *s2; s1++, s2++){
                if (*s1 != *s2) return ((int)(*s1) - (int)(*s2));
        }
        if (*s1 || *s2) return ((int)(*s1) - (int)(*s2));
        return 0;
}        // StrCmp.

// ���� : 10���� ���ڿ� s���� ������ ����� retval�� ����Ű�� ��ġ�� ���.
// �Ű� : s      : ��ȯ�� ���ڿ��� �ּ�.
//        retval : ��ȯ�� ���� ��ϵ� �ּ�.
// ��ȯ : return : 1 : success                0 : failure.
// ���� :
int DecToLong(char *s, long *retval){
        long remainder;
        if (!s || !s[0]) return false;


        for (*retval=0; *s; s++){
                if (*s < '0' || *s > '9') return false;
                remainder = *s - '0';
                *retval = *retval * 10 + remainder;
        }


        return true;
}        // DecToLong.

// ���� : printf() �� �Ϻθ� �����ϰ� ����.
// �Ű� : fmt : printf()�� �����ϳ� "%s", "%c", "%d", "%x" ��� ����.
//              %d, %x�� ��쿡�� "%08x", "%8x"�� ���� ��Ÿ�� ���̿� �� ������ 0���� ä���� ���� ����.
// ��ȯ : ����.
// ���� : ����.
LD_PRINTF_DEF void printf(char *fmt, ...)
{
        int                i;
        va_list args;
        char        *s=fmt;
        char        format[10];        // fmt�� ���ڰ� "%08lx"���, "08l"�� �ӽ÷� ���.
        
        va_start(args, fmt);
        while (*s){
                if (*s=='%'){
                        s++;
                        // s���� "%08lx"������ ������ format�� ���. ���߿� ����Լ��� �Ѱ���.
                        format[0] = '%';
                        for (i=1; i<10;){
                                if (*s=='c' || *s=='d' || *s=='x' || *s=='s' || *s=='%'){
                                        format[i++] = *s;
                                        format[i] = '\0';
                                        break;
                                }
                                else {
                                        format[i++] = *s++;
                                }
                        }
                        // "%s", "%c", "%d", "%x"�� ã�� ����� �Լ� ȣ��.
                        switch (*s++){
                                case 'c' :
                                        PrintChar(format, va_arg(args, int));
                                        break;
                                case 'd' :
                                        PrintDec(format, va_arg(args, int));
                                        break;
                                case 'x' :
                                        PrintHex(format, va_arg(args, int));
                                        break;
                                case 's' :
                                        PrintString(format, va_arg(args, char *));
                                        break;
                                case '%' :
                                        PrintChar("%c", '%');
                                        break;
                        }
                }
                else {
                        PrintChar("%c", *s);
                        s++;
                }
        }
        va_end(args);
        return;
}

void PrintChar(char *fmt, char c)
{
        print_byte(c);
        return;
}

void PrintDec(char *fmt, int l)
{
        int        i, j;
        char        c, *s=fmt, tol[10];
        bool        flag0=false, flagl=false;        // "%08lx"���� '0', 'l'�� ���� ����.
        long        flagcnt=0;                                        // "%08lx"���� "8"�� ã�Ƽ� long������.
        bool        leading_zero=true;                        // long���� data�� ����ϱ� ���� ����.
        long        divisor, result, remainder;


        // fmt�� "%08lx"���� '0', '8', 'l'�� �ؼ�.
        for (i=0; (c=s[i]) != 0; i++){
                if (c=='d') break;
                else if (c>='1' && c<='9'){
                        for (j=0; s[i]>='0' && s[i]<='9'; j++){
                                tol[j] = s[i++];
                        }
                        tol[j] = '\0';
                        i--;
                        DecToLong(tol, &flagcnt);
                }
                else if (c=='0') flag0=true;
                else if (c=='l') flagl=true;
                else continue;
        }


        // ���� flag�� ���� ���.
        if (flagcnt){
                if (flagcnt>9) flagcnt=9;
                remainder = l%(Power(10, flagcnt));        // flagcnt���� ���ڸ��� ���� �ɷ���. 199�� flagcnt==2�̸�, 99��.


                for (divisor=Power(10, flagcnt-1); divisor>0; divisor/=10){
                        result = remainder/divisor;
                        remainder %= divisor;


                        if (result!=0 || divisor==1) leading_zero = false;


                        if (leading_zero==true){
                                if (flag0)        print_byte('0');
                                else                print_byte(' ');
                        }
                        else print_byte((char)(result)+'0');
                }
        } else {
                remainder = l;


                for (divisor=1000000000; divisor>0; divisor/=10){
                        result = remainder/divisor;
                        remainder %= divisor;


                        if (result!=0 || divisor==1) leading_zero = false;
                        if (leading_zero==false) print_byte((char)(result)+'0');
                }
        }
        return;
}

void PrintHex(char *fmt, int l){
        int                i, j;
        char        c, *s=fmt, tol[10];
        bool        flag0=false, flagl=false;        // flags.
        long        flagcnt=0;
        bool        leading_zero=true;
        char        uHex, lHex;
        int                cnt;                                                // "%5x"�� ��� 5���� ����ϵ��� ����� ����.


        // fmt�� "%08lx"���� '0', '8', 'l'�� �ؼ�.
        for (i=0; (c=s[i]) != 0; i++){
                if (c=='x') break;
                else if (c>='1' && c<='9'){
                        for (j=0; s[i]>='0' && s[i]<='9'; j++){
                                tol[j] = s[i++];
                        }
                        tol[j] = '\0';
                        i--;
                        DecToLong(tol, &flagcnt);
                }
                else if (c=='0') flag0=true;
                else if (c=='l') flagl=true;
                else continue;
        }


        s = (char *)(&l);
        l = SWAP32(l);                // little, big endian�� ����.(big�� ����ϱ� ���� ������ �ٲ�)
        
        // ���� flag�� ���� ���.
        if (flagcnt){
                if (flagcnt&0x01){        // flagcnt�� Ȧ�� �϶�, upper�� ����, lower�� ���.
                        c = s[(8-(flagcnt+1))/2]; // Ȧ�� �϶� �� ��ġ�� �����ϴ� ���� ���� ���� �ɴϴ�.
                        
                        // lower 4 bits�� �����ͼ� ascii code��.
                        lHex = ((c>>0)&0x0f);
                        if (lHex!=0) leading_zero=false;
                        if (lHex<10) lHex+='0';
                        else         lHex+='A'-10;


                        // lower 4 bits ���.
                        if (leading_zero){
                                if (flag0) print_byte('0');
                                else       print_byte(' ');
                        }
                        else print_byte(lHex);
                        
                        flagcnt--;
                }


                // byte������ data�� Hex�� ���.
                for (cnt=0, i=(8-flagcnt)/2; i<4; i++){
                        c = s[i];
                                
                        // get upper 4 bits and lower 4 bits.
                        uHex = ((c>>4)&0x0f);
                        lHex = ((c>>0)&0x0f);


                        // upper 4 bits and lower 4 bits to '0'~'9', 'A'~'F'.
                        // upper 4 bits�� ascii code��.
                        if (uHex!=0) leading_zero = false;
                        if (uHex<10) uHex+='0';
                        else         uHex+='A'-10;


                        // upper 4 bits ���.
                        if (leading_zero){
                                if (flag0) print_byte('0');
                                else       print_byte(' ');
                        }
                        else print_byte(uHex);
                        
                        // lower 4 bits�� ascii code��.
                        if (lHex!=0) leading_zero = false;
                        if (lHex<10) lHex+='0';
                        else         lHex+='A'-10;


                        // lower 4 bits ���.
                        if (leading_zero){
                                if (flag0) print_byte('0');
                                else       print_byte(' ');
                        }
                        else print_byte(lHex);
                }
        }
        else {
                for (i=0; i<4; i++){
                        c = s[i];
        
                        // get upper 4 bits and lower 4 bits.
                        uHex = ((c>>4)&0x0f);
                        lHex = ((c>>0)&0x0f);


                        // upper 4 bits and lower 4 bits to '0'~'9', 'A'~'F'.
                        if (uHex!=0) leading_zero = false;
                        if (uHex<10) uHex+='0';
                        else         uHex+='A'-10;
                        if (!leading_zero) print_byte(uHex);
                        
                        if (lHex!=0 || i==3) leading_zero = false;
                        if (lHex<10) lHex+='0';
                        else         lHex+='A'-10;
                        if (!leading_zero) print_byte(lHex);
                }
        }
        return;
}

void PrintString(char *fmt, char *s){
        if (!fmt || !s) return;
        while (*s) print_byte(*s++);
        return;
}

int Power(int num, int cnt){
        long retval=num;
        cnt--;


        while (cnt--){
                retval *= num;
        }
        return retval;
} 

