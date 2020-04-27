#include"LinkStack.h"
#include<stdlib.h>

Status initLcharStack(LinkcharStack* s)
{
	LinkcharStackPtr head;
	head = new StackcharNode;
	head->next = 0;
	s->top = head;
	s->count = 0;

	return SUCCESS;
};//��ʼ��ջ


Status isEmptyLcharStack(LinkcharStack* s)
{
	if (s->top->next == 0)
		return SUCCESS;
	else
		return ERROR;
};//�ж�ջ�Ƿ�Ϊ��


Status getTopLcharStack(LinkcharStack* s, char* e)
{
	*e = s->top->data;
	return SUCCESS;
};//�õ�ջ��Ԫ��


Status clearLcharStack(LinkcharStack* s)
{
	
	while(isEmptyLcharStack(s) == ERROR)
	{
			LinkcharStackPtr p;
			p = s->top;
			s->top = s->top->next;
	}
		return SUCCESS;
};//���ջ


Status destroyLcharStack(LinkcharStack* s)
{
	clearLcharStack(s);
	free(s->top);

	return SUCCESS;
};//����ջ


Status LStackcharLength(LinkcharStack* s, int* length)
{
	*length = s->count;

	return SUCCESS;
};//���ջ����


Status pushLcharStack(LinkcharStack* s, char data)
{
	LinkcharStackPtr p;
	p = new StackcharNode;
	p->next = s->top;
	p->data = data;
	s->top = p;
	s->count++;
	return SUCCESS;
};//��ջ


Status popLcharStack(LinkcharStack* s, char* data)
{
	if (isEmptyLcharStack(s) == ERROR)
	{
		LinkcharStackPtr p = s->top;
		*data = s->top->data;
		s->top = s->top->next;
		delete p;
	}
	return SUCCESS;
};//��ջ






Status initLdStack(LinkdStack* s)
{
	LinkdStackPtr head;
	head = new StackdNode;
	head->next = 0;
	s->top = head;
	s->count = 0;

	return SUCCESS;
};//��ʼ��ջ


Status isEmptyLdStack(LinkdStack* s)
{
	if (s->top->next == 0)
		return SUCCESS;
	else
		return ERROR;
};//�ж�ջ�Ƿ�Ϊ��


Status getTopLdStack(LinkdStack* s, BiTree* data)
{
	data = s->top->data;
	return SUCCESS;
};//�õ�ջ��Ԫ��


Status clearLdStack(LinkdStack* s)
{

	while (isEmptyLdStack(s) == ERROR)
	{
		LinkdStackPtr p;
		p = s->top;
		s->top = s->top->next;
		free(p);
	}
	return SUCCESS;
};//���ջ



Status destroyLdStack(LinkdStack* s) 
{
	clearLdStack(s);
	free(s->top);

	return SUCCESS;
};//����ջ


Status LStackdLength(LinkdStack* s, int* length)
{
	*length = s->count;

	return SUCCESS;
};//���ջ����


Status pushLdStack(LinkdStack* s, BiTree*data)
{
	LinkdStackPtr p;
	p = new StackdNode;
	p->next = s->top;
	p->data = data;
	s->top = p;
	s->count++;
	return SUCCESS;
};//��ջ


BiTree* popLdStack(LinkdStack* s)
{
	BiTree* data=0;
	if (isEmptyLdStack(s) == ERROR)
	{
		LinkdStackPtr p = s->top;
		data = s->top->data;
		s->top = s->top->next;
		delete p;
	}
	return data;
};//��ջ