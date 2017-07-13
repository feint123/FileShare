#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INIT_SIZE 100
#define false 0
#define true 1

typedef int bool;
typedef void * ElemType;


//linkedlist 是一个指向ListNode的指针
typedef struct ListNode{
	ElemType value;
	struct ListNode* next;
} listnode,*linkedlist;

linkedlist createList(linkedlist* list){
	(*list) = (linkedlist)malloc(sizeof(listnode));
	(*list)->next = NULL;
	return (*list);
}

listnode *getElem(linkedlist list, int i)
{
	int j = -1;
	listnode *temp = list ;
	if (i == -1)
		return list;
	if (i < -1)
		return NULL;
	while (temp&&j < i)
	{
		temp = temp->next;
		j++;
	}
	return temp;
}
listnode *locateElem(linkedlist list, ElemType e)
{
	listnode *p = list->next;
	while (p&&p->value != e)
		p = p->next;

	return p;
}

bool listInsert(linkedlist list, ElemType e,int i)
{
	printf("addr insert:%d\n", &list);
	if (i < 0)
		return false;
	listnode *before = getElem(list, i-1);
	if (before == NULL)
		return false;
	listnode *new_node = (listnode *)malloc(sizeof(listnode));
	new_node->value = e;
	new_node->next = before->next;
	before->next = new_node;
	return true;
}

listnode * listDelete(linkedlist list, int i)
{
	if (i < 0)
		return NULL;
	listnode *before = getElem(list,i - 1);
	printf("addr list:%d\taddr before:%d\n", &list, &before);
	listnode *self;
	if (before == NULL||before->next==NULL)
		return NULL;
	self = before->next;
	if (before->next->next == NULL)
		before->next = NULL;
	else{
		before->next = self->next;
		printf("before next:%d\n", self->next->value);
	}
	return self;

}