#include "BinTree.h"

//函数实现
////////////////////////////////////////////////////////////////////

//创建二叉树节点
BNode BuyBinTree(DataType data)
{
	BNode NewNode = (pNode*)malloc(sizeof(pNode));

	NewNode->_data = data;
	NewNode->_pLeft = NULL;
	NewNode->_pright = NULL;

	return NewNode;
}

//创建二叉树
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


//前序遍历打印
void PrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);

		PrintBinTree(pRoot->_pLeft);

		PrintBinTree(pRoot->_pright);
	}
}

//中序遍历打印
void LPrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		LPrintBinTree(pRoot->_pLeft);

		printf("%c ", pRoot->_data);

		LPrintBinTree(pRoot->_pright);
	}
}
//后续遍历打印
void RPrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		RPrintBinTree(pRoot->_pLeft);

		RPrintBinTree(pRoot->_pright);

		printf("%c ", pRoot->_data);
	}
}


//非递归前序遍历打印

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
//非递归中序遍历打印

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
//非递归后续遍历打印
//方法一:两个栈来实现
//将二叉树以根->右->左的顺序存入一个栈中，然后输出这个栈。如同中序遍历一样
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
//后序非递归遍历方法二：
///方法二：记录节点的父亲节点，判断其是否已经处理过，避免重复处理
void PostOrderTraversal(BNode BT)
{
	if (BT == NULL)
		return;
	stack<BNode> s;
	BNode Prev = NULL, Curr = NULL;     //初始化
	s.push(BT);
	while (!s.empty())
	{
		Curr = s.top();        //将栈顶元素赋给Curr
		if (Prev == NULL || Prev->_pLeft == Curr || Prev->_pright == Curr) //若Prev为NULL或是Curr的父节点
		{
			if (Curr->_pLeft != NULL)
				s.push(Curr->_pLeft);
			else if (Curr->_pright != NULL)
				s.push(Curr->_pright);
		}
		else if (Curr->_pLeft == Prev)    //若Prev是Curr的左儿子
		{
			if (Curr->_pright != NULL)
				s.push(Curr->_pright);
		}
		else
		{
			printf("%c ", Curr->_data);    //访问当前节点
			s.pop();    //访问后弹出
		}
		Prev = Curr;    //处理完当前节点后将Curr节点变为Prev节点
	}
}


//层序遍历打印 
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
}




//拷贝二叉树--深拷贝（赋值拷贝）
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

//销毁二叉树
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


//返回节点数目
int SizeBinTree(BNode pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}

	return 1 + SizeBinTree(pRoot->_pLeft) + SizeBinTree(pRoot->_pright);
}