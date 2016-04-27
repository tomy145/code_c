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

#define kCharacterSize 26
/**
 *  检查字符是否在数组里面
 *
 *  @param arr 数组
 *  @param c   字符
 *
 *  @return 1 存在 ，0 不存在
 */
int checkChar(char *arr,char c)
{
    int i = 0;
    int isExit = 0;

    for (i = 0; i < 26; i++)
    {
        if (arr[i] == c)
        {
            isExit = 1;
            break;
        }
    }

    return  isExit;
}

/**
 *  打印字符数组
 *
 *  @param arr 字符数组
 */
void printCharArr(char *arr)
{
    int i = 0;
    for (i = 0; i < 26; i++)
    {
        printf("--- %c\n",arr[i]);
    }
}

/**
 *  排序
 *
 *  @param a 字符数组
 *  @param n 长度
 */
void sort(char *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for(int j = 1; j < n - i; ++j)
        {
            if(a[j] < a[j - 1])
            {
                char temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}



int main(int argc, const char * argv[])
{

    unsigned int  ts = (unsigned int)time(NULL);
    srand(ts);
    char *p = (char *)calloc(kCharacterSize, sizeof(char));
    int charArraySize = 0;

    do
    {
        char c = rand()%26 + 97;
        if (0 == (checkChar(p,c)))
        {
            p[charArraySize] = c;
            ++charArraySize;
        }

        printf("--%c -- \n",c);

    }while (!(charArraySize == 26));
    sort(p, 26);
    printCharArr(p);
    free(p);

    return 0;
}
