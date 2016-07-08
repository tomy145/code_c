//
//  main.c
//  数组习题
//
//  Created by Mac on 16/5/18.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int	searcheKeyTable(const char *table[5],	const int size, const char *key,int	*pos , int w_ch)
{

    int ret = 0;
    int index = -1;

    char **p = calloc(30, sizeof(char*));
    for (int i = 0; i < 30; i++)
    {
        p[i] = calloc(10, sizeof(char));
    }


    int k = 0;

    char row = 0;
    char col = 0;

    for (int i = 0; i < size; i++)
    {
        int len = (int)strlen(table[i]);
        for (int j = 0; j < len; j++)
        {
            row = i;
            printf("tab--- %c\n",table[i][j]);
            if (table[i][j] == w_ch)
            {
                col = j;
                char a[2] = {row + 0x30,0};
                strcat(p[k], a);
                char c[2] = {':',0};
                strcat(p[k], c);
                char b[2] = {col + 0x30,0};
                strncat(p[k], b, 2);
                printf("pk -- %s\n",p[k]);
                k++;
            }
        }
    }

    if (index >= 0)
    {
        ret = 0;
    }


    *pos = index;

    for (int i = 0; i < 30; i++)
    {
        printf("kie---- %s\n",p[i]);
    }

    return  ret;

}



int main(int argc, const char * argv[])
{

    char *	keywords[]	=
    {
        "while",
        "case",
        "static",
        "do",
        "lso"
    };

    char *str = "do";
    int pos = -1;


    searcheKeyTable(keywords, sizeof(keywords) / sizeof(int *), str, &pos,'i');

    printf("str--- %d\n",pos);

    return 0;
}



