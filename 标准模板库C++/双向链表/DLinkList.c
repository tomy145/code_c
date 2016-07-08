//
//  DLinkList.c
//  标准模板库C++
//
//  Created by Mac on 16/6/17.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "DLinkList.h"



//创建链表
DLinkList* DLinkList_Create()
{
    DLinkList *list = calloc(1, sizeof(DLinkList));

    if (list != NULL)
    {
        list->length = 0;
        list->head.next = NULL;
        list->slider = NULL;

        return list;
    }

    return NULL;
}

//销毁链表
void DLinkList_Destroy(DLinkList* list)
{
    if (list != NULL)
    {
        free(list);
    }
}

//清空链表
void DLinkList_Clear(DLinkList* list)
{
    if (list != NULL)
    {
        list->head.next = NULL;
        list->slider = NULL;
        list->length = 0;
    }
}

//获取链表长度
int DLinkList_Length(DLinkList* list)
{
    if (list!= NULL)
    {
        return list->length;
    }

    return 0;
}

//获取第pos个元素操作
Node* DLinkList_Get(DLinkList* list, int pos)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (pos < 0 || pos > list->length)
    {
        return NULL;
    }

    Node *pCur = &list->head;

    //挪动位置
    for (int i = 0; i <= pos; i++)
    {
        pCur = pCur->next;
    }

    return pCur;

}

//插入元素到位置pos
int DLinkList_Insert(DLinkList* list, Node* node, int pos);

//删除位置pos处的元素
Node* DLinkList_Delete(DLinkList* list, int pos);

//直接指定删除链表中的某个数据元素
Node* DLinkList_DeleteNode(DLinkList* list, Node* node);


//------------ 游标操作 -------------

//获取当前游标指向的数据元素
Node* DLinkList_Current(DLinkList* list);

//将游标重置指向链表中的第一个数据元素
Node* DLinkList_Reset(DLinkList* list);

//将游标移动指向到链表中的下一个数据元素
Node* DLinkList_Next(DLinkList* list);

//将游标移动指向到链表中的上一个数据元素
Node* DLinkList_Prev(DLinkList* list);

