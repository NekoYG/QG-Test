#include"LQueue.h"
#include<stdio.h>
#include <stdlib.h>

int main()
{
	printf("��Ҫ�ȳ�ʼ����ʽ���У�\n");
	system("pause");
	system("cls");
	LQueue* LQ = (LQueue*)malloc(sizeof(LQueue));

	InitLQueue(LQ);
	system("pause");
	while (1)
	{
		system("cls");
		printf("������������������������������������������������������\n");
		printf("��ѡ��Ҫ�Զ��н��еĲ�����\n");
		printf("������������������������������������������������������\n");
		printf("1    ���\n");
		printf("2    ����\n");
		printf("3    ��ն���\n");
		printf("4    �鿴��ͷԪ��\n");
		printf("5    ��ȡ���г���\n");
		printf("6    ��������\n");
		printf("0    �˳����Զ�ɾ�����У�\n");
		printf("��������������Ĭ��ѡ���˳�\n");
		printf("������������������������������������������������������\n");
		int temp;
		scanf_s("%d", &temp);
		switch (temp)
		{
		case  1:
		{
			system("cls");
			printf("������������������������������������������������������\n");
			printf("��ѡ��洢Ԫ�ص����ͣ�\n");
			printf("������������������������������������������������������\n");
			printf("1    int��\n");
			printf("2    char��\n");
			printf("3    double��\n");
			printf("4    srting��\n");
			printf("��������������Ĭ��ѡ��int��\n");
			printf("������������������������������������������������������\n");
			void* dat;
			int temp;
			int typeSize;
			scanf_s("%d", &temp);
			getchar();
			switch (temp)//ȷ�Ϸ���
			{
				case  1:
				{
					int* t = (int*)malloc(sizeof(int));
					type = 'i';
					typeSize = sizeof(int);
					printf("������int�����ݣ�\n");
					scanf_s("%d",t);
					dat = t;
					datatype[LQ->length] = type;
					break;
				}
				case  2:
				{
					char* t= (char*)malloc(sizeof(char));
					type = 'c';
					typeSize = sizeof(char);
					printf("������char�����ݣ�\n");
					*t = getchar();
					dat = t;
					datatype[LQ->length] = type;
					break;
				}
				case  3:
				{
					double* t= (double*)malloc(sizeof(double));
					type = 'd';
					typeSize = sizeof(double);
					printf("������double�����ݣ�\n");
					scanf_s("%lf",t);
					dat = t;
					datatype[LQ->length] = type;
					break;
				}
				case 4:
				{
					char* t=(char*)malloc(sizeof(char));
					type = 's';
					typeSize = sizeof(char)*100;
					printf("������string��\n");
					scanf_s("%s",t);
					dat = t;
					datatype[LQ->length] = type;
					break;
				}
				default:
				{
					int* t = (int*)malloc(sizeof(int));
					type = 'i';
					typeSize = sizeof(int);
					printf("������int�����ݣ�\n");
					scanf_s("%d", t);
					dat = t;
					datatype[LQ->length] = type;
					break;
				}
			}
			EnLQueue(LQ,dat,typeSize);
			printf("���������.\n");
			break;
		}
		case  2:
		{
			DeLQueue(LQ);
			printf("���Ӳ������.\n");
			break;
		}
		case  3:
		{
			ClearLQueue(LQ);
			printf("���������.\n");
			break;
		}
		case  4:
		{
			void* head = NULL;
			GetHeadLQueue(LQ, head);
			LPrint(head,datatype[0]); break;
		}
		case  5:
		{
			printf("���г���Ϊ��%d\n", LengthLQueue(LQ));
			break;
		}
		case  6:
		{
			void (*foo)(void* q,char size);
			foo = LPrint;
			TraverseLQueue(LQ, foo);
			break;
		}
		case  0: 
			DestoryLQueue(LQ);
			return 0;
		default: 
			DestoryLQueue(LQ);
			return 0;
		}
		system("pause");

	}

	return 0;
}