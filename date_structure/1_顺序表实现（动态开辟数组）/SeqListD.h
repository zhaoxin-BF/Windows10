#ifndef __SeqListD_h_
#define __SeqListD_h_

#include<stdio.h>
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

void SeqListDInit(PSeqListD pSeq);
void SeqListDPushBack(PSeqListD pSeq,DataType data);
void SeqListDPopBack(PSeqListD pSeq);
int SeqListDEmpty(PSeqListD pSeq);
int SeqListDSize(PSeqListD pSeq);
void SeqListDClear(PSeqListD pSeq);
int SeqListDCapacity(PSeqListD pSeq);
void SeqListDDestroy(PSeqListD pSeq);
int CheckCapacity(PSeqListD pSeq);
void PrintSeqListD(PSeqListD pSeq);


#endif

void SeqListDInit(PSeqListD pSeq)
{
	if (NULL == pSeq)
		return;

	pSeq->_array = (DataType*)malloc(3 * sizeof(DataType));
	if (NULL == pSeq->_array)
		return;

	pSeq->_capacity = 3;
	pSeq->_size = 0;
}

void SeqListDPushBack(PSeqListD pSeq, DataType data)
{
	if (NULL == pSeq)
		return;

	if (!CheckCapacity(pSeq))
		return;

	pSeq->_array[pSeq->_size] = data;

	pSeq->_size++;
}

void SeqListDPopBack(PSeqListD pSeq)
{
	if (NULL == pSeq)
		return;

	if (SeqListDEmpty(pSeq))
		return;

	pSeq->_size--;
}

int SeqListDEmpty(PSeqListD pSeq)
{
	return pSeq->_size == 0;
}

int SeqListDSize(PSeqListD pSeq)
{
	return pSeq->_size;
}

void SeqListDClear(PSeqListD pSeq)
{
	pSeq->_size = 0;
}
int SeqListDCapacity(PSeqListD pSeq)
{
	return pSeq->_capacity;
}
void SeqListDDestroy(PSeqListD pSeq)
{
	if (pSeq->_array)
	{
		free(pSeq->_array);
		pSeq->_capacity = 0;
		pSeq->_size = 0;
	}
}

int CheckCapacity(PSeqListD pSeq)
{
	if (NULL == pSeq)
		return 0;

	if (pSeq->_capacity == pSeq->_size)
	{
		size_t newCapacity = pSeq->_capacity * 2;
		DataType* pTemp = (DataType*)malloc(newCapacity*sizeof(DataType));
		if (NULL == pTemp)
			return 0;

		memcpy(pTemp,pSeq->_array,pSeq->_size*sizeof(DataType));
		
		free(pSeq->_array);

		pSeq->_array = pTemp;
		pSeq->_capacity = newCapacity;
	}
	return 1;
}

void PrintSeqListD(PSeqListD pSeq)
{

	for (int i = 0; i < pSeq->_size; i++)
	{
		printf("%d ", pSeq->_array[i]);
	}
	printf("\n");
}