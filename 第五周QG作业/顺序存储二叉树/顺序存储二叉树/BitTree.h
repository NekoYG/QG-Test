#pragma once
#include <iostream>
using namespace std;

#ifndef __BITTREE_H__
#define __BITTREE_H__


#define MAX_NODE_SIZE 100         //�����������ڵ���
typedef char SqBiTree[MAX_NODE_SIZE + 1];        //0�ŵ�Ԫ�ڵ����


class BitTree {
public:
	void creat_tree(SqBiTree& t);

	//��ȡ������㣨λ�ã������ӵĽ��λ��
	int LeftChild_locate(SqBiTree& t, int node);

	//��ȡ������㣨λ�ã����Һ��ӵĽ��λ��
	int RightChild_locate(SqBiTree& t, int node);

	//�������
	void level_order(SqBiTree& t);

	//�������
	void pre_order(SqBiTree& t, int i);

	//�������
	void mid_order(SqBiTree& t, int i);

	//�������
	void back_order(SqBiTree& t, int i);
};


#endif