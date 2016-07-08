////
////  main.c
////  结构体存储
////
////  Created by Mac on 16/5/21.
////  Copyright © 2016年 Mac. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//typedef struct _tag_Student
//{
//    int nameLen;
//    char *name;
//    double height;
//
//}Student;
//
//int main(int argc, const char * argv[])
//{
//
//
//    const char *url = "/Users/Mac/Desktop/tempo/temp/结构体存储/stu.bin";
//
//    FILE *fp = NULL;
//
//    fp = fopen(url, "r");
//
//    if (fp == NULL)
//    {
//        printf("fopen error !\n");
//        return 0;
//    }
//
////    Student stu1;
////    stu1.height = 178.5;
////    stu1.name = calloc(60, sizeof(char));
////    stu1.nameLen = 60;
////    strcpy(stu1.name, "张三");
////
////    int ret = (int)fwrite(&stu1, sizeof(Student), 1, fp);
////    if (ret >= 1)
////    {
////        unsigned long ret = fwrite(&stu1.name, stu1.nameLen, 1, fp);
////        if (ret != stu1.nameLen)
////        {
////            printf("fwrite name Error!\n");
////        }
////    }
//
////    fclose(fp);
//
//    Student stu2;
//
//    fread(&stu2, 1, sizeof(Student), fp);
//
//    stu2.name = calloc(60, sizeof(char));
//
//    fread(&stu2.name, 1, stu2.nameLen, fp);
//
//    printf("stu2 --- %s\n",stu2.name);
//
//
////    free(stu1.name);
//    free(stu2.name);
//    fclose(fp);
//
//
//
//
//
//
//
//    return 0;
//}


#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "/Users/Mac/Desktop/tempo/temp/结构体存储/stu.bin"

struct teacher
{
    int id;
    int age;
    char *name;
    int name_len;
};


int main(int argc, char **argv)
{
    struct teacher t1;

#if 0
    t1.id = 10;
    t1.age = 18;
    t1.name = (char*)malloc(sizeof(char)* 64);
    strcpy(t1.name, "zhang3");
    t1.name_len = strlen(t1.name);

    FILE*fp = NULL;
    int ret = 0;

    fp = fopen(FILE_NAME, "wb+");
    if (fp == NULL) {
        printf("open error\n");
        return -1;
    }


    //要t1结构体本身写道文件中，
    ret = fwrite(&t1, sizeof(struct teacher), 1, fp);
    if (ret != 1) {
        printf("fwrite error\n");
        return -1;
    }

    //再把t1的name数据写道文件中。
    ret = fwrite(t1.name, t1.name_len, 1, fp);
    if (ret != 1) {
        printf("fwrite name error\n");
        return -1;
    }


    if (fp != NULL) {
        fclose(fp);
        fp = NULL;
    }
#endif


#if 1
    FILE *fp = NULL;
    int ret = 0;

    fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("open error\n");
        return -1;
    }

    ret = fread(&t1, sizeof(struct teacher), 1, fp);
    if (ret != 1) {
        printf("fread error\n");
        return -1;
    }


    //读name数据 到name中， 需要给name开辟空间。
    t1.name = (char*)malloc(t1.name_len + 1);
    if (t1.name == NULL) {
        return -1;
    }
    memset(t1.name, 0, t1.name_len + 1);

    printf("t1. name_len = %d\n", t1.name_len);

    ret = fread(t1.name, t1.name_len, 1, fp);
    
    if (ret != 1) {
        printf("fread t1 name error\n");
        return -1;
    }
    
    printf("id = %d, age = %d, name_len = %d, name = %s\n", t1.id, t1.age, t1.name_len, t1.name);
    
    
    if (fp != NULL) {
        fclose(fp);
        fp = NULL;
    }
#endif
    
    return 0;
}
