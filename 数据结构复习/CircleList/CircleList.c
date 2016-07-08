//
//  CircleList.c
//  数据结构复习
//
//  Created by Mac on 16/6/19.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "CircleList.h"



//创建循环链表
CircleList* CircleList_Create()
{
    CircleList *list = calloc(1, sizeof(CircleList));

    if (list != NULL)
    {
        list->header.next = NULL;
        list->length = 0;
        list->slider = NULL;
        return list;
    }

    return NULL;
}

//销毁循环链表
void CircleList_Destroy(CircleList* list)
{
    if (list!= NULL)
    {
        if (list->type == CreateType_malloc) //堆上开辟的
        {
            //销毁每个节点
            Node *del = CircleList_Delete(list, 0);

            if (del != NULL)
            {
                free(del);
                del = NULL;
            }
        }

        free(list);
        list = NULL;
    }
}

//清空循环链表
void CircleList_Clear(CircleList* list)
{
    if (list != NULL)
    {
        list->header.next = NULL;
        list->type = CreateType_No_malloc;
        list->length = 0;
        list->slider = NULL;
    }
}

//获取循环链表长度
int CircleList_Length(CircleList* list)
{
    int ret = 0;

    if (list!= NULL)
    {
        ret = list->length;
    }

    return ret;
}

//在循环链表中插入新节点
int CircleList_Insert(CircleList* list, Node* node, int pos)
{
    int ret = -1;

    if (list == NULL)
    {
        return ret;
    }

    if (pos < 0 || pos > list->length || node == NULL)
    {
        return ret;
    }

    //定义游标
    Node *pCur = &list->header;

    //挪动游标
    for (int i = 0; i < pos; ++i)
    {
        pCur = pCur->next;
    }

    node->next = pCur->next;
    pCur->next = node;

    list->length++;


    if (0 == pos) //是头结点，特殊处理
    {
        list->slider = node; //游标指向头结点
        Node *last = CircleList_Get(list, list->length -1); //获取末尾节点
        if (last != NULL)
        {
            last->next = node;
        }
    }



    return ret;
}

//获取循环链表中的指定位置的节点
Node* CircleList_Get(CircleList* list, int pos)
{

    if (list == NULL)
    {
        return NULL;
    }

    if (pos < 0 || pos >= list->length)
    {
        return NULL;
    }

    Node *pCur = &list->header;

    for (int i = 0; i <= pos; ++i)
    {
        pCur = pCur->next;
    }

    return pCur;
}

//删除循环链表中的指定位置的节点
Node* CircleList_Delete(CircleList* list, int pos)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (pos < 0 || pos > list->length || 0 == list->length)
    {
        return NULL;
    }

    //定义游标指针
    Node *pCur = &list->header;

    //移动游标
    for (int i = 0; i < pos; ++i)
    {
        pCur = pCur->next;
    }

    Node *del = pCur->next;

    if (0 == pos) //首号元素特殊处理
    {
        pCur->next = del->next;

        Node *last = CircleList_Get(list, list->length - 1);

        if (last != NULL)
        {
            last->next = del->next;

        }
    }
    else
    {
        pCur->next = del->next;
    }

    list->length--;

    if (list->slider == del) //如果删除的节点和游标节点相同，游标向下移动一个位置
    {
        list->slider = del->next;
    }

    return del;
}

//直接指定删除链表中的某个数据元素
Node* CircleList_DeleteNode(CircleList* list, Node* node)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (0 == list->length)
    {
        return NULL;
    }

    //定义游标
    Node *pCur = &list->header;

    int pos = 0;
    //遍历链表
    for (int i = 0; i < list->length -1; ++i)
    {
        pCur = pCur->next;
        if (node == pCur) //找到节点位置
        {
            pos = i;
            break;
        }
    }
    Node *del = CircleList_Delete(list, pos);
    return del;
}



//----------------- 游标操作(辅助指针) -------------------

//将游标重置指向链表中的第一个数据元素
Node* CircleList_Reset(CircleList* list)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (list->length == 0)
    {
        return NULL;
    }

    list->slider = list->header.next; //游标指向首元素

    return list->slider;

}

//获取当前游标指向的数据元素
Node* CircleList_Current(CircleList* list)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (list->length == 0)
    {
        return NULL;
    }

    return list->slider;
}

//将游标移动指向到链表中的下一个数据元素
Node* CircleList_Next(CircleList* list)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (list->length == 0)
    {
        return NULL;
    }

    Node *temp = list->slider; //返回未移动之前的

    if (list->slider->next != NULL)
    {
        list->slider = list->slider->next;
    }


    return temp;
}
