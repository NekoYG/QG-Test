#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;



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
	double data;
	struct StackdNode* next;
}StackdNode, * LinkdStackPtr;

typedef struct  LinkdStack
{
	LinkdStackPtr top;
	int	count;
}LinkdStack;

Status initLdStack(LinkdStack* s);//初始化栈
Status isEmptyLdStack(LinkdStack* s);//判断栈是否为空
Status getTopLdStack(LinkdStack* s, double* e);//得到栈顶元素
Status clearLdStack(LinkdStack* s);//清空栈
Status destroyLdStack(LinkdStack* s);//销毁栈
Status LStackdLength(LinkdStack* s, int* length);//检测栈长度
Status pushLdStack(LinkdStack* s, double data);//入栈
Status popLdStack(LinkdStack* s, double* data);//出栈

#endif 
