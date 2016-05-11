/*************************************************************************
	> File Name: strok.c
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 4 17:03:02 2016
 ************************************************************************/

#include<stdio.h>
#include <string.h>

int main(int argv,const char *argc[])
{
    char bu[] = "When I was yong";
    char *de = " , .";
    char *token = strok(bu,de);

    while(token != NULL)
    {
        token = strok(NULL,de);
        printf("token --- %s\n",token);
    }

    return 0;
}
