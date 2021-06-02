#include "test_lib.h"
#include "test_main.h"

void itoaw(int num, char *str, int radix)
{
    char  string[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* ptr = str;
    int i; int j;
	int value=num;
	if(num<0) num=-num;
    while (num>=radix)
    {
        *ptr++  = string[num % radix];
        num /= radix;
    }
	if (num)
    {
        *ptr++ = string[num];
        *ptr  = '\r';
    }
    int n=j= ptr-str-1;
    for (i=0; i <(ptr - str) / 2; i++)
    {
        int temp = str[i]; str[i]  = str[j]; str[j--] = temp;
    }
	if(value<0)
	{
		for(j=n;j>=0;--j) str[j+1]=str[j];
		str[0]='-';
	}
	str[n+2]='\r';
}
