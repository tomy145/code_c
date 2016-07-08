//
//  LinkList.c
//  temp
//
//  Created by Mac on 16/5/23.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "LinkList.h"



/**
 *  创建一个链表节点
 *
 *  @param data 节点数据
 *
 *  @return 节点首地址
 */
LinkListNode *makeLinkListNode(int data)
{
    LinkListNode *node = calloc(1, sizeof(LinkListNode));
    if (node == NULL)
    {
        printf("makeLinkListNode Error!\n");
    }

    node->data = data;
    node->next = NULL;

    return node;
}


/**
 初始化链表
 */
LinkList *initList(void)
{
    LinkList *list = (LinkList *)makeLinkListNode(-1);

    return list;
}



/**
 *  释放一个链表节点
 *
 *  @param node 节点
 */
void freeLinkListNode(LinkListNode *node)
{
    if (node != NULL)
    {
        free(node);
    }
}

/**
 *  链表插入一个节点的头部
 *
 *  @param list 链表
 *  @param node 节点
 *  @param pos  插入的位置
 *
 *  @return 新的链表
 */
void insertToLinkList_Head(LinkList **list , LinkListNode *node)
{
    LinkList *head = *list;
    if (list == NULL ||  node == NULL)
    {
        printf("list is NULL or node isNull\n");
        return;
    }

    node->next = head->next;
    head->next = node;

    *list = head;
}

/**
 *  插入链表到尾部
 *
 *  @param list 链表
 *  @param node 节点
 */
void insertToLinkList_Last(LinkList **list, LinkListNode *node)
{

    if (list == NULL ||  node == NULL)
    {
        printf("list is NULL or node isNull\n");
        return;
    }

    LinkList *head = *list;
    LinkList *p = NULL;
    for (p = head; p->next != NULL; p = p->next);
    p->next = node;
    node->next = NULL;

    *list = head;

}

/**
 *  从一个链表中获取链表节点
 *
 *  @param list 链表
 *  @param pos  节点位置
 *
 *  @return 链表节点
 */
LinkListNode *getLinkListNodeFromLinkList(LinkList **list ,int *data)
{
    if (list == NULL || data == NULL)
    {
        printf("list is null or node is null\n");
        return NULL;
    }

    LinkList *head = *list;
    LinkListNode *p = head->next;
    LinkListNode *current = NULL;
    while (p != NULL)
    {
        if (p->data == *data)
        {
            current = p;
            break;
        }
        p = p->next;

    }

    *list = head;

    return current;
}

/**
 *  从一个链表中删除一个节点
 *
 *  @param list 链表
 *  @param node  节点
 *
 *  @return 是否删除成功
 */
int deleteLinkListNode(LinkList **list , LinkListNode *node)
{
    LinkList *head = *list;
    int ret = -1;

    if (list == NULL || node == NULL)
    {
        printf("list is null or node is null \n");
        ret = -1;
    }

    LinkList *p = head;

    while (p->next != NULL)
    {
        if (p->next == node)
        {

            p->next = node->next;

            freeLinkListNode(node);

            break;
        }
        p = p->next;

    }

    *list = head;

    return ret;
}

/**
 *  销毁一个链表
 *
 *  @param list 链表
 */
void destory_LinkList(LinkList *list)
{
    if (list == NULL)
    {
        printf("list is null \n");
        return;
    }

    LinkListNode *node  = NULL;
    LinkList *p = list;

    int i = 0;

    while (p != NULL)
    {
        node = p->next;
        p = p->next;

        free(p);
        ++i;
    }

    printf("i = %d\n",i);

}


/**
 *  打印一个链表
 *
 *  @param list 链表
 */
void printLinkList(LinkList *list)
{
    if (list == NULL)
    {
        printf("list is null \n");
        return;
    }
    LinkListNode *head = list;
    int i = 0;
    while (head != NULL)
    {
        printf("linklist->data --- %c --- 第 - %d - 个节点\n",head->data,i);
        head = head->next;
        ++i;
    }
}