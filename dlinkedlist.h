#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void* ElemType;

typedef struct DNode{
	struct DNode *prior;
	struct DNode *next;
	ElemType data;
}dnode,*dlinkedlist;

typedef int bool;
#define false 0
#define true 1


dlinkedlist createList(dlinkedlist *list)
{
	(*list) = (dlinkedlist)malloc(sizeof(dnode));
	(*list)->next = NULL;
	return (*list);
}

dlinkedlist createCirList(dlinkedlist *list)
{
	(*list) = (dlinkedlist)malloc(sizeof(dnode));
	(*list)->next = (*list);
	return (*list);
}

dnode *getElement(dlinkedlist list ,int index)
{

	if (index == -1)
		return list;
	else if (index<-1)
		return NULL;
	else{
		dnode *temp = list;
		int current = -1;
		while (temp&&current < index)
		{
			temp = temp->next;
			current++;
		}
		return temp;
	}

}

ElemType getValue(dlinkedlist list,int index)
{
	dnode *res = getElement(list, index);
	if (res == NULL)
		return NULL;
	else
		return res->data;
}

bool insertList(dlinkedlist list,ElemType e,int index){
	dnode *ni = getElement(list, index-1);
	if (ni == NULL)
		return false;
	dnode *node = (dnode *)malloc(sizeof(dnode));
	node->data = e;
	if (ni->next!=NULL)
		ni->next->prior = node;
	node->next = ni->next;
	ni->next = node;
	node->prior = ni;
	return true;
}

ElemType deleteList(dlinkedlist list, int index){
	dnode *ni = getElement(list, index);
	ni->prior->next = ni->next;
	ni->next->prior = ni->prior;
	ElemType e = ni->data;
	free(ni);
	return e;
}
