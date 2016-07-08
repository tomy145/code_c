//
//  main.c
//  获取文件大小
//
//  Created by Mac on 16/5/21.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>

void shop(int p[3][4])
{
    printf("size --- %d\n",sizeof(p));
}

typedef struct
{
    int age;
    char name[24];

}stu;

int main(int argc, const char * argv[])
{

    stu st1 = {4,"name"};

    printf("na--- %s\n",((char *)&st1+4));

    int a[3][4];
    shop(a);

    FILE *fp;
    int len;
    fp = fopen("/Users/Mac/Desktop/tempo/temp/数组与指针/main.c", "rb");
    if( fp == NULL )
    {
        perror ("    错误");


    }

    fseek(fp, 0, SEEK_END);


    len = (int)ftell(fp);

    fclose(fp);
    printf("file.txt  总   = %d  节\n", len);


    return 0;
}


