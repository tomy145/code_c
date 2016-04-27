/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月26日 星期二 10时39分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(void)
{
    char ch[26] = {0};
    char * p = ch;
    int i,j;

    srand((int)time(NULL));
    while(strlen(p) != 26)
    {
       i = rand() % 26;
        *(p + i) = i + 'a';
       // printf("%lu\t,%d\t,%c\n",strlen(p),i,*(p+i));
    }

    for(j = 0; j < 26;++j)
    {
        printf("%c\n",*(p + j));
    }

    return 0;

}
