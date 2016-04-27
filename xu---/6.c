/*************************************************************************
	> File Name: 6.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月26日 星期二 11时44分16秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(void)
{
    char a[256],b[50] = {0};
    char * p = a;
    char *p1 = b;
    int len,i,j = 0;

    gets(p);
  //  puts(p);
    len = (int) strlen(p);
    for(i = 0;i < len;++i)
    {
        if((*(p + i) >= 'A')&&(*(p + i) <= 'Z'))
        {
            j = *(p + i) -'A';
            *(p1 + j) = *(p + i);
        }else if((*(p + i) >= 65)||(*(p + i) <= 90))
        {
            j = *(p + i) - 'a' + 25;
            *(p1 + j) = *(p + i);
        }

    }
    for(j = 0; j < 50;++j)
    {
            printf("%c",*(p1 + j));
    }

    printf("\n");
    return 0;
}
