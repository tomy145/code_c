//
//  main.c
//  双向链表
//
//  Created by Mac on 16/6/19.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include "DLinkList.h"


typedef struct _tag_Person
{

    Node node;

    int age;

}Person;

int main(int argc, const char * argv[])
{

    DLinkList *list = DLinkList_Create();

    for (int i = 0; i < 3; ++i)
    {
        Person *p1 = calloc(1, sizeof(Person));

        p1->age = i + 1;

        DLinkList_Insert(list, &p1->node, 0);
    }


    int len = list->length;

    for (int i = 0; i < len; ++i )
    {
        Node *node = DLinkList_Next(list);

        Person *p1 = (Person *)node;

        printf("value = %d\n",p1->age);
    }

    //删除链表




    return 0;
}
