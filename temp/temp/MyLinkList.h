////
////  MyLinkList.h
////  temp
////
////  Created by Mac on 16/5/15.
////  Copyright © 2016年 Mac. All rights reserved.
////
//
//#ifndef MyLinkList_h
//#define MyLinkList_h
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct LinkListNode MyLinkListNode;
//typedef  struct _tag_MyLinkList MyLinkList;
//
//struct LinkListNode
//{
//
//    int value;
//
//    MyLinkListNode  * next;
//    
//};
//
//
//
//struct _tag_MyLinkList
//{
//    int length;
//
//    MyLinkListNode *next;
//} ;
//
//
///**
// *  链表的创建
// *
// *  @return 链表首地址
// */
//MyLinkList* LinkList_Create();
//
///**
// *  链表的销毁
// *
// *  @param list 链表首地址
// */
//void LinkList_Destroy(MyLinkList* list);
//
///**
// *  链表的清空
// *
// *  @param list 链表首地址
// */
//void LinkList_Clear(MyLinkList* list);
//
///**
// *  获取链表长度
// *
// *  @param list 链表
// *
// *  @return 长度
// */
//int LinkList_Length(MyLinkList* list);
//
///**
// *  链表的插入
// *
// *  @param list 链表
// *  @param node 链表节点
// *  @param pos  插入的位置
// *
// *  @return 是否插入成功
// */
//int MyLinkList_Insert(MyLinkList* list, MyLinkListNode* node, int pos);
//
///**
// *  获取链表节点
// *
// *  @param list 链表
// *  @param pos  位置
// *
// *  @return 节点首地址
// */
//MyLinkListNode * LinkList_Get(MyLinkList * list, int pos);
//
///**
// *  链表的删除
// *
// *  @param list 链表
// *  @param pos  位置
// *
// *  @return 删除的节点
// */
//MyLinkListNode * LinkList_Delete(MyLinkList * list, int pos);
//
//
//
//
//#endif /* MyLinkList_h */
