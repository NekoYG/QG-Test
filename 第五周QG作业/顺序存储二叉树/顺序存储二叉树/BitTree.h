#pragma once
#include <iostream>
using namespace std;

#ifndef __BITTREE_H__
#define __BITTREE_H__


#define MAX_NODE_SIZE 100         //二叉树的最大节点数
typedef char SqBiTree[MAX_NODE_SIZE + 1];        //0号单元节点个数


class BitTree {
public:
	void creat_tree(SqBiTree& t);

	//获取给定结点（位置）的左孩子的结点位置
	int LeftChild_locate(SqBiTree& t, int node);

	//获取给定结点（位置）的右孩子的结点位置
	int RightChild_locate(SqBiTree& t, int node);

	//层序遍历
	void level_order(SqBiTree& t);

	//先序遍历
	void pre_order(SqBiTree& t, int i);

	//中序遍历
	void mid_order(SqBiTree& t, int i);

	//后序遍历
	void back_order(SqBiTree& t, int i);
};


#endif