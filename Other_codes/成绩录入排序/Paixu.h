#ifndef __Paixu_h_
#define __Paicu_h_

#include<stdio.h>

typedef int DataType;
typedef struct Node
{
	struct Node* _pNext;
	DataType _sno;
	DataType _score;
	int _size;
}Grade,*PGrade;

void InitGrade(PGrade* grade);

#endif

//��ʼ��
void InitGrade(PGrade* grade)
{
	*grade = NULL;
}
//�����½ڵ�
PGrade BuyNewGrade(DataType sno, DataType score)
{
	PGrade NewGrade = (PGrade)malloc(sizeof(Grade));

	NewGrade->_pNext = NULL;
	NewGrade->_score = score;
	NewGrade->_sno = sno;
	return NewGrade;
}

//����
void PushGrade(PGrade* grade, DataType sno, DataType score)
{
	if (*grade == NULL)
		*grade = BuyNewGrade(sno,score);
	else
	{
		PGrade pCur = *grade;
		while (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = BuyNewGrade(sno,score);
	}
}

//��ӡ
void PrintGrade(PGrade* grade)
{
	PGrade pCur = *grade;
	while (pCur)
	{
		printf("ѧ��:%d    ", pCur->_sno);
		printf("�ɼ�:%d    \n", pCur->_score);
		pCur = pCur->_pNext;
	}


}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectGrade(PGrade* grade)
{
	PGrade Min = *grade;
	PGrade Tmp = Min->_pNext;
	while (Min)
	{
		while (Tmp)
		{
			if (Tmp->_score < Min->_score)
			{
				Swap(&(Tmp->_sno), &(Min->_sno));
				Swap(&(Tmp->_score), &(Min->_score));
			}
			Tmp = Tmp->_pNext;
		}
		Min = Min->_pNext;
		if (Min->_pNext)
		{
			Tmp = Min->_pNext;
		}
		else
		{
			break;
		}
	}
}