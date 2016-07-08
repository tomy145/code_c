#ifndef _LINKLIST_H
#define _LINKLIST_H

#if 0
typedef int ElemType;
// 节点结构体
typedef struct NODE
{
    ElemType data;	// 数据
    struct NODE *next;	// 指向后继节点的指针
}Node;

typedef struct LINKLIST
{
    int length;
    Node header;
}LinkList;


// 初始化，建立一个空的线性表L。
void InitList(LinkList *L);
// 若线性表为空，返回true，否则返回false
int ListEmpty(LinkList L);
// 将线性表清空
void ClearList(LinkList *L);
// 将线性表L中的第pos个位置的元素返回给e
void GetElem(LinkList L, int pos, int *e);
// 在线性表L中的第pos个位置插入新元素e
void ListInsert(LinkList *L, int pos, int e);
// 删除线性表L中的第pos个位置元素，并用e返回其值
void ListDelete(LinkList *L, int pos, int *e);
// 返回线性表L的元素个数
int ListLength(LinkList L);
// 销毁线性表
void DestroyList(LinkList *L);

#else

typedef int ElemType;
// 小链表节点
typedef struct NODE
{
    struct NODE *next;	// 指向后继节点的指针
}Node;


// 链表结构体
typedef struct LINKLIST
{
    int length;
    Node header;
}LinkList;

// 初始化，建立一个空的线性表L。
void InitList(LinkList *L);
// 若线性表为空，返回true，否则返回false
int ListEmpty(LinkList L);
// 将线性表清空
void ClearList(LinkList *L);
// 将线性表L中的第pos个位置的元素返回给e
void GetElem(LinkList L, int pos, Node **e);
// 在线性表L中的第pos个位置插入新元素e
void ListInsert(LinkList *L, int pos, Node* e);
// 删除线性表L中的第pos个位置元素，并用e返回其值
void ListDelete(LinkList *L, int pos, Node **e);
// 返回线性表L的元素个数
int ListLength(LinkList L);
// 销毁线性表
void DestroyList(LinkList *L);

#endif

#endif	// _LINKLIST_H