/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月26日 星期二 11时05分27秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(void)
{
    char *p ={"We Are Family!"};
    char a[20];
    char *p1 = a;
    int len,i,j;

    len = (int)strlen(p);

    for(i = 0,j = 0; i < len ;++i)
    {
        if(*(p + i) != ' ')
        {
            *(p1 + j) = * (p + i);
            printf("%c",*(p1 + j));
            j++;
        }
    }

    return 0;
}
