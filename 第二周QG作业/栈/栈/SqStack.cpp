#include"SqStack.h"
#include<iostream>
using namespace std;

Status initStack(SqStack* s, int sizes)
{
	s->elem = new int[sizes];
	s->size =sizes;
	s->top = -1;
	cout << "初始化栈完成！" << endl;
	return SUCCESS;
};//初始化栈


Status isEmptyStack(SqStack* s)//判断栈是否为空
{
	if (s->top == -1)
	{
		cout << "检测：该栈为空栈." << endl;
		return SUCCESS;
	}
	else
	{
		cout << "检测：该栈不为空栈." << endl;
		return ERROR;
	}
};


Status isFullStack(SqStack* s)
{
	if (s->top == (s->size - 1))
	{
		cout << "检测：该栈已满！" << endl;
		return SUCCESS;
	}
	else
		cout << "检测：该栈未满可继续入栈." << endl;
		return ERROR;
};//判断栈是否为满

Status getTopStack(SqStack* s, ElemType* e) 
{
	*e = s->elem[s->top+1];
	return SUCCESS; 
}; //得到栈顶元素


Status clearStack(SqStack* s) 
{
	while (s->top > -1)
		s->top--;
	cout << "栈已清空！" << endl;
	return SUCCESS;
};//清空栈


Status destroyStack(SqStack* s) 
{
	delete s;
	cout << "栈已销毁！" << endl;
	return SUCCESS;
};//销毁栈


Status stackLength(SqStack* s, int* length) 
{
	*length = s->size;
	return SUCCESS;
};//检测栈长度


Status pushStack(SqStack* s, ElemType data) 
{
	if (isFullStack(s) == ERROR)
	{
		s->elem[s->top+1] = data;
		s->top++;
		cout << "入栈完成！" << endl;
		return SUCCESS;
	}
};//入栈


Status popStack(SqStack* s, ElemType* data) 
{
	if (isEmptyStack(s) == ERROR)
	{
		*data = s->elem[s->top+1];
		s->top--;
		cout << "出栈完成！" << endl;
		return SUCCESS;
	}
};//出栈