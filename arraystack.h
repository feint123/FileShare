#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define INIT_SIZE 100
typedef void * ElemType;
typedef struct ArrayStack
{
	int top;
	ElemType* data;
	int maxSize;

}arraystack;

#define true 1
#define false 0

void initStack(arraystack *stack)
{
	stack->top = -1;
	stack->maxSize = INIT_SIZE;
	stack->data= (ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
}

void increaseStack(arraystack *stack){
	ElemType *dupData = (ElemType *)malloc(stack->maxSize * 2*sizeof(ElemType));
	stack->maxSize *= 2;
	for (int i = 0; i <= stack->top; i++)
		dupData[i] = stack->data[i];
	//free(stack->data);
	stack->data = dupData;
}

int push(arraystack *stack,ElemType e)
{
	if ((++stack->top) >= stack->maxSize)
		increaseStack(stack);

	stack->data[stack->top] = e;
	return true;
}

int emptyStack(arraystack stack)
{
	if (stack.top == -1)
		return true;
	else
		return false;
}

ElemType pop(arraystack *stack)
{
	if (emptyStack(*stack))
		return NULL;
	ElemType e = stack->data[stack->top--];
	return e;
}

#endif