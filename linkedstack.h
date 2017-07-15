#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H

//if you want to use stack with a header ,please remove this define
#define _NO_HEADER
#include<stdio.h>
#include<stdlib.h>

#define true 1;
#define false 0;

typedef void* ElemType;

typedef struct StackNode{
	struct StackNode *next;
	ElemType data;
}snode, *linkedstack;


#ifdef _NO_HEADER
void initStack(linkedstack *stack)
{
	(*stack) = NULL;
}
int push(linkedstack* stack, ElemType e)
{
	snode *node = (snode*)malloc(sizeof(snode));
	node->data = e;
	node->next =(*stack);
	(*stack) = node;
	return true;
}
ElemType pop(linkedstack* stack){
	snode *node = (*stack);
	if (node == NULL)
		return NULL;
	(*stack) = node->next;
	ElemType e = node->data;
	free(node);
	return e;
}
int emptyStack(linkedstack stack)
{
	if (stack == NULL){
		return true;
	}
	else
		return false;
}
#else
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

int push(linkedstack stack, ElemType e)
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

#endif


#endif