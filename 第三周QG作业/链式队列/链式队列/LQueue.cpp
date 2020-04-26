#include"LQueue.h"
#include <malloc.h>
#include<stdio.h>
#include<string.h>

char type;
char datatype[30];

void InitLQueue(LQueue* Q)
{	
	Q->front = Q->rear = NULL;
	Q->length = 0;
	printf("链式队列初始化完成.\n");
	return;
};


void DestoryLQueue(LQueue* Q)
{

	//从队头开始遍历队列
	Node* p = Q->front;
	while (p != NULL)
	{
		Node* q = p->next;
		free(p);
		p = q;
	}

	printf("链式队列已经销毁.\n");
	return;

};



Status IsEmptyLQueue(const LQueue* Q)
{
	return (Q->front == NULL ? TRUE : FALSE);
};



Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (IsEmptyLQueue(Q))
	{
		printf("链式队列为空队列.\n");
		return FALSE;
	}
	e = Q->front->data;
	return TRUE;
};



int LengthLQueue(LQueue* Q)
{
	return Q->length;
};


Status EnLQueue(LQueue* Q, void* data,int size)
{
	Node* p = (Node*)malloc(sizeof(Node));

	p->data = (void*)malloc(size);
	memcpy(p->data, data,size);
	p->next = NULL;
	if (Q->front == NULL)
	{
		Q->front = Q->rear = p;
		Q->length++;
		return TRUE;
	}
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return TRUE;

};



Status DeLQueue(LQueue* Q)
{

	if (IsEmptyLQueue(Q))
	{
		printf("队列为空，不可出队\n");
		return FALSE;
	}

	Node* p = Q->front;
	Q->front = Q->front->next;
	free(p);
	Q->length--;
	return TRUE;

};



void ClearLQueue(LQueue* Q)
{

	if (IsEmptyLQueue(Q))
		return;
	Node* p=NULL, * q=NULL;
	Q->rear = Q->front;
	p = Q->front;
	while (NULL != p->next) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	Q->rear = Q->front = NULL;
	Q->length = 0;
	return;

};



Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,char size))
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p = Q->front;

	int i = 1;
	while (p != NULL) {
		if (i % 5 == 0) printf("\n");
		foo(p->data,datatype[i-1]);
		p = p->next;
		i++;
	}
	printf("\n");
	return TRUE;
};



void LPrint(void* q,char size)
{
	if (size == 'd')//size = 8
		printf("%lf", *(double*)q);
	if (size == 'c')//size = 1
		printf("%c", *(char*)q);
	if (size =='i')//size = 4
		printf("%d", *(int*)q);
	if (size == 's')//size = 4
		printf("%s", *(char*)q);
	printf("-<");
};