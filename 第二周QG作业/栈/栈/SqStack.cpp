#include"SqStack.h"
#include<iostream>
using namespace std;

Status initStack(SqStack* s, int sizes)
{
	s->elem = new int[sizes];
	s->size =sizes;
	s->top = -1;
	cout << "��ʼ��ջ��ɣ�" << endl;
	return SUCCESS;
};//��ʼ��ջ


Status isEmptyStack(SqStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->top == -1)
	{
		cout << "��⣺��ջΪ��ջ." << endl;
		return SUCCESS;
	}
	else
	{
		cout << "��⣺��ջ��Ϊ��ջ." << endl;
		return ERROR;
	}
};


Status isFullStack(SqStack* s)
{
	if (s->top == (s->size - 1))
	{
		cout << "��⣺��ջ������" << endl;
		return SUCCESS;
	}
	else
		cout << "��⣺��ջδ���ɼ�����ջ." << endl;
		return ERROR;
};//�ж�ջ�Ƿ�Ϊ��

Status getTopStack(SqStack* s, ElemType* e) 
{
	*e = s->elem[s->top+1];
	return SUCCESS; 
}; //�õ�ջ��Ԫ��


Status clearStack(SqStack* s) 
{
	while (s->top > -1)
		s->top--;
	cout << "ջ����գ�" << endl;
	return SUCCESS;
};//���ջ


Status destroyStack(SqStack* s) 
{
	delete s;
	cout << "ջ�����٣�" << endl;
	return SUCCESS;
};//����ջ


Status stackLength(SqStack* s, int* length) 
{
	*length = s->size;
	return SUCCESS;
};//���ջ����


Status pushStack(SqStack* s, ElemType data) 
{
	if (isFullStack(s) == ERROR)
	{
		s->elem[s->top+1] = data;
		s->top++;
		cout << "��ջ��ɣ�" << endl;
		return SUCCESS;
	}
};//��ջ


Status popStack(SqStack* s, ElemType* data) 
{
	if (isEmptyStack(s) == ERROR)
	{
		*data = s->elem[s->top+1];
		s->top--;
		cout << "��ջ��ɣ�" << endl;
		return SUCCESS;
	}
};//��ջ