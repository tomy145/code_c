//
//  main.c
//  排序
//
//  Created by Mac on 16/6/20.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>


void selectSort(int *p , int len)
{
    int min = 0;

    for (int i = 0; i < len - 1; ++i)
    {
        min = i;

        for (int j = i + 1; j < len; ++j)
        {
            if (p[min] > p[j])
            {
                min = j;
            }
        }

        //交换位置
        int temp = p[min];
        p[min] = p[i];
        p[i] = temp;

    }

}


void printArray(int *p , int len,char *str)
{

    printf("--- %s\n",str);

    printf("printArray ---- start \n");


    for (int i = 0; i < len; ++i)
    {
        printf("array[%d] = %d\n",i,p[i]);
    }


    printf("printArray ---- end \n");
}

int main(int argc, const char * argv[])
{

    int array[] = {1,4,2,6,8,9,18,22,19};

    int len = sizeof(array) / sizeof(int);

    printArray(array, len,"排序之前 ---- ");


    selectSort(array, len);


    printArray(array, len,"排序之后 ---- ");






    return 0;
}
