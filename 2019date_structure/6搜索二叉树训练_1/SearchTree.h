#ifndef _SEARCHTREE_H__
#define _SEARCHTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int _BSTDataType;

typedef struct BSTreeNode
{
	_BSTDataType _data;
	struct BSTreeNode * _left;
	struct BSTreeNode * _right;
}BSTNode, *BSTree;

int Insert_BSTree(BSTree* tree, _BSTDataType data);
int Remove_BSTree(BSTree* tree, _BSTDataType data);
void InOrder_BSTree(BSTree* tree);
BSTree Find_BSTree(BSTree* tree, _BSTDataType data);
#endif

BSTree BuyTreeNode(_BSTDataType data)
{
	BSTree NowNode = (BSTree)malloc(sizeof(BSTNode));
	NowNode->_data = data;
	NowNode->_left = NULL;
	NowNode->_right = NULL;
	return NowNode;
}

int Insert_BSTree(BSTree* tree, _BSTDataType data)
{
	BSTree parent = NULL,cur;
	if (*tree == NULL)
	{
		*tree = BuyTreeNode(data);
	}
	cur = *tree;
	while (cur)
	{
		if (cur->_data > data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
			return 0;
	}
	if (parent->_data>data)
		parent->_left = BuyTreeNode(data);
	else
	{
		parent->_right = BuyTreeNode(data);
	}
	return 1;
}

void InOrder_BSTree(BSTree *tree)
{
	if (*tree == NULL)
	{
		return;
	}
	InOrder_BSTree(&((*tree)->_left));
	printf("%d ", (*tree)->_data);
	InOrder_BSTree(&((*tree)->_right));
}

BSTree Find_BSTree(BSTree* tree, _BSTDataType data)
{
	BSTree cur = *tree;
	while (cur)
	{
		if (cur->_data < data)
		{
			cur = cur->_right;
		}
		else if (cur->_data > data)
		{
			cur = cur->_left;
		}
		else
		{
			return cur;
		}
	}
	return NULL;
}

int Remove_BSTree(BSTree* tree, _BSTDataType data)//删除
{

	BSTree cur = *tree;
	BSTree parent = *tree;
	BSTree del = NULL;

	while (cur)
	{
		if (cur->_data > data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			del = cur;
			if (cur->_left == NULL) //1、左孩子为空
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else if (parent->_right == cur)
					parent->_right = cur->_right;
				else if (parent == cur) //没有父亲节点时
					*tree = parent->_right;
			}
			else if (cur->_right == NULL) //2、右孩子为空
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else if (parent->_right == cur)
					parent->_right = cur->_left;
				else if (parent == cur) //没有父亲节点时
					*tree = parent->_left;
			}
			else//3、左右孩子都不为空
			{
				BSTree sub = cur->_right;
				while (sub->_left)
				{
					parent = sub;
					sub = sub->_left;
				}

				del = sub;
				cur->_data = sub->_data;

				if (parent->_left == sub)
					parent->_left = sub->_right;
				else
					parent->_right = sub->_right;
			}

			free(del);
			del = NULL;
			return 0;

		}
	}
	return -1;
}