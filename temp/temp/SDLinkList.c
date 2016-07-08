//
//  SDLinkList.c
//  temp
//
//  Created by Mac on 16/5/15.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "SDLinkList.h"

typedef struct _tag_LinkList
{
    SDLinkListNode header;
    int length;

} SD_LinkList;



SDLinkList * LinkList_init()
{
    SD_LinkList *list = (SD_LinkList *)calloc(1, sizeof(SD_LinkList));

    if (list != NULL)
    {
        list->header.next = NULL;
        list->length = 0;
    }

    return list;
}

void LinkList_Destroy(SDLinkList *list)
{
    if (list != NULL)
    {
        free(list);
    }
}

void LinkList_Clear(SDLinkList *list)
{
    SD_LinkList *sList = (SD_LinkList *)list;
    if (sList != NULL)
    {
        sList->header.next = NULL;
        sList->length = 0;
    }
}


int LinkList_GetLength(SDLinkList *list)
{
    SD_LinkList *sList = (SD_LinkList *)list;

    int ret = -1;
    if (sList != NULL)
    {
        ret = sList->length;
    }

    return ret;
}

int LinkList_Insert(SDLinkList *list , SDLinkListNode *node , int poss)
{
    int ret = -1;

    SD_LinkList *sList = (SD_LinkList *)list;

    ret = (sList != NULL) && (node != NULL);
    ret = ret && (poss >= 0 && poss <= sList->length);

    if (ret)
    {
        int i = 0;
        SDLinkListNode *current = (SDLinkListNode *)sList;

        for (i = 0; i < poss ; ++i)
        {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;

        sList->length += 1;
    }



    return ret;
}

SDLinkListNode *LinkList_GetNode(SDLinkList *list , int poss)
{
    SDLinkListNode *node = NULL;

    SD_LinkList *sList = (SD_LinkList *)list;

    if (sList != NULL && (poss >=0 && poss <= sList->length))
    {
        SDLinkListNode *current = (SDLinkListNode *)sList;

        for (int i = 0; i < poss; ++i)
        {
            current = current->next;
        }

        node = current->next;
    }

    return node;
}



SDLinkListNode *LinkList_Delete(SDLinkList *list , int poss)
{

    SD_LinkList *sList = (SD_LinkList *)list;

    SDLinkListNode *node = NULL;

    if (sList != NULL && (poss >=0 && poss <= sList->length))
    {

        SDLinkListNode *current = (SDLinkListNode *)sList;
        for (int i = 0; i < poss; i++)
        {
            current = current->next;
        }

        node = current->next; //取出节点
        current->next = node->next;

        sList->length -= 1;
    }

    return node;
}