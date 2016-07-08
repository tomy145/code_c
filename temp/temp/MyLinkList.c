////
////  MyLinkList.c
////  temp
////
////  Created by Mac on 16/5/15.
////  Copyright © 2016年 Mac. All rights reserved.
////
//
//#include "MyLinkList.h"
//
//
///**
// *  链表的创建
// *
// *  @return 链表首地址
// */
//MyLinkList* LinkList_Create()
//{
//    MyLinkList *list = calloc(1, sizeof(MyLinkList));
//
//    if (list != NULL)
//    {
//        list->length = 0;
//        list->next = NULL;
//    }
//
//    return list;
//}
//
///**
// *  链表的销毁
// *
// *  @param list 链表首地址
// */
//void LinkList_Destroy(MyLinkList* list)
//{
//    if (list != NULL)
//    {
//        free(list);
//    }
//
//}
//
///**
// *  链表的清空
// *
// *  @param list 链表首地址
// */
//void LinkList_Clear(MyLinkList* list)
//{
//    if (list != NULL)
//    {
//        list->length = 0;
//        while (list->next != NULL)
//        {
//            free(list->next);
//        }
//        list->next = NULL;
//    }
//}
//
///**
// *  获取链表长度
// *
// *  @param list 链表
// *
// *  @return 长度
// */
//int LinkList_Length(MyLinkList* list)
//{
//    int ret = -1;
//    if (list != NULL)
//    {
//       ret = list->length;
//    }
//
//    return ret;
//}
//
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
//int LinkList_Insert(MyLinkList* list, MyLinkListNode* node, int pos)
//{
//    int ret = -1;
//
//    ret = (list != NULL);
//    ret = (node != NULL) && (pos >= 0 && pos <= list->length);
//
//    int i = 0;
//
//    if (ret)
//    {
//        MyLinkListNode *current = (MyLinkListNode *)list;
//
//        for (i = 0; (i < pos && i < list->length); i++)
//        {
//            current = current->next; //指向下一个节点
//        }
//
//        node->next = current->next;
//        current->next = node;
//        ++list->length;
//    }
//
//
//    return ret;
//
//}
//
///**
// *  获取链表节点
// *
// *  @param list 链表
// *  @param pos  位置
// *
// *  @return 节点首地址
// */
//MyLinkListNode * LinkList_Get(MyLinkList * list, int pos)
//{
//    MyLinkListNode *ret = NULL;
//
//    if (list != NULL && (pos >=0 && pos < list->length)) //链表合法，位置合法
//    {
//        MyLinkListNode *current = (MyLinkListNode *)list;
//        for (int i = 0; i < pos; i++)
//        {
//            current = current->next;
//        }
//
//        ret = current->next;
//    }
//
//    return ret;
//}
//
//
//
///**
// *  链表的删除
// *
// *  @param list 链表
// *  @param pos  位置
// *
// *  @return 删除的节点
// */
//MyLinkListNode * LinkList_Delete(MyLinkList * list, int pos)
//{
//    MyLinkListNode *ret = NULL;
//
//    if (list != NULL && (pos >=0 && pos < list->length)) //链表合法，位置合法
//    {
//
//        MyLinkListNode *current = (MyLinkListNode *)list;
//
//        for (int i = 0; i < pos; i++)
//        {
//            current = current->next;
//        }
//
//        ret = current->next;
//
//        current->next = ret->next;
//
//        //长度减一
//        --list->length;
//
//    }
//
//
//    return ret;
//}
//
