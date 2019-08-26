#include "BinTree.h"

//����ʵ��
////////////////////////////////////////////////////////////////////

//�����������ڵ�
BNode BuyBinTree(DataType data)
{
	BNode NewNode = (pNode*)malloc(sizeof(pNode));

	NewNode->_data = data;
	NewNode->_pLeft = NULL;
	NewNode->_pright = NULL;

	return NewNode;
}

//����������
void CreateBinTree(BNode* pRoot, DataType array[], int size, int* index, DataType invalid)
{
	if ((*index < size) && (invalid != array[*index]))
	{
		*pRoot = BuyBinTree(array[*index]);

		++(*index);
		CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);

		++(*index);
		CreateBinTree(&(*pRoot)->_pright, array, size, index, invalid);
	}
}


//ǰ�������ӡ
void PrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);

		PrintBinTree(pRoot->_pLeft);

		PrintBinTree(pRoot->_pright);
	}
}

//���������ӡ
void LPrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		LPrintBinTree(pRoot->_pLeft);

		printf("%c ", pRoot->_data);

		LPrintBinTree(pRoot->_pright);
	}
}
//����������ӡ
void RPrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		RPrintBinTree(pRoot->_pLeft);

		RPrintBinTree(pRoot->_pright);

		printf("%c ", pRoot->_data);
	}
}


//�ǵݹ�ǰ�������ӡ

void goRoot(stack<BNode>& s, BNode pRoot)
{
	while (pRoot != NULL)
	{
		printf("%c ",pRoot->_data);
		s.push(pRoot);
		pRoot = pRoot->_pLeft;
	}
}

void FPrintBinTree(BNode pRoot)
{
	stack<BNode> s;
	if (pRoot == NULL)
	{
		return;
	}
	goRoot(s, pRoot);
	while (!s.empty())
	{
		BNode pCur = s.top();
		s.pop();
		if (pCur->_pright != NULL)
		{
			goRoot(s, pCur->_pright);
		}
	}
}
//�ǵݹ����������ӡ

void goLeft(stack<BNode> &s,BNode pRoot)
{
	while (pRoot != NULL)
	{
		s.push(pRoot);
		pRoot = pRoot->_pLeft;
	}
}

void FLPrintBinTree(BNode pRoot)
{
	stack<BNode> s;
	if (pRoot == NULL)
		return;

	goLeft(s, pRoot);

	while (!s.empty())
	{
		BNode pCur = s.top();

		printf("%c ",pCur->_data);
		s.pop();
		if (pCur->_pright != NULL)
			goLeft(s, pCur->_pright);
	}
}
//�ǵݹ����������ӡ
//����һ:����ջ��ʵ��
//���������Ը�->��->���˳�����һ��ջ�У�Ȼ��������ջ����ͬǰ�����һ�����Ҹ�-��������
void goLR(stack<BNode>& s1, BNode pRoot)
{
	while (pRoot != NULL)
	{
		s1.push(pRoot);
		pRoot = pRoot->_pright;
	}
}
void FRPrintBinTree(BNode pRoot)
{
	stack<BNode> s1;
	stack<BNode> s2;
	if (pRoot == NULL)
		return;

	goLR(s1, pRoot);
	goLR(s2, pRoot);
	while (!s2.empty())
	{
		BNode pCur = s2.top();
		s2.pop();

		if (pCur->_pLeft != NULL)
		{
			goLR(s1, pCur->_pLeft);
			goLR(s2, pCur->_pLeft);
		}

	}
	while (!s1.empty())
	{
		printf("%c ",s1.top()->_data);
		s1.pop();
	}
}
/////////////////////
//����ǵݹ������������
///����������¼�ڵ�ĸ��׽ڵ㣬�ж����Ƿ��Ѿ�������������ظ�����
void PostOrderTraversal(BNode BT)
{
	if (BT == NULL)
		return;
	stack<BNode> s;
	BNode Prev = NULL, Curr = NULL;     //��ʼ��
	s.push(BT);
	while (!s.empty())
	{
		Curr = s.top();        //��ջ��Ԫ�ظ���Curr
		if (Prev == NULL || Prev->_pLeft == Curr || Prev->_pright == Curr) //��PrevΪNULL����Curr�ĸ��ڵ�
		{
			if (Curr->_pLeft != NULL)
				s.push(Curr->_pLeft);
			else if (Curr->_pright != NULL)
				s.push(Curr->_pright);
		}
		else if (Curr->_pLeft == Prev)    //��Prev��Curr�������
		{
			if (Curr->_pright != NULL)
				s.push(Curr->_pright);
		}
		else
		{
			printf("%c ", Curr->_data);    //���ʵ�ǰ�ڵ�
			s.pop();    //���ʺ󵯳�
		}
		Prev = Curr;    //�����굱ǰ�ڵ��Curr�ڵ��ΪPrev�ڵ�
	}
}


//���������ӡ 
void LevelBinTree(BNode pRoot)
{
	queue<BNode> q;

	q.push(pRoot);

	while (!q.empty())
	{
		BNode pCur = q.front();
		printf("%c ", pCur->_data);
		q.pop();

		if (pCur->_pLeft)
			q.push(pCur->_pLeft);

		if (pCur->_pright)
			q.push(pCur->_pright);
	}
	printf("\n");
}




//����������--�������ֵ������
BNode CopyBinTree(BNode pRoot)
{
	BNode newpRoot = NULL;
	if (pRoot)
	{
		newpRoot = BuyBinTree(pRoot->_data);

		newpRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		newpRoot->_pright = CopyBinTree(pRoot->_pright);
	}
	return newpRoot;
}

//���ٶ�����
void DestoryBinTree(BNode* pRoot)
{
	if (*pRoot)
	{
		DestoryBinTree(&(*pRoot)->_pLeft);

		DestoryBinTree(&(*pRoot)->_pright);

		free(*pRoot);

		*pRoot = NULL;
	}
}


//���ؽڵ���Ŀ
int SizeBinTree(BNode pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}

	return 1 + SizeBinTree(pRoot->_pLeft) + SizeBinTree(pRoot->_pright);
}

//�ֲ��ӡ�������ڵ�
void LevelPrintBinTree(BNode pRoot)
{

	if (NULL == pRoot)
		return;
	queue<BNode> node;
	node.push(pRoot);
	int nextLevel = 0, toBeprinted = 1;
	while (!node.empty())
	{
		BNode pNode = node.front();
		printf("%c ", pNode->_data);
		if (NULL != pNode->_pLeft)
		{
			node.push(pNode->_pLeft);
			nextLevel++;
		}
		if (NULL != pNode->_pright)
		{
			node.push(pNode->_pright);
			nextLevel++;
		}
		node.pop();
		toBeprinted--;
		if (0 == toBeprinted)
		{
			printf("\n");
			toBeprinted = nextLevel;
			nextLevel = 0;
		}
	}
	printf("\n");
}
//���ض������ĸ߶�
int HighBinTree(BNode pRoot)
{
	if (pRoot == NULL)
		return 0;
	int L = HighBinTree(pRoot->_pLeft);
	int R = HighBinTree(pRoot->_pright);

	return (L > R) ? L : R + 1;

	//return (HighBinTree(pRoot->_pLeft) > HighBinTree(pRoot->_pright)) ? HighBinTree(pRoot->_pLeft) : HighBinTree(pRoot->_pright) + 1;
}
//����Ҷ�ӽ�����
//��������������Ϊ�գ��򷵻� 1��������ҽ�㲻Ϊ�գ��ͷ�������������Ҷ�ӽ��ͣ�
int SizeLeafNode(BNode pRoot)
{
	if (pRoot == NULL)
		return 0;
	if (pRoot->_pLeft == NULL && pRoot->_pright == NULL)
	{
		return 1;
	}
	else
	{
		return SizeLeafNode(pRoot->_pLeft) + SizeLeafNode(pRoot->_pright);
	}
}
//��ӡҶ�ӽ��
void PrintLeafNode(BNode pRoot)
{
	if (pRoot)
	{
		if (pRoot->_pLeft == NULL && pRoot->_pright == NULL)
			printf("%c ", pRoot->_data);
		PrintLeafNode(pRoot->_pLeft);
		PrintLeafNode(pRoot->_pright);
	}
	return;
}