//
//  main.c
//  线性表
//
//  Created by Mac on 16/6/15.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SqList.h"

int main(int argc, const char * argv[])
{

    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
//
//    void **p1 = calloc(2, sizeof(void *));
//
//    int *ip = calloc(1, sizeof(int));
//    *ip = 1;
//
//    p1[0] = ip;
//
//    printf("p1.value = %d\n",* (int*) p1[0]);
//
    SqList list;

    InitList(&list);

    for (int i = 0; i < 10; i++)
    {
        double value = arr[i];

        ListInsert(&list, i, (Node)(&value), sizeof(double));

    }



    printList(&list);


    for (int i = 0; i < 3; i++)
    {

        if (i == 0)
        {
            double v1 = 3.1415926;

            ListInsert(&list, 0, (Node)(&v1), sizeof(double));
        }
        else if (1 == i)
        {
            double v1 = 3.1415926;

            ListInsert(&list, 2, (Node)(&v1), sizeof(double));
        }
        else
        {
            double v1 = 3.1415926;
            ListInsert(&list, 4, (Node)(&v1), sizeof(double));
        }

    }




//    printf(" ------ ");
//
////
//    for (int i = 0; i < list.capacity; i++)
//    {
////        Node node;
////        GetElem(&list, i, &node);
//        if (list.list[i] != NULL)
//        {
//            printf("value = %f\n",*(double *)list.list[i]);
//
//        }
//    }
//

//
//    double i = 3.1425973738;
//    void *p = calloc(1, sizeof(double));
//
//    memcpy(p, &i, sizeof(double));
//
//    printf("value = %f\n",* (double*)p);
//    printf("value = %f\n",i);


//    void **p1 = calloc(11, sizeof(void *));
//
//    for (int i = 0; i < 11; ++i)
//    {
//        p1[i] = calloc(1, sizeof(int));
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        int len = i;
//        memcpy(p1[i], &len, sizeof(int));
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        printf("i = %d --- value = %d\n",i , *(int *)p1[i]);
//    }
//
//    printf(" ------------------ \n");
//
//    for (int i = 10; i > 0; i --)
//    {
//        p1[i] = p1[i-1];
//    }
//
//    for (int i = 0; i < 11; i++)
//    {
//        printf("i = %d --- value = %d\n",i , *(int *)p1[i]);
//    }
//
//    printf("ssssssssssssssssssssssss\n");
//
//    int v1 = 28900;
//
//    memcpy(&p1[1], &v1, 4);
//
//    for (int i = 0; i < 11; i++)
//    {
//        printf("i = %d --- value = %d\n",i , *(int *)p1[i]);
//    }

//
//    int arr[3] = {1,2,3};
//
//    int a = -1;
//    memcpy(&arr[0],&a , sizeof(int));
//
//    for (int i = 0; i < 3; ++i)
//    {
//        printf("i -- %d\n",arr[i]);
//    }


    return 0;
}
