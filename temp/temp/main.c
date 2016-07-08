////
////  main.c
////  temp
////
////  Created by Mac on 16/5/14.
////  Copyright © 2016年 Mac. All rights reserved.
////
//
//#include<stdio.h>
//#include <stdlib.h>
//#include "SDLinkList.h"
////
//// struct Value
////{
////    SDLinkListNode *next;
////
////    char buf[10];
////
////    int value;
////
////
////};
////
////void test1(void)
////{
////    SDLinkList *list = LinkList_init();
////    struct Value *vbus[5];
////
////    for (int i = 0; i < 5; i++)
////    {
////        struct Value *v1 = ( struct Value *)calloc(1, sizeof( struct Value));
////        v1->buf[0] = i + 'a';
////        v1->value = i;
////        LinkList_Insert(list, (SDLinkListNode *)v1, 0);
////        vbus[i] = v1;
////    }
////
////    for (int i = 0; i < 5; i++)
////    {
////        SDLinkListNode * node = LinkList_GetNode(list, i);
////        struct Value *v2 = (struct Value *)(node);
////        printf("v2.buf--- %c\n",v2->buf[0]);
////        printf("v2.value--- %d\n",v2->value);
////
////    }
////
////
////    //释放内存
////    for (int i = 0; i < 5; i++)
////    {
////        free(vbus[i]);
////    }
////    
////    
////    free(list);
////}
//
//
