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
};//初始化栈


Status isEmptyLcharStack(LinkcharStack* s)
{
	if (s->top->next == 0)
		return SUCCESS;
	else
		return ERROR;
};//判断栈是否为空


Status getTopLcharStack(LinkcharStack* s, char* e)
{
	*e = s->top->data;
	return SUCCESS;
};//得到栈顶元素


Status clearLcharStack(LinkcharStack* s)
{
	
	while(isEmptyLcharStack(s) == ERROR)
	{
			LinkcharStackPtr p;
			p = s->top;
			s->top = s->top->next;
	}
		return SUCCESS;
};//清空栈


Status destroyLcharStack(LinkcharStack* s)
{
	clearLcharStack(s);
	free(s->top);

	return SUCCESS;
};//销毁栈


Status LStackcharLength(LinkcharStack* s, int* length)
{
	*length = s->count;

	return SUCCESS;
};//检测栈长度


Status pushLcharStack(LinkcharStack* s, char data)
{
	LinkcharStackPtr p;
	p = new StackcharNode;
	p->next = s->top;
	p->data = data;
	s->top = p;
	s->count++;
	return SUCCESS;
};//入栈


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
};//出栈






Status initLdStack(LinkdStack* s)
{
	LinkdStackPtr head;
	head = new StackdNode;
	head->next = 0;
	s->top = head;
	s->count = 0;

	return SUCCESS;
};//初始化栈


Status isEmptyLdStack(LinkdStack* s)
{
	if (s->top->next == 0)
		return SUCCESS;
	else
		return ERROR;
};//判断栈是否为空


Status getTopLdStack(LinkdStack* s, BiTree* data)
{
	data = s->top->data;
	return SUCCESS;
};//得到栈顶元素


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
};//清空栈



Status destroyLdStack(LinkdStack* s) 
{
	clearLdStack(s);
	free(s->top);

	return SUCCESS;
};//销毁栈


Status LStackdLength(LinkdStack* s, int* length)
{
	*length = s->count;

	return SUCCESS;
};//检测栈长度


Status pushLdStack(LinkdStack* s, BiTree*data)
{
	LinkdStackPtr p;
	p = new StackdNode;
	p->next = s->top;
	p->data = data;
	s->top = p;
	s->count++;
	return SUCCESS;
};//入栈


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
};//出栈