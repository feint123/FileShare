//#ifndef _CARRAYQUEUE_H
//#define _CARRAYQUEUE_H
//
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#define INIT_SIZE 20

typedef void* ElemType;
typedef struct CArrayQueue{
	ElemType *data;
	int maxSize;
	int length;
	int rear;
	int front;
} carrayqueue;

void initQueue(carrayqueue *queue){
	queue->data = (ElemType *)malloc(sizeof(ElemType)*INIT_SIZE);
	queue->maxSize = INIT_SIZE;
	queue->length = 0;
	queue->rear = 0;
	queue->front = 0;
}

bool emptyQueue(carrayqueue queue){
	if (queue.front == queue.rear)
		return true;
	else
		return false;
}

void increaseQueue(carrayqueue *queue){
	if (queue->length == queue->maxSize)
	{

		printf("increase size\n");
		queue->maxSize *= 2;
		ElemType *temp = (ElemType *)malloc(sizeof(ElemType)*queue->maxSize);
		for (int i = 0; i < queue->length; i++){
			temp[(queue->front+i)%(queue->maxSize)] = queue->data[(queue->front + i) % (queue->maxSize / 2)];
		}
		queue->rear = (queue->front + queue->length) % queue->maxSize;
		queue->data = temp;
	}
}

bool enQueue(carrayqueue *queue,ElemType e){
	increaseQueue(queue);
	++queue->length;
	queue->data[queue->rear] = e;
	queue->rear = (queue->rear + 1) % queue->maxSize;
	return true;
}

ElemType deQueue(carrayqueue *queue){
	ElemType e = queue->data[queue->front];
	queue->front = (queue->front + 1)%queue->maxSize;
	--queue->length;
	return e;
}

//#endif