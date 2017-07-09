#define INIT_LEN 20
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义列表元素
typedef void* ElemType;

/*
定义列表的结构
length：记录列表的长度
maxsize：记录列表当前时刻的最大长度
data：存储列表项
*/

typedef struct List{
	int length;
	int maxsize;
	ElemType* data;
} ArrayList;

/*
初始化列表
1. 将列表长度置为0
2. 为data开辟一个大小为 INIT_LEN*sizeof(ElemType) 的空间
*/
void initList(ArrayList* list)
{
	list->length = 0;
	list->maxsize = INIT_LEN;
	int size = (list->maxsize)*sizeof(ElemType);
	list->data = malloc(size);

}

/*
扩展列表的存储空间
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
向位置index插入元素e，并将原列表从位置i开始的元素全部向后移一位
*/
int insertElem(ArrayList *list, int index, ElemType e)
{
	if (index > list->length||index<0)
		return 0;

	else
	{
		//若在插入新元素之前，列表的长度已达到列表最大长度，则对列表进行扩容
		if (list->length+1 >= list->maxsize)
		{
			incressList(list);
		}

		for (int i = list->length; i >index; i--)
		{

			list->data[i] = list->data[i-1];
		}

		list->data[index] = e;
		//元素插入成功，列表长度+1
		++list->length ;
		return 1;
	}
}
/*
删除位置index处的元素，并将列表从index+1开始的元素全部向前移一位。
将被删除的元素的值赋予 ele
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
获取位置index处的元素的值
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
销毁列表，释放列表持有的内存空间。
*/
void destoryList(ArrayList *list)
{
	free(list->data);
	free(list);
}

