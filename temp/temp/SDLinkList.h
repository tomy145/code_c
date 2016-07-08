//
//  SDLinkList.h
//  temp
//
//  Created by Mac on 16/5/15.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef SDLinkList_h
#define SDLinkList_h

#include <stdio.h>
#include <stdlib.h>

typedef void  SDLinkList;
typedef struct _tag_SDLinkListNode SDLinkListNode;

struct _tag_SDLinkListNode
{
    SDLinkListNode *next;
};



SDLinkList * LinkList_init();

void LinkList_Destroy(SDLinkList *list);

void LinkList_Clear(SDLinkList *list);

int LinkList_GetLength(SDLinkList *list);

int LinkList_Insert(SDLinkList *list , SDLinkListNode *node , int poss);

SDLinkListNode *LinkList_GetNode(SDLinkList *list , int poss);

SDLinkListNode *LinkList_Delete(SDLinkList *list, int poss);

#endif /* SDLinkList_h */
