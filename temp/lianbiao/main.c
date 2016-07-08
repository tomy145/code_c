//
//  main.c
//  lianbiao
//
//  Created by Mac on 16/5/23.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include "LinkList.h"


int main(int argc, const char * argv[])
{

    LinkList *list = initList();

    for (int i = 0; i < 10; i++)
    {
        LinkListNode *node = makeLinkListNode(i + 'a');
        insertToLinkList_Head(&list, node);
//        insertToLinkList_Last(&list, node);
    }

    printLinkList(list);

//    destory_LinkList(list);

    int a = 'h';

    LinkListNode *node = getLinkListNodeFromLinkList(&list,&a);
//    deleteLinkListNode(&list, node);
//    freeLinkListNode(node);

    printLinkList(list);


    getchar();

    return 0;
}
