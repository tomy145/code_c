//
//  main.c
//  C提高阶段习题
//
//  Created by 黄绍冬 on 16/5/25.
//  Copyright © 2016年 Mac. All rights reserved.
//


/**
    
 选择题和填空题
 1、12 , 0x78891586
 2、简述堆区与栈区内存分配方式及数据的特点。
 答：堆区，内存有程序员申请和释放，申请的最大内存量比较栈大一个数量级。
     栈区，在不同的线程，栈所占用的空间的大小也是不一样的，在主线程中，栈一般占用8M字节，有系统分配，和释放，系统统一管理，内存分配效率高，速度比堆区的速度快

 3、简述数组指针和指针数组的区别。
 答:数组指针 int (*array)[4] , 指针数组 int *array1[4] ,
    共同点，array 和 array1 都是指向数组首地址，
    异同点:数组指针只是一个指针变量，似乎是C语言里专门用来指向二维数组的，它占有内存中一个指针的存储空间,
          指针数组是多个指针变量，以数组形式存在内存当中，占有多个指针的存储空间
 4、请简述const int *p, int const *p, int * const p, const int * const p的区别。

    答：const 匹配有一个原则 和它最靠近右边的匹配
       const int *p const和*p 结合， p所指向的内存的数据不可以改变，但是可以改变指针的指向.
       int const *p 和 const int *p 一样，
       int * const p p的指向不能改变，但是p所指向的内存的值可以改变,比如*p = 20；是可以修改里面的值的
       const int * const p  ,其中p的指向不能改变，所指向内存的值也不能改变。
 
 5.  4(32位平台) ，7，8，7





 */






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkList.h"


//1、求一个字符串中数字字符的个数。（20分）
//int getCount(const char *str, int *pCount);
//计算出str所指向的字符串中数字字符的个数，并通过pCount返回。
//str：指向所要求数字字符个数的字符串；
//pCount：将所求数字字符个数通过pCount进行间接赋值。
//成功返回0，失败返回-1。
int getCount(const char *str, int *pCount)
{
    int ret = -1;

    char *tempStr = (char *)str;

    if (NULL == tempStr)
    {
        ret = -1;
    }
    else
    {
        int i = 0;
        while (*tempStr != '\0')
        {
            if (*tempStr >= '0' && *tempStr <= '9')
            {
                ++i;

            }
            tempStr +=1;
        }

        *pCount = i;

        ret = 0;
    }

    return ret;
}


//2、已知strncpy函数原型为:（25分）
//char *strncpy(char *strDes, const char *strSrc, int n);
//尝试自己一个strncpy函数？
//函数原型：char *mystrncpy(char *strDes, const char *strSrc, int n);
//函数功能：从strSrc所指向的字符串中拷备n个字符到strDes所指向的内存空间中。
//函数参数：strDes：拷备字符串的目的空间。
//strSrc：待拷备的字符串。
//n：所要拷备的字符的个数。
//函数返回值：成功返回目的字符串的首地址，失败返回NULL。

char *myStrncpy(char *strDes, const char *strSrc, int n)
{
    char *tempDes = strDes;
    char *tempSrc = (char *)strSrc;
    char *retStr = NULL;

    if (strDes == NULL || strSrc == NULL)
    {
        printf("strDes == NULL || strSrc == NULL error ! \n");
    }
    else
    {
        int desStrLen = 0;
        getCount(strDes, &desStrLen);

        int i = 0;
        for ( i = 0; i < n; i++)
        {
            tempDes[i+desStrLen] = tempSrc[i];
        }


        retStr = tempDes;
    }

    return retStr;
}


//3.假设一个student.txt文件中有以下信息：（30分）
//
//name=suyu age=20
//name=  haha  age=23
//name= lili age= 22
//name= xixi age=27
//name=lucy age =18
//name=lala age =33
//......
//
//请你把文件中的信息读出，把每行的数据按age进行从大到小排序，并把结果写回一个文件student2.txt中。
//
//提示：
//(1) 每行的学生信息可用一个结构体进行保存。
//typedef struct _tag_Student {
//    char name[24];
//    int age;
//}Student;

//(2) 获取从文件中读取的每一行学生的信息。

//函数原型：int getStudentInfo(char *studentInfo, Student *stu);

//函数功能：从studentInfo所指向的字符串中提取出学生的姓名年龄，并保存到一个结构体变量中。

//函数参数：studentInfo：指向包含学生name和age的一个字符串。

//stu：指向用于保存学生信息的结构体。

//返回值：成功返回0，失败返回-1。

//(3) 获得的每个学生的信息可用链表进行保存。
//typedef struct _listNode {
//    Student *stu;
//    struct _listNode *next;
//}ListNode;
//

//读取路径
static const char *readDir = "/Users/Mac/Desktop/tempo/temp/C提高阶段习题/student.txt";

//存储路径
static const char *writeDir = "/Users/Mac/Desktop/tempo/temp/C提高阶段习题/sortStudent.txt";



int getStudentInfo(char *studentInfo, Student *stu)
{
    int ret = -1;

    char *token = NULL;
    char *delim = "= ";
    char *buf = calloc(1024, 1);
    if (studentInfo == NULL || stu == NULL)
    {
        ret = -1;
    }
    else
    {
        strcpy(buf, studentInfo);

        printf("buf --- %s\n",buf);

        if (strlen(buf))
        {
            token = strtok(buf,delim);
            for (int i = 0; token != NULL; i++)
            {

                token = strtok(NULL,delim);
                if (token != NULL)
                {
                    if (strcmp(token, "age") != 0)
                    {
                        strcpy(stu->name, token);
                    }
                    printf("token --- %s\n",token);
                    token = strtok(NULL,delim);
                    printf("token --- %s\n",token);

                    token = strtok(NULL,delim);
                    if (token != NULL)
                    {
                        stu->age = atoi(token);
                    }
                    printf("token --- %s\n",token);
                }

            }
            ret = 0;
        }
    }


    free(buf);

    return ret;
}


int main(int argc, const char * argv[])
{


    LinkList *list = initList();

    FILE *fp = fopen(readDir, "r");
    if (fp == NULL)
    {
        printf("file open error !\n");
    }
    else
    {
        char *buf = calloc(1024, 1);
        char *p = NULL;

        while ((p = fgets(buf, 1024, fp)) != NULL)
        {
            Student stu1 = {0};
            if(0 == getStudentInfo(p, &stu1))
            {
                LinkListNode *node = makeLinkListNode(stu1);
                insertToLinkList_Head(&list, node);
            }
            memset(buf, 0, 1024);

        }

        free(buf);

    }

    int listLen = getLinkListLength(list);

    Student *stu = calloc(listLen - 1, sizeof(Student));
    Student *stu2 = calloc(listLen -1, sizeof(Student));

    for (int i = 0; i < listLen; i++) //从链表中提取data
    {
        if (i > 0)
        {
            stu[i-1] = list->data;
        }
        list = list->next;
    }

    //打印从链表里面抽取出来的元素
    for (int i = 0; i < listLen -1; i++)
    {
        printf("name ---  %s -- age ---%d\n",stu[i].name,stu[i].age);
    }

    for (int i = 0; i < listLen -1; i++)
    {
        for (int j = i; j < listLen - 1; j++)
        {
            if (stu[i].age < stu[j].age)
            {
                Student tempStu = stu[i];
                stu[i] = stu[j];
                stu[j] = tempStu;
            }
        }
    }

    printf("排序后的----\n");
    //打印从链表里面抽取出来的元素
    for (int i = 0; i < listLen -1; i++)
    {
        printf("name ---  %s -- age ---%d\n",stu[i].name,stu[i].age);
    }

    //销毁链表
    destory_LinkList(list);

//    重新生成链表,排好序的链表
    LinkList *list2 = initList();
    for (int i = 0; i < listLen -1; i++)
    {
        LinkListNode *node = makeLinkListNode(stu[i]);
        insertToLinkList_Last(&list2, node);
    }

    //关闭文件
    fclose(fp);
    //保存到文件中
    FILE *wFp = fopen(writeDir, "w+");
    if (wFp != NULL)
    {
        fwrite(stu, sizeof(Student), listLen-1, wFp);
    }

    fclose(wFp);
    free(stu);
    free(stu2);

    return 0;
}
