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
    char *token = strtok(str, " ");
    int *lenP = (int *)calloc(strlen(str), sizeof(int));
    int i = 0;
    while(token)
    {
        ++i;
        lenP[i] = (int)strlen(token);
        puts(token);
        token = strtok(NULL, " ");
        puts(token);
    }

    int max = lenP[0];

    int j = 0;

    for (j = 0;j < strlen(str); j++)
    {
        if (max < lenP[j])
        {
            max = lenP[j];
        }
    }

    printf("最长的是--- %d\n",max);

    free(str);
    free(token);
    free(lenP);






       return 0;
}
