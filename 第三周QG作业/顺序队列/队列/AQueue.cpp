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
	printf("��ʼ�����.\n");
};



void DestoryAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("���󱨸棺����δ��ʼ��\n");
		return;
	}
	for (int i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	Q->data[0] = NULL;
	printf("�������.\n");
	return;
};


Status IsFullAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("���󱨸棺����δ��ʼ��\n");
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
		printf("���󱨸棺����δ��ʼ��\n");
		return FALSE;
	}
	return(Q->front == Q->rear ? TRUE : FALSE);
};


Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (Q->data[0] == NULL)
	{
		printf("���󱨸棺����δ��ʼ��\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		printf("��⣺����Ϊ�գ��޶�ͷ.\n");
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
		printf("���󱨸棺��������,���ɼ������.\n");
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
		printf("���󱨸棺�����ѿ�,���ɼ�������.\n");
	}return FALSE;

	Q->front = (Q->front + 1) % MAXQUEUE;
	printf("�ѳ���.\n");
	return TRUE;
};


void ClearAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("���󱨸棺����δ��ʼ��\n");
		return;
	}
	if (IsEmptyAQueue(Q))
	{
		printf("���󱨸棺���������.\n");
		return;
	}
	Q->front = Q->rear = 0;
	return;
};


Status TraverseAQueue(const AQueue* Q,void (*foo)(void* q, int typeData))
{
	if (Q->data[0] == NULL)
	{
		printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		printf("��������ʲô��û��!\n");
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