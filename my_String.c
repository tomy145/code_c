//
//  my_String.c
//  tempo
//
//  Created by Mac on 16/5/12.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "my_String.h"
#include <assert.h>
#include <stdlib.h>

/**
 *  计算有效字符串长度
 *
 *  @param str 字符串
 *
 *  @return 有效字符串长度
 */
int my_Strlen(char *str)
{
    unsigned int count = 0;
    char *p = str;
    while(*p != '\0')
    {
        p = &str[count];
        count++;
        p++;
    }

    return count;
}

/**
 *  字符串拷贝
 *
 *  @param destStr 目的字符串
 *  @param srcStr  原字符串
 *
 *  @return 拷贝好的字符串
 */
char *my_Strcpy(char *destStr,char *srcStr)
{
    int destStrLen = my_Strlen(destStr);
    int srcStrLen = my_Strlen(srcStr);
    int i = 0;
    for (i = 0; i < srcStrLen; i++)
    {
        //数组越界 ---
        assert(destStr[i + destStrLen] == '\0');
        destStr[i + destStrLen] = srcStr[i];
    }

    return destStr;
}

/**
 *  字符串追加
 *
 *  @param destStr 目标字符串
 *  @param srcStr  原字符串
 *  @param len     长度
 *
 *  @return 追加后的目标字符串
 */
char *my_StrCat(char *destStr , char *srcStr , unsigned int len)
{
    int destStrLen = my_Strlen(destStr);
    int srcStrLen = my_Strlen(srcStr);
    int i = 0;

    for (i = 0; (i < len) && (len < srcStrLen) ; i++)
    {
        //数组越界 ------
        assert(destStr[i + destStrLen] == '\0');
        destStr[i + destStrLen] = srcStr[i];
    }

    return destStr;
}

int my_StrCmp(const char *str1, const char *str2)
{
    int len = 0;

    unsigned int str1Len = my_Strlen((char *)str1);
    unsigned int str2Len = my_Strlen((char *)str2);

    int i = 0 ;
    int j = 0;
    int k = 0;

    //

    if (str1Len > str2Len)
    {
        for (i = 0; i < str2Len; i++)
        {
            int temp = str1[i] - str2[i];
            len += temp;
            if (len > 0)
            {
                len =  1;
            }
            else if (len == 0)
            {
                len = 1;
            }
            else
            {
                len = -1;
            }
        }

    }
    else if(str1Len == str2Len)
    {
        for (k = 0; k < str2Len; k++)
        {
            int temp = str1[k] - str2[k];
            len += temp;
            if (len > 0)
            {
                len =  1;
            }
            else if (len == 0)
            {
                len = 0;
            }
            else
            {
                len = -1;
            }
        }
    }
    else
    {
        for (j = 0; j < str1Len; j++)
        {
            int temp = str1[j] - str2[j];
            len += temp;
            if (len > 0)
            {
                len =  1;
            }
            else if (len == 0)
            {
                len = 1;
            }
            else
            {
                len = -1;
            }
        }
    }


    return len;
}



