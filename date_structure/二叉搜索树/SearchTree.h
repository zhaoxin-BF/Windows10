#ifndef __SearchTree_h_
#define __SearchTree_h_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int _BSTDataType;

typedef struct BSTreeType
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	_BSTDataType _data;
}BSTreeNode;

int Insert_BSTree(BSTreeNode** tree, _BSTDataType data);
int Remove_BSTree(BSTreeNode** tree,_BSTDataType data);
BSTreeNode * Find_BSTree(BSTreeNode ** tree,_BSTDataType data);
void InQrderBSTree(BSTreeNode** tree);

#endif