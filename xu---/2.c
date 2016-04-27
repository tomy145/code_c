/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月26日 星期二 09时37分14秒
 ************************************************************************/

#include<stdio.h>

int is_leap_year(int year);
int main(void)
{
    unsigned int year,day,day2 = 0,mouth2=0,isleap,i,sum=0;
    unsigned int *p;
    unsigned int mouth_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    unsigned int mouth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    scanf("%d,%d",&year,&day);
    isleap = is_leap_year(year);
    isleap ? (p = mouth_leap) : (p = mouth) ;
    for(i = 0;i < 12;++i)
    {
        sum += *(p + i);
       // printf("%u,%u,%u",sum,i,day);
        if(sum > day)
        {
            mouth2 = (i + 1);
            day2 = day - (sum - *(p + i));
            break;
        }
        if(sum == day)
        {
            mouth2 = (i + 1);
            day2 = 0;
            break;
        }

    }

    printf("the mouth is %u,day is %u\n",mouth2,day2);

    return 0;


}

int is_leap_year(int year)
{
    if(((!(year % 4))&&(year % 100))||(!(year % 400)))
        return 1;
    return 0;
}
