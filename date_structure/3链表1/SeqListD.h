#ifndef __SeqListD_h_
#define __SeqListD_h_
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef int DataType;
typedef unsigned int size_t;

typedef struct SeqListD
{
	DataType* _array;
	size_t _capacity;
	size_t _size;
}SeqListD,*PSeqListD;




void Init(PSeqListD pSeq);
void PushBack(PSeqListD pSeq, DataType data);
void PopBack(PSeqListD pSeq);
int CheckCapacity(PSeqListD pSeq);
void Print(PSeqListD pSeq);





#endif


void Init(PSeqListD pSeq)
{
	if (NULL == pSeq)
		return;
	/*pSeq->_array = NULL;
	pSeq->_capacity = 0;
	pSeq->_size = 0;*/

	pSeq->_array = (DataType*)malloc(3 * sizeof(DataType));
	if (NULL == pSeq->_array)
		return;
	pSeq->_capacity = 3;
	pSeq->_size = 0;
}

void PushBack(PSeqListD pSeq,DataType data)
{
	if (pSeq == NULL)
		return;
	if (!CheckCapacity(pSeq))
		return;

	pSeq->_array[pSeq->_size++] = data;

}


void PopBack(PSeqListD pSeq)
{
	if (pSeq == NULL)
		return;
	pSeq->_size--;
}

//检查内存是否溢出，如果溢出则动态开辟内存
//int CheckCapacity(PSeqListD pSeq)
//{
//	if (NULL == pSeq)
//		return 0;
//	if (pSeq->_size == pSeq->_capacity)
//	{
//		//扩容
//		size_t newCapacity = pSeq->_capacity * 2;
//		DataType* pTemp = (DataType*)malloc(newCapacity*sizeof(DataType));
//		if (NULL == pTemp)
//			return 0;
//
//		//搬移旧空间的元素
//		memcpy(pTemp, pSeq->_array, pSeq->_size*sizeof(DataType));
//
//		free(pSeq->_array);
//
//		pSeq->_array = pTemp;
//		pSeq->_capacity = newCapacity;
//
//	}
//	return 1;
//}

void Print(PSeqListD pSeq)
{
	if (pSeq == NULL)
		return;
	int i;
	for (i = 0; i <= pSeq->_size; i++)
	{
		printf("%d ", pSeq->_array[i]);
	}
	printf("\n");
}

int CheckCapacity(PSeqListD pSeq)
{
	if (pSeq == NULL)
		return 0;
	if (pSeq->_size == pSeq->_capacity)
	{
		size_t NewCapacity = pSeq->_capacity * 2;
		DataType* pTmp = (DataType*)malloc(NewCapacity*sizeof(DataType));

		if (pTmp == NULL)
			return 0;

		memcpy(pTmp,pSeq->_array,pSeq->_size*sizeof(DataType));

		free(pSeq->_array);


		pSeq->_array = pTmp;
		pSeq->_capacity = NewCapacity;
	}
	return 1;
}