//
//  SLinkList.c
//  数据结构复习
//
//  Created by Mac on 16/6/18.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "SLinkList.h"


// 初始化，建立一个空的线性表L。
void InitList(SLinkList *list)
{
    if (list != NULL)
    {
        list->length = 0;
        list->header.next = NULL;
    }
}



// 若线性表为空，返回true，否则返回false
int ListEmpty(SLinkList *list)
{

    int ret = 0;

    if (list != NULL)
    {
        ret = 1;
    }

    return ret;
}


// 将线性表清空
void ClearList(SLinkList *list)
{
    if (list!= NULL && list->length >0) //保证不是空表
    {
        int len = list->length;



        if (list->type == CreatType_malloc)
        {
            for (int i = 0; i < len; ++i)
            {
                Node *temp = NULL;
                ListDelete(list, 0, &temp);

                if (temp != NULL)
                {
                    free(temp);
                    temp = NULL;
                }
            }
        }
        else
        {
            Node *temp = NULL;
            for (int i = 0; i < len; ++i)
            {
                ListDelete(list, 0, &temp);
            }
        }



    }
}

// 将线性表L中的第pos个位置的元素返回给e
void GetElem(SLinkList *list, int pos, Node **e)
{
    if (list == NULL || list->length == 0)
    {
        return;
    }

    if (pos < 0 || pos > list->length)
    {
        return;
    }

    Node *pCur = &list->header;

    //挪动位置
    for (int i = 0; i < pos; ++i)
    {
        pCur = pCur->next;
    }

    *e = pCur->next;

}

// 在线性表L中的第pos个位置插入新元素e
void ListInsert(SLinkList *list, int pos, Node* e)
{
    if (list == NULL)
    {
        return;
    }

    if (pos < 0 || pos > list->length)
    {
        return;
    }

    //定义游标指针
    Node *pCur = &list->header;

    //挪动指针
    for (int i = 0; i < pos; ++i)
    {
        pCur = pCur->next;
    }

    //插入节点
    e->next = pCur->next; //先把后面的节点接上,保证链表不会断掉
    pCur->next = e;


    list->length++;
}

// 删除线性表L中的第pos个位置元素，并用e返回其值
void ListDelete(SLinkList *list, int pos, Node **e)
{
    if (list == NULL || 0 == list->length)
    {
        return;
    }

    if (pos < 0 || pos > list->length)
    {
        return;
    }

    //定义游标指针
    Node *pCur = &list->header;

    //挪动游标
    for (int i = 0; i < pos; ++i)
    {
        pCur = pCur->next;
    }

    //删除节点

    Node *temp = pCur->next;
    pCur->next = temp->next;

    *e = temp;

    list->length--;

}

// 返回线性表L的元素个数
int ListLength(SLinkList *list)
{
    int ret = 0;

    if (list != NULL)
    {
        ret = list->length;
    }

    return ret;
}


