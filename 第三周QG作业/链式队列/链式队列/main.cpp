#include"LQueue.h"
#include<stdio.h>
#include <stdlib.h>

int main()
{
	printf("需要先初始化链式队列！\n");
	system("pause");
	system("cls");
	LQueue* LQ = (LQueue*)malloc(sizeof(LQueue));

	InitLQueue(LQ);
	system("pause");
	while (1)
	{
		system("cls");
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("请选择要对队列进行的操作：\n");
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("1    入队\n");
		printf("2    出队\n");
		printf("3    清空队列\n");
		printf("4    查看队头元素\n");
		printf("5    获取队列长度\n");
		printf("6    遍历队列\n");
		printf("0    退出（自动删除队列）\n");
		printf("输入其他数字则默认选择退出\n");
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		int temp;
		scanf_s("%d", &temp);
		switch (temp)
		{
		case  1:
		{
			system("cls");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("请选择存储元素的类型：\n");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf("1    int型\n");
			printf("2    char型\n");
			printf("3    double型\n");
			printf("4    srting型\n");
			printf("输入其他数字则默认选择int型\n");
			printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			void* dat;
			int temp;
			int typeSize;
			scanf_s("%d", &temp);
			getchar();
			switch (temp)//确认泛型
			{
				case  1:
				{
					int* t = (int*)malloc(sizeof(int));
					type = 'i';
					typeSize = sizeof(int);
					printf("请输入int型数据：\n");
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
					printf("请输入char型数据：\n");
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
					printf("请输入double型数据：\n");
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
					printf("请输入string：\n");
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
					printf("请输入int型数据：\n");
					scanf_s("%d", t);
					dat = t;
					datatype[LQ->length] = type;
					break;
				}
			}
			EnLQueue(LQ,dat,typeSize);
			printf("数据已入队.\n");
			break;
		}
		case  2:
		{
			DeLQueue(LQ);
			printf("出队操作完成.\n");
			break;
		}
		case  3:
		{
			ClearLQueue(LQ);
			printf("队列已清空.\n");
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
			printf("队列长度为：%d\n", LengthLQueue(LQ));
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