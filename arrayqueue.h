//#ifndef _ARRAYQUEUE_H
//#define _ARRAYQUEUE_H
//

#include<stdlib.h>
#include<stdbool.h>

#define INIT_SIZE 20

typedef void * ElemType;

typedef struct ArrayQueue{
	ElemType *data;
	//队尾指针
	int rear;
	//队首指针
	int front;
	int length;
	int maxSize;
}arrayqueue;

void initQueue(arrayqueue *queue){
	queue->data = (ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
	queue->front = 0;
	queue->rear = 0;
	queue->maxSize = INIT_SIZE;
	queue->length = 0;
}

void increaseQueue(arrayqueue *queue){
	if (queue->rear == queue->maxSize)
	{
		if (queue->length == queue->maxSize)
		{
			queue->maxSize *= 2;
			ElemType *temp = (ElemType *)malloc(queue->maxSize*sizeof(ElemType));
			for (int i = 0; i < queue->length; i++)
				temp[i] = queue->data[queue->front + i];
			queue->data = temp;
		}
		else{
			for (int i = 0; i < queue->length; i++)
				queue->data[i] = queue->data[queue->front + i];
		}
		queue->front = 0;
		queue->rear = queue->length;
	}
}

bool emptyQueue(arrayqueue queue){
	if (queue.front == queue.rear)
		return true;
	else
		return false;
}

/**
* 进队操作，队尾指针+1；
*/
bool enQueue(arrayqueue *queue,ElemType e){
	increaseQueue(queue);

	queue->data[queue->rear++]=e;
	queue->length++;
	
	return true;
}
/**
*  出对操作，队首指针+1；
*/
ElemType deQueue(arrayqueue *queue){
	ElemType e = queue->data[queue->front++];
	queue->length--;
	return e;
}

//#endif