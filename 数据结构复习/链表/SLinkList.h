//
//  SLinkList.h
//  数据结构复习
//
//  Created by Mac on 16/6/18.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef SLinkList_h
#define SLinkList_h

#include <stdio.h>
#include <stdlib.h>


typedef enum _tag_CreatType
{
    CreatType_malloc = 1,
    CreatType_No_malloc

}CreatType;


typedef struct _tag_Node
{
    struct _tag_Node *next;

}Node;

typedef struct _tag_sLinkList
{
    int length; //长度
    Node header;

    CreatType type; //节点创建类型

}SLinkList;




// 初始化，建立一个空的线性表L。
void InitList(SLinkList *list);


// 若线性表为空，返回true，否则返回false
int ListEmpty(SLinkList *list);


// 将线性表清空
void ClearList(SLinkList *list);

// 将线性表L中的第pos个位置的元素返回给e
void GetElem(SLinkList *list, int pos, Node **e);

// 在线性表L中的第pos个位置插入新元素e
void ListInsert(SLinkList *list, int pos, Node* e);

// 删除线性表L中的第pos个位置元素，并用e返回其值
void ListDelete(SLinkList *list, int pos, Node **e);

// 返回线性表L的元素个数
int ListLength(SLinkList *list);



#endif /* SLinkList_h */
