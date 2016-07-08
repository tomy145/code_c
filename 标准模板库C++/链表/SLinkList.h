//
//  SLinkList.h
//  标准模板库C++
//
//  Created by Mac on 16/6/16.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef SLinkList_h
#define SLinkList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef void * ElemType;

struct _tag_Node
{

    ElemType data;
    struct _tag_Node *next;

};

typedef struct _tag_Node Node;

typedef  struct _tag_Sqlist
{
    int length;
    Node header;

}SqList;


//创建一个节点
Node * makeANode(ElemType elm);
// 初始化，建立一个空的线性表L。
void InitList(SqList *list);
// 若线性表为空，返回true，否则返回false
int ListEmpty(SqList * list);
// 将线性表清空
void ClearList(SqList *list);
// 将线性表L中的第pos个位置的元素返回给e
void GetElem(SqList *list, int pos, Node *e);
// 在线性表L中的第pos个位置插入新元素e
void ListInsert(SqList *list, int pos, Node *e);
// 删除线性表L中的第pos个位置元素，并用e返回其值
Node * ListDelete(SqList *list, int pos);
// 返回线性表L的元素个数
int ListLength(SqList *list);


void printList(SqList *list);


#endif /* SLinkList_h */
