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





int main(int argc, const char * argv[])
{
    char input[] = "We Are Family!";
    char *token = strtok(input, " ");
    char *str = calloc(sizeof(input), sizeof(char));

    while(token)
    {
        puts(token);
        str = strcat(str, token);
        token = strtok(NULL, " ");
        puts(token);

    }

    printf("str -- %s\n",str);
    free(str);



       return 0;
}
