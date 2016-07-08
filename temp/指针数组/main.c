//
//  main.c
//  指针数组
//
//  Created by Mac on 16/6/6.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{

    int arr[3][4] = {{1,2,3,4} , { 5,6,7,8} , {9 , 10 , 11 , 12}};

    int *arrayPoint[4] = &arr;


    return 0;
}





