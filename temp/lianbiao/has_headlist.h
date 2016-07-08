#ifndef _HAS_HEAD_LIST_H_
#define _HAS_HEAD_LIST_H_

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node *next;
};


//初始化一个链表
void init_list(struct node **head_p);

//创建一个节点
struct node *make_node(int data);

//释放一个节点
void free_node(struct node *node);

//插入一个节点（头）
int insert_node_from_begin(struct node *head, struct node* node);


//插入一个节点(尾)
int insert_node_to_end(struct node *head, struct node* node);

//查找一个节点
struct node *search(struct node *head, int data);

//删除一个节点
int delete_node(struct node *head, struct node *del_node);

//销毁整个链表
void destory_list(struct node **head_p);

//遍历链表
void print_list(struct node *head);



#endif