//
//  SqList.c
//  标准模板库C++
//
//  Created by Mac on 16/6/15.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "SqList.h"


// 初始化，建立一个空的线性表L。
void InitList(SqList *list)
{
    if (list != NULL)
    {
        list->length = 0;
        list->capacity = 4;
        list->list = calloc(list->capacity, sizeof(Node));
        list->itemSize = 0;

    }
}


// 若线性表为空，返回true，否则返回false
int ListEmpty(SqList *list)
{
    return list->length;
}

// 将线性表清空
void ClearList(SqList *list)
{
    if (list != NULL)
    {
        //释放空间
        for (int i = 0; i < list->capacity; i++)
        {
            Node node = list->list[i];
            if (node != NULL)
            {
                free(node);
            }
        }
        free(list->list);
        list->list = NULL;

        list->length = 0;
        list->capacity = 4;
        list->list = calloc(list->capacity, sizeof(Node));
        list->itemSize = 0;

    }
}

// 将线性表L中的第pos个位置的元素返回给e
void GetElem(SqList *list, int pos, Node *e)
{
    if (list!= NULL&& (pos < list->capacity -1 ))
    {
        *e = list->list[pos];
    }
    else
    {
        printf("获取位置非法，元素不存在!\n");
        assert(1);
    }
}

void printList(SqList *list)
{
    printf(" lllllllllllllllll \n");

    for (int i = 0; i < list->capacity/2; i++)
    {
        Node n2 = list->list[i];
        if (n2 != NULL)
        {
            printf("sll - i %d - %f\n",i , * (double *)n2);

        }

    }

    printf("-------end -------\n");
}


// 在线性表L中的第pos个位置插入新元素e
void ListInsert(SqList *list, int pos, Node e , int itemSize)
{

    char ass = 1;

    if (list!= NULL&& (pos < list->capacity -1 ))
    {
        ass = 1;

        //先判断容量大小
        list->length += 1;

        if (list->length > list->capacity / 2) //重新调整容量的大小
        {

            list->capacity *= 2;
            //重新调整分区大小
            Node *tempList = calloc(list->capacity, sizeof(Node)); //重新调整节点数量

            //重新拷贝到新的临时空间
            for (int i = 0; i < list->capacity / 2; i++)
            {
                //执行深拷贝
                if (list->list[i] != NULL)
                {
                    Node n1 = calloc(1, itemSize);
                    memcpy(n1, list->list[i], itemSize); //节点深拷贝
                    tempList[i] = n1;
                }

            }


            //释放老的空间
            if (list->list != NULL)
            {
                for (int i = 0; i < list->capacity/2; i++)
                {
                    Node node = list->list[i];
                    if (node!= NULL)
                    {
                        free(node);
                        node = NULL;
                    }
                }
                free(list->list);
                list->list = NULL;
            }

            list->list = tempList;


        }

        if (pos >= 0)
        {
            if (list->list[pos] != NULL)
            {
                //移动位置
                for (int i = list->length - 1; i > pos; i--)
                {
                    list->list[i] = list->list[i-1];
                    printList(list);
                }
            }

            if (list->list[pos] == NULL) //判断节点里面是否存有数据
            {
                list->list[pos] = calloc(1, itemSize);
                memcpy(list->list[pos], e, itemSize); //执行深拷贝
            }
            else
            {
                Node n2 = list->list[pos];
                memcpy(n2, e, itemSize); //执行深拷贝
            }

            printList(list);




        }


    }
    else
    {
        ass = 0;

        printf("非法插入!\n");

        assert(ass);
    }
}


// 删除线性表L中的第pos个位置元素，并用e返回其值
void ListDelete(SqList *list, int pos, Node *e)
{
    if (list != NULL && (pos < list->capacity -1))
    {
        //取出临时节点
        *e = list->list[pos];

        //挪动位置
        for (int i = pos; i < list->capacity - 2; i++)
        {
            list->list[i] = list->list[i+1];
        }

        list->length -= 1;
    }
    else
    {
        printf("删除非法\n");
        assert(1);
    }
}

// 返回线性表L的元素个数
int ListLength(SqList * list)
{
    return list->length;
}

