#pragma once

#include <malloc.h>
#include <iostream>
#include <string>
using namespace std;

#ifndef __BSTREE_H__
#define __BSTREE_H__



#define MaxSize 15
typedef char ElemType;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;



typedef struct {
	BiTree data[MaxSize];
	int front, rear;
} SqQueue;


class BsTree {
public:
	void delAllNode(BiTree& T);
	bool CreateBiTree(BiTree& T);
	bool PreOrder(BiTree& T);
	bool InOrder(BiTree& T);
	bool PostOrder(BiTree& T);
	void InitQueue(SqQueue& Q);
	bool IsEmpty(SqQueue& Q);
	bool EnQueue(SqQueue& Q, BiTree x);
	bool DeQueue(SqQueue& Q, BiTree& x);
	void LeverOrder(BiTree& T);
};


#endif