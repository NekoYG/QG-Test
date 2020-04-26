#include"LinkStack.h"
#include<stdlib.h>

Status initLStack(LinkStack* s) 
{
	LinkStackPtr head;
	head = new StackNode;
	head->next = 0;
	s->top = head;
	s->count = 0;

	return SUCCESS;
};//初始化栈


Status isEmptyLStack(LinkStack* s)
{
	if (s->top->next == 0)
		return SUCCESS;
	else
		return ERROR;
};//判断栈是否为空


Status getTopLStack(LinkStack* s, ElemType* e) 
{
	*e = s->top->data;
	return SUCCESS;
};//得到栈顶元素


Status clearLStack(LinkStack* s)
{
	
	while(isEmptyLStack(s) == ERROR)
	{
			LinkStackPtr p;
			p = s->top;
			s->top = s->top->next;
			free(p);
	}
		return SUCCESS;
};//清空栈


Status destroyLStack(LinkStack* s)
{
	clearLStack(s);
	free(s->top);

	return SUCCESS;
};//销毁栈


Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;

	return SUCCESS;
};//检测栈长度


Status pushLStack(LinkStack* s, ElemType data) 
{
	LinkStackPtr p = 0;
	p = new StackNode;
	p->next = s->top;
	p->data = data;
	s->top = p;
	s->count++;
	return SUCCESS;
};//入栈


Status popLStack(LinkStack* s, ElemType* data)
{
	if (isEmptyLStack(s) == ERROR)
	{
		*data = s->top->data;
		LinkStackPtr p = s->top;
		s->top = s->top->next;
		free(p);
	}
	return SUCCESS;
};//出栈