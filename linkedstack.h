//#ifndef _LINKEDSTACK_H
//#define _LINKEDSTACK_H
#include<stdio.h>
#include<stdlib.h>

#define true 1;
#define false 0;

typedef void* ElemType;

typedef struct StackNode{
	struct StackNode *next;
	ElemType data;
}snode, *linkedstack;


void initStack(linkedstack *stack)
{
	(*stack) = (linkedstack)malloc(sizeof(snode));
	(*stack)->next = NULL;
}

int emptyStack(linkedstack stack)
{
	if (stack->next == NULL){
		return true;
	}
	else
		return false;
}

int push(linkedstack stack,ElemType e)
{
	snode *node = (snode*)malloc(sizeof(snode));
	node->data = e;
	node->next = stack->next;
	stack->next = node;
	return true;
}

ElemType pop(linkedstack stack){
	snode *node = stack->next;
	if (node == NULL)
		return NULL;
	stack->next = node->next;
	ElemType e = node->data;
	free(node);
	return e;
}

//#endif