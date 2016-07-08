//
//  main.c
//  链表
//
//  Created by Mac on 16/6/18.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SLinkList.h"

typedef struct _tag_Person
{

    Node node;

    int age;

}Person;


//遍历线性表
void printsSLinkList(SLinkList *list)
{

    printf(" ------ printLinkList ---- \n");
    if (list == NULL || list->length == 0)
    {
        return;
    }

    int len = list->length;

    Node *pCur = &list->header;

    for (int i = 1; i < len + 1; ++i)
    {
        if (pCur->next != NULL)
        {

            pCur = pCur->next;
            Person *p1 = (Person *)pCur;
            printf("age = %d\n",p1->age);
        }
    }

    printf("---------- printLinkList End------ \n");
}


int main(int argc, const char * argv[])
{

    SLinkList list;

    list.type = CreatType_malloc;
    //初始化OK
    InitList(&list);


    //插入OK
    for (int i = 0; i < 3; ++i)
    {
        Person *p1 = calloc(1, sizeof(Person));
        p1->age = i + 'a';
        ListInsert(&list, 0, &p1->node);
    }


    printsSLinkList(&list);

    Node *node;

    //GET --- OK
    GetElem(&list, 0, &node);

    Person *p2 = (Person *)node;

    printf("p2.age = %d\n",p2->age);


    if (ListEmpty(&list) != 0)
    {
        printf("链表非空 --- \n");
    }


    ClearList(&list);

    return 0;
}
