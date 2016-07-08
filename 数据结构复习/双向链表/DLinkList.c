//
//  DLinkList.c
//  数据结构复习
//
//  Created by Mac on 16/6/19.
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
        list->slider = NULL;
        list->header.next = NULL;

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
void DLinkList_Clear(DLinkList* list);

//获取链表长度
int DLinkList_Length(DLinkList* list)
{
    if (list != NULL)
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

    if (pos < 0 || pos >list->length)
    {
        return NULL;
    }

    //定义游标指针
    Node *pCur = &list->header;

    //滚动游标
    for (int i = 0; i < pos; ++i)
    {
        pCur = pCur->next;
    }

    return pCur->next;

}

//插入元素到位置pos
int DLinkList_Insert(DLinkList* list, Node* node, int pos)
{

    int ret = -1;

    if (list == NULL || node == NULL)
    {
        return ret;
    }

    if (pos < 0 || pos > list->length)
    {
        return ret;
    }

    Node *pCur = &list->header; //游标节点

    //移动位置
    for (int i = 0; i < pos; ++i)
    {
        pCur = pCur->next;
    }


    Node *n_Next = pCur->next;

    //插入节点
    node->next = n_Next;

    if (n_Next != NULL)
    {
        n_Next->prev = node;
    }

    pCur->next = node;

    node->prev = pCur;

    if (pCur == &list->header) //如果是头插法，头结点prev = null；
    {
        node->prev = NULL;
    }

    if (list->length == 0) //没有数据
    {
        list->slider = node; //游标指向首元素
    }

    //长度加一
    list->length++;

    return ret;
}



//删除位置pos处的元素
Node* DLinkList_Delete(DLinkList* list, int pos)
{

    if (list == NULL)
    {
        return NULL;
    }

    if (pos < 0 || pos > list->length || list->length == 0)
    {
        return NULL;
    }

    //定义游标
    Node *pCur = &list->header;

    //挪动游标
    for (int i = 0; i < pos; ++i)
    {
        pCur = pCur->next;
    }

    Node *del = pCur->next;

    pCur->next = del->next;


    if (del->next != NULL)
    {
        Node *delNext = del->next;
        delNext->prev = pCur;


        //判断pCur是否是头结点,头结点prev = null
        if (pCur == &list->header)
        {
            delNext->prev = NULL;
        }

    }


    //判断删除节点是否是游标
    if (del == list->slider)
    {
        if (del->next != NULL)
        {
            list->slider = del->next;
        }
    }

    //长度--
    list->length--;

    return del;
}


//直接指定删除链表中的某个数据元素
Node* DLinkList_DeleteNode(DLinkList* list, Node* node);


//------------ 游标操作 -------------

//获取当前游标指向的数据元素
Node* DLinkList_Current(DLinkList* list);

//将游标重置指向链表中的第一个数据元素
Node* DLinkList_Reset(DLinkList* list);

//将游标移动指向到链表中的下一个数据元素
Node* DLinkList_Next(DLinkList* list)
{
    if (list != NULL || list->length > 0)
    {
        Node *current = list->slider;

        list->slider = list->slider->next;

//        if (list->slider->next != NULL)
//        {
//
//        }
        return current;

    }

    return NULL;
}

//将游标移动指向到链表中的上一个数据元素
Node* DLinkList_Prev(DLinkList* list);