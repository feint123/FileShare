#ifndef _linkedqueue_h
#define _linkedqueue_h

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

typedef void * ElemType;

typedef struct QueueNode{
	struct QueueNode *next;
	ElemType data;
}qNode;

typedef struct LinkedQueue{
	qNode *rear;
	qNode *front;
}linkedqueue;

void initQueue(linkedqueue *queue){

	(*queue).front = (qNode *)malloc(sizeof(qNode));
	(*queue).rear = (qNode *)malloc(sizeof(qNode));
	(*queue).front->next = NULL;
	(*queue).rear->next = NULL;
}

bool emptyQueue(linkedqueue queue){
  	if (queue.front->next == NULL&&queue.rear->next == NULL)
		return true;
	else
		return false;
}

bool enQueue(linkedqueue queue, ElemType e){
	qNode *node = (qNode*)malloc(sizeof(qNode));
	node->data = e;
	if (emptyQueue(queue)){
		queue.front->next = node;
		queue.rear->next = node;
		return true;
	}
	queue.rear->next->next = node;
	queue.rear->next = node;

	return true;
}

ElemType deQueue(linkedqueue queue){
	if (emptyQueue(queue))
		return NULL;
	qNode *node = queue.front->next;
	if (node == queue.rear->next)
	{
		queue.front->next = NULL;
		queue.rear->next = NULL;
	}
	else{
		queue.front->next = node->next;
	}
	ElemType e = node->data;
	free(node);

	return e;
}

#endif