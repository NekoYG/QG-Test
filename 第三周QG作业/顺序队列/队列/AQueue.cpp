#include"AQueue.h"
#include <malloc.h>
#include <stdio.h>
#include<string.h>

void InitAQueue(AQueue* Q)
{
	int i;
	Q->length = MAXQUEUE;
	for (i = 0; i < MAXQUEUE; i++)
	{
		Q->data[i] = (void*)malloc(20);
		Q->type[i] = 0;
	}
	Q->front = Q->rear = 0;
	printf("初始化完成.\n");
};



void DestoryAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("错误报告：队列未初始化\n");
		return;
	}
	for (int i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	Q->data[0] = NULL;
	printf("销毁完成.\n");
	return;
};


Status IsFullAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("错误报告：队列未初始化\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
		return FALSE;
	if (LengthAQueue(Q) ==( MAXQUEUE - 1))
	{
		return TRUE;
	}
	else
		return FALSE;
};


Status IsEmptyAQueue(const AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("错误报告：队列未初始化\n");
		return FALSE;
	}
	return(Q->front == Q->rear ? TRUE : FALSE);
};


Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (Q->data[0] == NULL)
	{
		printf("错误报告：队列未初始化\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		printf("检测：队列为空，无队头.\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front], 20);
	return TRUE;
};


int LengthAQueue(AQueue* Q)
{
	return (Q->rear - Q->front + Q->length) % Q->length;
};


Status EnAQueue(AQueue* Q, void* data)
{
	if (IsFullAQueue(Q))
	{
		printf("错误报告：队列已满,不可继续入队.\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		memcpy(Q->data[Q->front], data, 20);
		Q->rear = (Q->rear + 1) % Q->length;
		return TRUE;
	}
	memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % Q->length;
	return TRUE;
};


Status DeAQueue(AQueue* Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("错误报告：队列已空,不可继续出队.\n");
	}return FALSE;

	Q->front = (Q->front + 1) % MAXQUEUE;
	printf("已出队.\n");
	return TRUE;
};


void ClearAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("错误报告：队列未初始化\n");
		return;
	}
	if (IsEmptyAQueue(Q))
	{
		printf("错误报告：队列已清空.\n");
		return;
	}
	Q->front = Q->rear = 0;
	return;
};


Status TraverseAQueue(const AQueue* Q,void (*foo)(void* q, int typeData))
{
	if (Q->data[0] == NULL)
	{
		printf("队列目前未初始化！请先初始化队列！\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		printf("队列里面什么都没有!\n");
		return FALSE;
	}
	int i = 0;
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
		foo(Q->data[Q->front + i], Q->type[Q->front + i]);
		i = (i + 1) % MAXQUEUE;
	}
	return TRUE;
};


void APrint(void* q, int typeData)
{
	if (typeData == DOUBLE)
		printf("--> %.2lf", *(double*)q);
	if (typeData == CHAR)
		printf("--> %c", *(char*)q);
	if (typeData == INT)
		printf("--> %d ", *(int*)q);
	if (typeData == STRING)
		printf("--> %s ", (char*)q);

};