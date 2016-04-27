//
//  main.c
//  1
//
//  Created by Mac on 16/4/26.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define kbool unsigned char
#define true 1
#define false 0

typedef struct {

    int dateCount; //日期数量
    kbool isMaxMonth; //判断是否是大月
    kbool isLeapYear;//判断是否是闰年
    unsigned char numMonth;//第几个月
    unsigned char day;//第几日

}month;

kbool leapYear(int year)
{
    kbool isLeapYear = false;

    if (0 == (year / 400))
    {
        isLeapYear = true;
    }

    return  isLeapYear;
}

int main(int argc, const char * argv[])
{

    unsigned int year = 0 , numberDay = 0; //定义两个变量保存年，和多少天
    printf("请输入年份xxxx,第多少天xxx\n");
    scanf("%u,%u",&year,&numberDay);
    printf("您输入的年份是--- %d, 第多少天--- %d\n",year,numberDay);

    kbool isLeap = leapYear(year);

    month *allMon = calloc(12, sizeof(month));

    int i = 0, j = 0, m = 0, n = 0;

    for (i = 1; i <= 7; i++)
    {
        if (isLeap && 1 == i) //是闰年
        {
            allMon[1].dateCount = 29;
            allMon[1].isLeapYear = isLeap;
            allMon[1].isMaxMonth = 0;
        }
        else if (!isLeap && 2 == i)
        {
            allMon[1].dateCount = 28;
            allMon[1].isLeapYear = isLeap;
            allMon[1].isMaxMonth = 0;
        }
        else
        {
            if (1 == (i % 2))
            {
                allMon[i - 1].dateCount = 31;
                allMon[i - 1].isLeapYear = isLeap;
                allMon[i - 1].isMaxMonth = 0;
            }
            else
            {
                allMon[i - 1].dateCount = 30;
                allMon[i - 1].isLeapYear = isLeap;
                allMon[i - 1].isMaxMonth = 0;
            }
        }

        allMon[i - 1].numMonth = i;
        allMon[i - 1].day = 0;
    }

    for (j = 8; j <= 12; j++)
    {
        if (0 == (j % 2))
        {
            allMon[j-1].dateCount = 31;
            allMon[j-1].isLeapYear = isLeap;
            allMon[j-1].isMaxMonth = 0;
        }
        else
        {
            allMon[j-1].dateCount = 30;
            allMon[j-1].isLeapYear = isLeap;
            allMon[j-1].isMaxMonth = 0;
        }

        allMon[ j - 1 ].numMonth = j;
        allMon[ j - 1 ].day = 0;
    }

    for (m = 0; m <12; m++)
    {
        for (n = 0; n < allMon[m].dateCount;n++)
        {
            numberDay = numberDay - 1;

            if (numberDay == 0)
            {
                printf("第 %d 月-- 第 %d 日 --\n",allMon[m].numMonth,n+1);
            }
        }
    }


    free(allMon);

    return 0;
}
