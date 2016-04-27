//
//  main.c
//  1
//
//  Created by Mac on 16/4/26.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>





int main(int argc, const char * argv[])
{

    printf("请输入一组字符串:\n");

    char *str = (char *)calloc(INT_MAX, sizeof(char));
    gets(str);

    char sum = 0;

    int len = (int)strlen(str);

    int half = len / 2;

    int i = 0;

    for (i = 0; i < half; i++)
    {
        if (str[i] == str[len - 1 - i])
        {
            sum += 1;
        }
    }

    if (sum == half)
    {
        printf("您输入的是回文\n");
    }
    else
    {
        printf("您输入的不是回文!\n");
    }

    free(str);



       return 0;
}
