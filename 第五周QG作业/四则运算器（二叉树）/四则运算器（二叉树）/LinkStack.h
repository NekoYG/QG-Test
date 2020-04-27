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
//链栈
Status initLcharStack(LinkcharStack *s);//初始化栈
Status isEmptyLcharStack(LinkcharStack*s);//判断栈是否为空
Status getTopLcharStack(LinkcharStack*s,char *e);//得到栈顶元素
Status clearLcharStack(LinkcharStack*s);//清空栈
Status destroyLcharStack(LinkcharStack*s);//销毁栈
Status LStackcharLength(LinkcharStack*s,int *length);//检测栈长度
Status pushLcharStack(LinkcharStack*s,char data);//入栈
Status popLcharStack(LinkcharStack*s,char *data);//出栈



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

Status initLdStack(LinkdStack* s);//初始化栈
Status isEmptyLdStack(LinkdStack* s);//判断栈是否为空
Status getTopLdStack(LinkdStack* s, BiTree* data);//得到栈顶元素
Status clearLdStack(LinkdStack* s);//清空栈
Status destroyLdStack(LinkdStack* s);//销毁栈
Status LStackdLength(LinkdStack* s, int* length);//检测栈长度
Status pushLdStack(LinkdStack* s, BiTree* data);//入栈
BiTree* popLdStack(LinkdStack* s);//出栈

#endif 
