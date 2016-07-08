//
//  main2.c
//  tempo
//
//  Created by Mac on 16/5/12.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"





int main(int argc, const char * argv[])
{

	printf("list -- %d\n",sizeof(Data));
    srand((unsigned int)time(NULL));
    int len = 3;
    Data *data = creatList(len);
    for (int i = 0; i < len; i++)
    {
        int temp = rand();
        printf("temp --- %d --- %d\n",temp,i);
        int *p = calloc(1, sizeof(temp));
        *p = temp;
        insertListToIndex(data, i, p, sizeof(int));
        free(p);
        printf("lll -- %d\n",*(int*)data[i].data);
        
    }

    Data d2 = data[1];

    printf("d2 -- %d\n",*(int*)d2.data);

    data = deleteListToIndex(data, 2,sizeof(int));

    Data d3 = data[0];

    printf("count -- %d\n",getListLength(data));

    printf("d3 -- %d\n",*(int*)d3.data);

    freeList(data);


    return 0;
}

