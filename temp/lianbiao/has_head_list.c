#include "has_headlist.h"


void init_list(struct node **head_p)
{
	struct node *head = NULL;

	if (head_p == NULL) {
		return;
	}

	head = (struct node *)malloc(sizeof(struct node));
	if (head == NULL) {
		return;
	}

	head->data = -1; //无意义
	head->next = NULL;//代表是空链表

	*head_p = head;
}

struct node *make_node(int data)
{
	struct node *new_node = NULL;

	new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node == NULL) {
		return NULL;
	}
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

//释放一个节点
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}

//插入一个节点(尾)
int insert_node_to_end(struct node *head, struct node* node)
{
	struct node* last_node = NULL;

	if (head == NULL || node == NULL) {
		return -1;
	}

	//找到last_node
    for (last_node = head; last_node->next != NULL; last_node = last_node->next);

	//让最后一个节点的下一个指针 指向 node就可以了
	last_node->next = node;


	node->next = NULL;

	return 0;
}

//遍历链表
void print_list(struct node *head)
{
	struct  node * p = NULL;

	if (head == NULL) {
		return;
	}


	for (p = head->next; p != NULL; p = p->next)
	{
		printf("%d\n", p->data);
	}
}

//插入一个节点（头）
int insert_node_from_begin(struct node *head, struct node* node)
{

	if (head == NULL || node == NULL) {
		return -1;
	}

	//让新节点的下一个的方向 跟head->next一样
	node->next = head->next;
	head->next = node;

	return 0;
}


//销毁整个链表
void destory_list(struct node **head_p)
{
	struct node *head = NULL;
	struct node *p = NULL;

	if (head_p == NULL) {
		return;
	}

	head = *head_p;

	//删除所有链表元素
	for (p = head->next; p != NULL;  ) {
		head->next = p->next;
		free_node(p);
		p = head->next;
	}

	//删除头结点本身
	free_node(head);
	*head_p = NULL;
}

//查找一个节点
struct node *search(struct node *head, int data)
{
	struct node *p = NULL;

	if (head == NULL) {
		return NULL;
	}

	for (p = head->next; p != NULL; p = p->next)
	{
		if (p->data == data) {
			//找到了data与之对应的节点 此时p就是这个节点的地址
			return p;
		}
	}

	return NULL;
}

//删除一个节点
int delete_node(struct node *head, struct node *del_node)
{
	struct node*p = NULL;

	if (head == NULL || del_node == NULL) {
		return -1;
	}


	//由于要通过p能够指向元素的前驱， 所以p应该从head开始遍历， 因为首元素的前驱就是head
	for (p = head; p->next != NULL; p = p->next) {
		if (p->next == del_node) {
			//此时找到了del_node的前驱节点，就是p
			p->next = del_node->next;
			free_node(del_node);
			break;
		}
	}


	return 0;
}