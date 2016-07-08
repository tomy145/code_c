////
////  list.c
////  temp
////
////  Created by Mac on 16/5/15.
////  Copyright © 2016年 Mac. All rights reserved.
////
//
//#include "list.h"
//#include <stdlib.h>
//#include <stdio.h>
//
//
//SqList * List_Create(int capacity)
//{
//    List *list = NULL;
//
//    if (capacity >0)
//    {
//        list = (List *)calloc(capacity, sizeof(List) + sizeof(ListNode)); //开辟线性表节点空间
//
//    }
//
//    if (list != NULL)
//    {
//        //初始化数据
//        list->capacity = capacity;
//        list->length = 0;
//        list->node = (ListNode *)(list + 1);
//    }
//
//
//    return  list;
//}
//
//void SqList_Destroy(SqList  * list)
//{
//    free(list);
//}
//
//
//
//void SqList_Clear(SqList  * list)
//{
//    List *li = (List *)list;
//
//    if (li != NULL)
//    {
//        li->length = 0;
//    }
//
//}
//
//int SqList_Length(SqList  * list)
//{
//    int ret = -1;
//    List *li = (List *)list;
//    if (li != NULL) //判断线性表是否合法
//    {
//        ret = li->length;
//    }
//
//    return ret;
//}
//
///**
// *  获取线性表容量
// *
// *  @param list 线性表
// *
// *  @return 容量
// */
//int SqList_Capacity(SqList  * list)
//{
//    int cap = -1;
//
//    List *li = (List *)list;
//
//    if (li != NULL)
//    {
//        cap = li->capacity;
//    }
//
//    return cap;
//}
//
//
//
//int SqList_Insert(SqList  * list, SqListNode* node, int pos)
//{
//
//    List *li = (List *)list;
//    int ret = -1;
//
//    ret = (li != NULL) && ((li->length + 1) <= li->capacity); //判断线性表长度是否合法，线性表是否合法
//    ret = ret && (pos >= 0); //判断位置是否合法
//
//    if (ret)
//    {
//        if (pos >= li->length)
//        {
//            pos = li->length;
//        }
//
//        int i = 0;
//        for (i = li->length; i > pos; --i)
//        {
//            li->node[i - 1] = li->node[i]; //循环移动
//        }
//
//        li->node[i] = (ListNode)node; //移动到位置相等
//
//        li->length +=1; //长度增加
//    }
//    
//
//
//    return ret;
//
//}
//
//SqListNode* SqList_Get(SqList  * list, int pos)
//{
//    List *li = (List *)list;
//
//    SqListNode *node = NULL;
//
//    if ((li != NULL ) && ((0 < pos) && pos <= li->length)) //线性表合法并且位置合法
//    {
//        node = (SqListNode *)&li->node[pos]; //取出节点
//    }
//
//
//    return node;
//}
//
//SqListNode* SqList_Delete(SqList  * list, int pos)
//{
//    List *li = (List *)list;
//
//    SqListNode *ret = SqList_Get(list, pos); //先取出节点
//
//    if (ret != NULL) //节点存在
//    {
////        //出列
//        int i = 0;
//        for(i = pos+1; i<li->length; i++)
//        {
//            li->node[i-1] = li->node[i];
//        }
//
//        li->length -=1; //长度减一
//    }
//
//    
//
//
//    return ret;
//}