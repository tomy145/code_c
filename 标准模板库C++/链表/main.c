//
//  main.c
//  链表
//
//  Created by Mac on 16/6/15.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include "SLinkList.h"

int main(int argc, const char * argv[])
{

    SqList list;

    InitList(&list);

    for (int i = 0; i < 5; i++)
    {
        char c = i + 'a';
        Node *node = makeANode(c);

        ListInsert(&list, 0, node);
    }

    printList(&list);

    Node node;

    GetElem(&list, 3, &node);

    printf("node value = %c\n",(char)node.data);

    printList(&list);

    Node *deleteNode = ListDelete(&list, 2);;

    if (deleteNode != NULL)
    {
        free(deleteNode);
    }

    ClearList(&list);


    printList(&list);


    printf(" --------------------end --------\n");
    return 0;
}
