//
//  CircleList.h
//  数据结构复习
//
//  Created by Mac on 16/6/19.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef CircleList_h
#define CircleList_h

#include <stdio.h>
#include <stdlib.h>


typedef enum _tag_CreateType
{
    CreateType_malloc = 1, //代表是在堆上分配内存的
    CreateType_No_malloc

}CreateType;

//自定义循环链表节点数据类型
typedef struct _tag_Node
{
    struct _tag_Node *next;
}Node;

//创建结构体管理链表
typedef struct tag_CircleList
{

    //循环链表头结点
    Node header;

    //循环链表游标
    Node *slider;
    //循环链表长度
    int	length;

    //节点是否是在堆上开辟的
    CreateType type;
    


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
Node* CircleList_Delete(CircleList* list, int pos);

//直接指定删除链表中的某个数据元素
Node* CircleList_DeleteNode(CircleList* list, Node* node);

//----------------- 游标操作(辅助指针) -------------------

//将游标重置指向链表中的第一个数据元素
Node* CircleList_Reset(CircleList* list);

//获取当前游标指向的数据元素
Node* CircleList_Current(CircleList* list);

//将游标移动指向到链表中的下一个数据元素
Node* CircleList_Next(CircleList* list);


#endif /* CircleList_h */
