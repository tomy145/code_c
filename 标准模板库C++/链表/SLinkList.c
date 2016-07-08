//
//  SLinkList.c
//  标准模板库C++
//
//  Created by Mac on 16/6/16.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "SLinkList.h"


//创建一个节点
Node * makeANode(ElemType elm)
{

    Node *node = calloc(1, sizeof(Node));

    if (node != NULL)
    {
        node->next = NULL;
        node->data = elm;
    }

    return node;
}

// 初始化，建立一个空的线性表L。
void InitList(SqList *list)
{
    if (list != NULL)
    {
        list->header.data = 0;
        list->header.next = NULL;
        list->length = 0;
    }
}


// 若线性表为空，返回true，否则返回false
int ListEmpty(SqList * list)
{
    return list->length;
}


// 将线性表清空
void ClearList(SqList *list)
{
    if (list != NULL)
    {
        int len = ListLength(list);
        for (int i = 0; i < len; i++)
        {
            Node *del = ListDelete(list, 0);
            if (del != NULL)
            {
                printf("释放次数 --- i = %d\n",i);
                free(del);
            }
        }

    }
}


// 将线性表L中的第pos个位置的元素返回给e
void GetElem(SqList *list, int pos, Node *e)
{
    if (pos >= 0 && pos <= list->length && list != NULL)
    {

        Node *pcur = &list->header;
        for (int i = 0; i < pos - 1; i++) //挪动位置
        {
            pcur = pcur->next;
        }

        *e = *pcur;

    }
    else
    {
        printf("非法获取 \n");
        assert(0);
    }

}


// 在线性表L中的第pos个位置插入新元素e
void ListInsert(SqList *list, int pos, Node *e)
{
    if (pos >= 0 && list != NULL)
    {
        Node *pcur = &list->header;

        //挪动指针
        for (int i = 0; i < pos; i++)
        {
            pcur = pcur->next;
        }

        //插入数据
        e->next = pcur->next;
        pcur->next = e;

        list->length += 1;

    }
}



// 删除线性表L中的第pos个位置元素，并用e返回其值
Node * ListDelete(SqList *list, int pos)
{


    Node *del = NULL;

    if (list != NULL && pos >= 0)
    {
        Node *pcur = &list->header;

        //挪动位置
        for (int i = 0; i < pos; i++)
        {
            pcur = pcur->next;
        }

        del = pcur->next;
        pcur->next = del->next;

        list->length --;

    }

    return del;

}


// 返回线性表L的元素个数
int ListLength(SqList *list)
{
    if (list!= NULL)
    {
        return list->length;
    }
    else
    {
        return 0;
    }
}


void printList(SqList *list)
{
    if (list != NULL)
    {
        Node *pcur = &list->header;

        int len = ListLength(list);

        for (int i = 0; i < len; i++)
        {
            pcur = pcur->next;

            printf("data = %d --- item = %d\n",pcur->data,i);
        }

        printf(" ----------打印完毕------ \n");

    }
}