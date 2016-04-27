/*************************************************************************
> File Name: 1.c
> Author: 
> Mail: 
> Created Time: 2016年04月26日 星期二 09时22分50秒
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int a[10];
    int *p =a;
    int i;

    srand((int)time(NULL));
    for(i = 0;i < 10;++i)
    {
        a[i] = rand() % 100;
        printf("%d\n",a[i]);
    }

    for(i = 9;i >= 0;--i)
    {
        printf("%d\n",*(p+i));
    }

    return 0;
}
