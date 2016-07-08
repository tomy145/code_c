//
//  main.c
//  循环链表
//
//  Created by Mac on 16/6/17.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"
#include <stdarg.h>

/*
 约瑟夫问题-循环链表典型应用
 n 个人围成一个圆圈，首先第 1 个人从 1 开始一个人一个人顺时针报数，
 报到第 m 个人，令其出列。然后再从下一 个人开始从 1 顺时针报数，报
 到第 m 个人，再令其出列，…，如此下去，求出列顺序。

 求解: 假设 m = 3, n = 8 (1 2 3 4 5 6 7 8)
 结果: 3 6 1 5 2 8 4 7
 */



typedef struct People
{
    // 包含一个链表节点(必须在第一个数据域的位置)
    Node node;
    int value;
}People;



void josephQuestion()
{
    People p[41];

    // create list
    CircleList* list = CircleList_Create();


    //初始化数据
    for (int i = 0; i < 41; ++i)
    {
        p[i].value = i + 1;
        // insert
        CircleList_Insert(list, &p[i].node, i);

        People *p1 = (People *)list->header.next;

        printf("value = %d\n",p1->value);
    }




    // 遍历
    for (int i = 0; i < CircleList_Length(list); ++i)
    {
        Node* node = CircleList_Get(list, i);
        People* p = (People *)node;
        printf("%d ", p->value);
    }

    printf("\n");

    CircleList_Reset(list);
    while (CircleList_Length(list))
    {
        // 数数 1 - 3
        for (int i = 1; i < 3; ++i)
        {
            // 游标移动
            CircleList_Next(list);
        }
        // 删除游标指向的节点
        Node* pDel = CircleList_Current(list);
        People* p = (People *)pDel;
        printf("%d ", p->value);
        CircleList_DeleteNode(list, pDel);
    }
    // 销毁链表
    CircleList_Destroy(list);
}


void func(int count , ...)
{

    va_list args;

    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        int value = (int)va_arg(args, int);
        printf("argv[%d] = %d\n",i,value);

    }

    va_end(args);



}

int main(void)
{
//    josephQuestion();


    func(13,3,5,6,3,7,9,33,22,35,67,123);



    getchar();
}