//
//  CircleList.c
//  标准模板库C++
//
//  Created by Mac on 16/6/17.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "CircleList.h"


//创建循环链表
CircleList* CircleList_Create()
{
    CircleList *list = calloc(1, sizeof(CircleList));

    if (list != NULL)
    {
        list->length = 0;
        list->header.next = NULL;
        list->slider = NULL;
        return list;
    }

    return NULL;
}

//销毁循环链表
void CircleList_Destroy(CircleList* list)
{
    if (list != NULL)
    {
        free(list);
    }
}

//清空循环链表
void CircleList_Clear(CircleList* list)
{
    if (list != NULL)
    {
        list->header.next = NULL;
        list->length = 0;
        list->slider = NULL;
    }
}

//获取循环链表长度
int CircleList_Length(CircleList* list)
{
    if (list != NULL)
    {
        return list->length;
    }
    else
    {
        return 0;
    }
}


//在循环链表中插入新节点
int CircleList_Insert(CircleList* list, Node* node, int pos)
{
    if (list == NULL)
    {
        return -1;
    }

    if (pos < 0 || pos > list->length)
    {
        return -1;
    }


    //定义游标指针
    Node *pCur = &list->header;

    if (0 == pos) //头结点
    {
        
    }
    else
    {

    }

    //挪动位置
    for (int i = 0; i < pos; ++i)
    {
        pCur = pCur->next;
    }

    //插入节点
    node->next = pCur->next;
    pCur->next = node;

    //挪动游标
    if (0 == list->length)
    {
        list->slider = node;
    }

    list->length ++;

    if (pCur == &list->header) //如果是头节点，特殊处理
    {
        //获取末尾节点
        Node *last = CircleList_Get(list, list->length - 1);
        last->next = pCur->next;

    }

    return 0;
}

//获取循环链表中的指定位置的节点
Node* CircleList_Get(CircleList* list, int pos)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (pos < 0 || pos > list->length)
    {
        return NULL;
    }


    Node *pCur = &list->header;

    //挪动位置
    for (int i = 0 ; i < pos; i++)
    {
        pCur = list->header.next;
    }

    return pCur;
}


//删除循环链表中的指定位置的节点
//-------------------------------
Node* CircleList_Delete(CircleList* list, int pos)
{

    if (list != NULL)
    {

        //定义游标指针
        Node *pcur = &list->header;

        //挪动位置
        for (int i = 0; i < list->length; ++i)
        {
            pcur = pcur->next;
        }

        //删除节点的位置
        Node *del = pcur->next;

        if (del == &list->header) //如果头结点,特殊处理
        {
            Node *last = CircleList_Get(list, list->length - 1);

            if (last != NULL)
            {
                last->next = del->next;
            }
        }

        pcur->next = del->next;

        list->length--;

        //如果是游标
        if (del == list->slider)
        {
            list->slider = del->next;
        }


    }

    return NULL;
}



//------------------ new add ------------------

//直接指定删除链表中的某个数据元素
Node* CircleList_DeleteNode(CircleList* list, Node* node)
{
    if (list != NULL && node != NULL)
    {
        int pos = 0; //获取节点位置

        Node *pCur = &list->header;

        for (int i = 0; i < list->length; ++i)
        {
            if (node == pCur->next)
            {
                pos = i;
                break;
            }

            pCur = pCur->next;
        }

        //获取删除节点
        Node *del = CircleList_Delete(list, pos);
        return del;
    }

    return NULL;
}


//将游标重置指向链表中的第一个数据元素
Node* CircleList_Reset(CircleList* list)
{
    if (list != NULL)
    {
        list->slider = list->header.next;

        return list->slider;
    }

    return NULL;

}


//获取当前游标指向的数据元素
Node* CircleList_Current(CircleList* list)
{
    if (list != NULL)
    {
        return list->slider;
    }

    return NULL;
}

//将游标移动指向到链表中的下一个数据元素
Node* CircleList_Next(CircleList* list)
{
    if (list == NULL)
    {
        return NULL;
    }

    Node *current = list->slider;

    if (current != NULL)
    {
        list->slider = list->slider->next;
    }

    return current;

}

