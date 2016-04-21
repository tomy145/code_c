/*************************************************************************
	> File Name: sum100.c
	> Author: 
	> Mail: 
	> Created Time: 三  4/20 10:47:29 2016
 ************************************************************************/

#include<stdio.h>

int main(void)
{
    int sum = 0;
    for(int i = 1; i <= 100 ; i++)
    {
        sum += i;
        printf("sum -- %d,  i -- %d\n",i,sum);
    }
    return 0;
}
