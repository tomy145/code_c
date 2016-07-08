//
//  CircleList.h
//  标准模板库C++
//
//  Created by Mac on 16/6/17.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef CircleList_h
#define CircleList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tag_Node
{

    struct _tag_Node *next;

}Node;


typedef  struct _tag_circleList
{

    int length;
    Node header;
    Node *slider;

}CircleList;

//创建循环链表
CircleList* CircleList_Create();

//销毁循环链表
void CircleList_Destroy(CircleList* list);

//清空循环链表
void CircleList_Clear(CircleList* list);

//获取循环链表长度
int CircleList_Length(CircleList* list);


//在循环链表中插入新节点
int CircleList_Insert(CircleList* list, Node* node, int pos);

//获取循环链表中的指定位置的节点
Node* CircleList_Get(CircleList* list, int pos);


//删除循环链表中的指定位置的节点
//-------------------------------
Node* CircleList_Delete(CircleList* list, int pos);



//------------------ new add ------------------

//直接指定删除链表中的某个数据元素
Node* CircleList_DeleteNode(CircleList* list, Node* node);


//将游标重置指向链表中的第一个数据元素
Node* CircleList_Reset(CircleList* list);


//获取当前游标指向的数据元素
Node* CircleList_Current(CircleList* list);

//将游标移动指向到链表中的下一个数据元素
Node* CircleList_Next(CircleList* list);



#endif /* CircleList_h */
