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
//将二叉树以根->右->左的顺序存入一个栈中，然后输出这个栈。如同前序遍历一样左右根-》根右左
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
	printf("\n");
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

//分层打印二叉树节点
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
//返回二叉树的高度
int HighBinTree(BNode pRoot)
{
	if (pRoot == NULL)
		return 0;
	int L = HighBinTree(pRoot->_pLeft);
	int R = HighBinTree(pRoot->_pright);

	return (L > R) ? L : R + 1;

	//return (HighBinTree(pRoot->_pLeft) > HighBinTree(pRoot->_pright)) ? HighBinTree(pRoot->_pLeft) : HighBinTree(pRoot->_pright) + 1;
}
//返回叶子结点个数
//如果结点左右子树为空，则返回 1，如果左右结点不为空，就返回左右子树的叶子结点和；
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
//打印叶子结点
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