//
//  DLinkList.h
//  数据结构复习
//
//  Created by Mac on 16/6/19.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef DLinkList_h
#define DLinkList_h

#include <stdio.h>
#include <stdlib.h>

//自定义双向链表节点数据类型
 struct tag_node
{
    struct tag_node *prev;	// 前驱
    struct tag_node *next;	// 后继


};

//重定义
typedef struct tag_node Node;


//定义管理双向链表的结构体
typedef struct _tag_dlinklist
{
    Node header;	// 头结点
    Node *slider;	// 辅助指针变量(游标)
    int length;		// 长度

}DLinkList;

//创建链表
DLinkList* DLinkList_Create();

//销毁链表
void DLinkList_Destroy(DLinkList* list);

//清空链表
void DLinkList_Clear(DLinkList* list);

//获取链表长度
int DLinkList_Length(DLinkList* list);

//获取第pos个元素操作
Node* DLinkList_Get(DLinkList* list, int pos);

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


#endif /* DLinkList_h */
