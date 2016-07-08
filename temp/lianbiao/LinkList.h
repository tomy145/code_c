//
//  LinkList.h
//  temp
//
//  Created by Mac on 16/5/23.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tag_LinkListNode  LinkListNode;
typedef  LinkListNode LinkList;

typedef struct  _tag_LinkListNode
{

    int data;

    LinkListNode *next;

}LinkListNode;



/**
 初始化链表
 */
LinkList *initList(void);

/**
 *  创建一个链表节点
 *
 *  @param data 节点数据
 *
 *  @return 节点首地址
 */
LinkListNode *makeLinkListNode(int data);


/**
 *  释放一个链表节点
 *
 *  @param node 节点
 */
void freeLinkListNode(LinkListNode *node);

/**
 *  链表插入一个节点
 *
 *  @param list 链表
 *  @param node 节点
 *  @param pos  插入的位置
 *
 *  @return 新的链表
 */
void insertToLinkList_Head(LinkList **list , LinkListNode *node);

/**
 *  插入链表到尾部
 *
 *  @param list 链表
 *  @param node 节点
 */
void insertToLinkList_Last(LinkList **list, LinkListNode *node);

/**
 *  从一个链表中获取链表节点
 *
 *  @param list 链表
 *  @param node  节点
 *
 *  @return 链表节点
 */
LinkListNode *getLinkListNodeFromLinkList(LinkList **list ,int *data);

/**
 *  从一个链表中删除一个节点
 *
 *  @param list 链表
 *  @param node  节点
 *
 *  @return 是否删除成功
 */
int deleteLinkListNode(LinkList **list , LinkListNode *node);

/**
 *  销毁一个链表
 *
 *  @param list 链表
 */
void destory_LinkList(LinkList *list);


/**
 *  打印一个链表
 *
 *  @param list 链表
 */
void printLinkList(LinkList *list);


#endif /* LinkList_h */
