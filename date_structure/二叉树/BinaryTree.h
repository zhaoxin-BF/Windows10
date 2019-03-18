#ifndef __BinaryTree_h_
#define __BInaryTree_h_

#include<malloc.h>
#include<stdio.h>
#include<assert.h>
#include"Queue.h"
#include"Stack.h"

typedef char DataType;

typedef struct BintryTreeNode
{
	DataType _data;
	struct BintryTreeNode* _right;
	struct BintryTreeNode* _left;
}BTNode;


//a是一个数组
BTNode* BintryTreeCreate(DataType* a,int n,int* pi);
void BintryTreeDestroy(BTNode* root);

int BinrtyTreeSize(BTNode* root);
int BinrtyTreeLeafSize(BTNode* root);
int BIntryTreeKsize(BTNode* root);
BTNode* BintryTreeFind(BTNode* root,DataType data);

//递归遍历二叉树
void BintryTreePrevOrder(BTNode* root);
void BintryTreeInOrder(BTNode* root);
void BintryTreePostOrder(BTNode* root);
void BintryTreeLeveOrder(BTNode* root);
int BintryTreeComplete(BTNode* root);

//非递归遍历二叉树
void BintryTreePrevOderNonR(BTNode* root);
void BintryTreeInOderNonR(BTNode* root);
void BintryTreePostOrderNonR(BTNode* root);

#endif


BTNode* BuyBTNode(DataType data)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));

	node->_data = data;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

BTNode* BintryTreeCreate(DataType* a, int n, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);

		++(*pi);
		root->_left = BintryTreeCreate(a, n, pi);

		++(*pi);
		root->_right = BintryTreeCreate(a, n, pi);;

		return root;
	}
	else
		return NULL;
}


void BintryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BintryTreePrevOrder(root->_left);
	BintryTreePrevOrder(root->_right);
}

void BintryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BintryTreeInOrder(root->_left);
	printf("%c ",root->_data);
	BintryTreeInOrder(root->_right);
}

void BintryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BintryTreePostOrder(root->_left);
	BintryTreePostOrder(root->_right);
	printf("%c ",root->_data);
}

void BintryTreePrevOderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* Top;
	Stack s;
	InitStack(&s);

	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			printf("%c ",cur->_data);
			PushbackStack(&s,cur);
			cur = cur->_left;
		}

		Top = StackTop(&s);
		PopbackStack(&s);
		cur = Top->_right;
	}
	printf("\n");
}

void BintryTreeInOderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* Top;
	Stack s;
	InitStack(&s);

	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			PushbackStack(&s, cur);
			cur = cur->_left;
		}


		Top = StackTop(&s);
		PopbackStack(&s);
		printf("%c ",Top->_data);
		cur = Top->_right;
	}
	printf("\n");
}

void BintryTreePostOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* Top;
	BTNode* prev = NULL;
	Stack s;
	InitStack(&s);

	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			PushbackStack(&s, cur);
			cur = cur->_left;
		}

		Top = StackTop(&s);

		if (Top->_right == NULL || Top->_right == prev)
		{
			printf("%c ", Top->_data);
			prev = Top;
			PopbackStack(&s);
		}
		else
		cur = Top->_right;
	}
	printf("\n");
}


void BintryTreeLeveOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		_QTDataType Front = QueueFront(&q);
		printf("%c ",Front->_data);
		QueuePop(&q);

		if (Front->_left)
			QueuePush(&q,Front->_left);
		if (Front->_right)
			QueuePush(&q, Front->_right);
	}
	QueueDestry(&q);
}

int BintryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (QueueEmpty(&q) && QueueFront(&q) != '#')
	{
		_QTDataType Front = QueueFront(&q);
		QueuePop(&q);
		if (Front->_left)
			QueuePush(&q, Front->_left);
		else
			QueuePush(&q,'#');
		if (Front->_right)
			QueuePush(&q, Front->_right);
		else
			QueuePush(&q,'#');
	}

	while (QueueEmpty(&q))
	{
		if (QueueFront(&q) != '#')
			return 0;
		QueuePop(&q);
	}

	QueueDestry(&q);

	return 1;
}