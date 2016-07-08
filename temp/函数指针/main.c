//
//  main.c
//  函数指针
//
//  Created by Mac on 16/5/24.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>

typedef void (*vp)();

void (func) ()
{
    printf("hello------- \n");
}

void funcB(int a , int b)
{
    printf("a --- %d ---- b --- %d\n",a,b);
}

int main(int argc, const char * argv[])
{
    void *p = NULL;

    p = func;

    vp p1 = &func;

    p1();

    getchar();



    

    return 0;
}


////打印一个节点
//void print_node(struct node *node) //void ()(struct node *)
//{
//    printf("%d\n", node->data);
//}

////给一个节点的数值自增1
//void add_node(struct node *node)
//{
//    node->data += 1;
//}

//
//void for_each(struct node *head, void(*fp)(struct node*))
//{
//    struct node *p;
//
//    for (p = head->next; p != NULL; p = p->next) {
//        //P 就代表一个节点
//        fp(p);
//    }
//}
