#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_listnode
{
	int data;//数据域
	struct _tag_listnode *next;//保存下个一个结点的地址
}ListNode;


ListNode * createList()
{
	int num;
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));//头结点
	if (head == NULL)
	{
		printf("malloc error\n");
		return NULL;
	}

	head->next = NULL;
	printf("请输入链表中结点的数目：");
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		int tmp;
		scanf("%d", &tmp);//得到结点中数据

		ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
		if (newnode == NULL)
		{
			printf("malloc error\n");
			return NULL;
		}

		newnode->data = tmp;

		newnode->next = head->next;
		head->next = newnode;
	}

	return head;
}
int printList(ListNode *head)
{
	int ret = 0;
	ListNode *pcur = NULL;
	if (head == NULL)
	{
		ret = -1;
		return ret;
	}

	pcur = head->next;//pcur指向head的下一个结点

	while (pcur != NULL)
	{
		printf("%d ", pcur->data);
		pcur = pcur->next;//指针指向当前结点的下一个结点
	}
	return ret;
}

ListNode* findListNode(ListNode *head, int data)
{
	ListNode *pcur = NULL;
	if (head == NULL)
		return NULL;

	pcur = head->next;
	
	while (pcur != NULL)
	{
		if (pcur->data == data)
			return pcur;
		pcur = pcur->next;
	}

	return NULL;
}
int main(void)
{
	ListNode *head = createList();

	printList(head);

	ListNode *pres = findListNode(head, 5);
	if (pres == NULL)
	{
		printf("no found\n");
	}
	else
	{
		printf("found node data:%d\n", pres->data);
	}
	system("pause");
	return 0;
}
int main1(void)
{
	ListNode head, node1, node2, node3, node4, node5;

	head.next = &node1;
	node1.data = 11; node1.next = &node2;
	node2.data = 10; node2.next = &node3;
	node3.data = 23; node3.next = &node4;
	node4.data = 24; node4.next = &node5;
	node5.data = 13; node5.next = NULL;


	printList(&head);

	system("pause");
	return 0;
}