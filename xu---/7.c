/*************************************************************************
> File Name: 7.c
> Author: 
> Mail: 
> Created Time: 2016年04月26日 星期二 12时29分18秒
************************************************************************/

#include<stdio.h>
#include<string.h>

int main(void)
{
    char input[256];
    char *p = input;
    char *p1 = input;
    int count = 0,lenth = 0,best = 0,i =0,len,j = 0;

    gets(p);
    len = (int)strlen(p);

    while(strchr(p1,' ') != NULL)
    {
        p1 = strchr(p1,' ');
        p1++;
        count++;
    }
    for(i = 0;i < count;++i)
    {
        if(i == 0)
             strtok(p," ");
        else 
            strtok(NULL," ");
    }

    for(j = 0;j < len;++j)
    {
        if(*(p + j) != 0)
        {
            lenth++;
            if(best < lenth)
            best = lenth;

        }else 
        {
            lenth = 0;
        }
    }
    printf("the best is %d\n",best);
}
