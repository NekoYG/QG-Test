#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include"BinaryTree.h"
typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef struct  BiTree
{
	char data;
	struct BiTree* lchild;
	struct BiTree* rchild;
}BiTree;

typedef struct StackcharNode
{
	char data;
	struct StackcharNode* next;
}StackcharNode, *LinkcharStackPtr;

typedef struct  LinkcharStack
{
	LinkcharStackPtr top;
	int	count;
}LinkcharStack;
//��ջ
Status initLcharStack(LinkcharStack *s);//��ʼ��ջ
Status isEmptyLcharStack(LinkcharStack*s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLcharStack(LinkcharStack*s,char *e);//�õ�ջ��Ԫ��
Status clearLcharStack(LinkcharStack*s);//���ջ
Status destroyLcharStack(LinkcharStack*s);//����ջ
Status LStackcharLength(LinkcharStack*s,int *length);//���ջ����
Status pushLcharStack(LinkcharStack*s,char data);//��ջ
Status popLcharStack(LinkcharStack*s,char *data);//��ջ



typedef struct StackdNode
{
	BiTree* data;
	struct StackdNode* next;
}StackdNode, * LinkdStackPtr;

typedef struct  LinkdStack
{
	LinkdStackPtr top;
	int	count;
}LinkdStack;

Status initLdStack(LinkdStack* s);//��ʼ��ջ
Status isEmptyLdStack(LinkdStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLdStack(LinkdStack* s, BiTree* data);//�õ�ջ��Ԫ��
Status clearLdStack(LinkdStack* s);//���ջ
Status destroyLdStack(LinkdStack* s);//����ջ
Status LStackdLength(LinkdStack* s, int* length);//���ջ����
Status pushLdStack(LinkdStack* s, BiTree* data);//��ջ
BiTree* popLdStack(LinkdStack* s);//��ջ

#endif 
