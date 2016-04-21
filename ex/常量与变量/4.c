/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 一  4/18 17:45:59 2016
 ************************************************************************/

#include<stdio.h>

 

char is_leap_year(unsigned int year)
{

    if((((0 == (year % 4))) && ((0 != (year % 100)))) || (0 == (year % 400)))
    {
           printf("输入的year = %d是闰年 \n",year);
           return 1;
    }
    else
    {
        printf("输入的year = %d 不是闰年\n",year);
        return 0 ;
    }
}

int main(void)
{

    unsigned int year = 0;
    printf("请输入年:xxxx\n");
    scanf("%d",&year);
    char isYear = is_leap_year(year);
    
    printf("isYear = %d\n", isYear);

    printf("打印 1900 - 2100 有多少个闰年 \n");

    for (int i = 1900; i < 2101; i++)
    {
        is_leap_year(i);
    }
    
    return 0 ;
}
