/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月26日 星期二 11时26分59秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(void)
{
    char a[256];
    char *p = a;
    int len,i,check;

    gets(p);
    len = strlen(p);
    for(i = 0;i < len / 2;++i)
    {
        if(*(p + i) != *(p + len - 1 -i))
        {
            check = 0;
            break;
        } else
            check = 1;
    }
    check ? printf("yes\n") : printf("no\n");
    return 0;
}
