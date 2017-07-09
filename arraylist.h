#define INIT_LEN 20
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�����б�Ԫ��
typedef void* ElemType;

/*
�����б�Ľṹ
length����¼�б�ĳ���
maxsize����¼�б�ǰʱ�̵���󳤶�
data���洢�б���
*/

typedef struct List{
	int length;
	int maxsize;
	ElemType* data;
} ArrayList;

/*
��ʼ���б�
1. ���б�����Ϊ0
2. Ϊdata����һ����СΪ INIT_LEN*sizeof(ElemType) �Ŀռ�
*/
void initList(ArrayList* list)
{
	list->length = 0;
	list->maxsize = INIT_LEN;
	int size = (list->maxsize)*sizeof(ElemType);
	list->data = malloc(size);

}

/*
��չ�б�Ĵ洢�ռ�
*/
void incressList(ArrayList *list)
{
	
	list->maxsize *= 2;
	ElemType *cpdata = malloc(list->maxsize*sizeof(ElemType));
	for (int i = 0; i < list->length; i++)
	{
		cpdata[i] = list->data[i];
	}
	ElemType *del = list->data;
	list->data = cpdata;
	free(del);
}
/*
��λ��index����Ԫ��e������ԭ�б��λ��i��ʼ��Ԫ��ȫ�������һλ
*/
int insertElem(ArrayList *list, int index, ElemType e)
{
	if (index > list->length||index<0)
		return 0;

	else
	{
		//���ڲ�����Ԫ��֮ǰ���б�ĳ����Ѵﵽ�б���󳤶ȣ�����б��������
		if (list->length+1 >= list->maxsize)
		{
			incressList(list);
		}

		for (int i = list->length; i >index; i--)
		{

			list->data[i] = list->data[i-1];
		}

		list->data[index] = e;
		//Ԫ�ز���ɹ����б���+1
		++list->length ;
		return 1;
	}
}
/*
ɾ��λ��index����Ԫ�أ������б��index+1��ʼ��Ԫ��ȫ����ǰ��һλ��
����ɾ����Ԫ�ص�ֵ���� ele
*/
int deleteElem(ArrayList *list, int index, ElemType *ele)
{
	if (index > list->length || index<0)
		return 0;
	else
	{
		*ele = list->data[index];
		for (int i = index; i < list->length-1; i++)
		{
			list->data[i] = list->data[i + 1];
		}

		--list->length;
	}
}

/*
��ȡλ��index����Ԫ�ص�ֵ
*/
ElemType getElem(ArrayList list, int index)
{
	if (index > list.length-1)
		return NULL;
	else
		return list.data[index];
}

int length(ArrayList list)
{
	return list.length;
}

void printList(ArrayList list)
{
	for (int i = 0; i < list.length; i++)
	{
		printf("(%d)\t%d\n", i, list.data[i]);
	}
}
/*
�����б��ͷ��б���е��ڴ�ռ䡣
*/
void destoryList(ArrayList *list)
{
	free(list->data);
	free(list);
}

