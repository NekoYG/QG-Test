#include"SqStack.h"
#include<iostream>
using namespace std;

int main(void)
{

	system("color F0");

		cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
		cout << "�� ���˵�                                                 ��" << endl;
		cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
		cout << "�� 1   ����˳��ջ(�������飩��������ز���                ��" << endl;
		cout << "�� 2   �˳�������                                         ��" << endl;
		cout << "��                                                        ��" << endl;
		cout << "��                                                        ��" << endl;
		cout << "�� ����δ�ṩ����Ĭ���˳�������                           ��" << endl;
		cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
		cout << "������룺";
		int choice1;
		cin >> choice1;
		switch (choice1)
		{
			case 1:
			{//����˳��ջ(�������飩��������ز���
				system("cls");
				cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
				cout << "�� ����Ҫ�ȴ���һ��ջ��                                   ��" << endl;
				cout << "��                                                        ��" << endl;
				cout << "�� ��������Ҫ������ջ�ĳ��ȣ�������                       ��" << endl;
				cout << "��                                                        ��" << endl;
				cout << "��                                                        ��" << endl;
				cout << "��                                                        ��" << endl;
				cout << "��                                                        ��" << endl;
				cout << "��                                                        ��" << endl;
				cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
				cout << "������룺";
				int size;
				SqStack* s;
				s = new SqStack;
				cin >> size;
				initStack(s, size);
				while (1)
				{

					system("cls");
					cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
					cout << "�� ˳��ջ(�������飩��ز���                              ��" << endl;
					cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
					cout << "�� 1   ��ջ                    6   ���ջ                 ��" << endl;
					cout << "�� 2   ��ջ                    7   ���ջ����             ��" << endl;
					cout << "�� 3   �ж�ջ�Ƿ�Ϊ��                                     ��" << endl;
					cout << "�� 4   �ж�ջ�Ƿ�Ϊ��                                     ��" << endl;
					cout << "�� 5   �õ�ջ��Ԫ��            0   �˳�����               ��" << endl;
					cout << "��  ����δ�ṩ���ֻ���0Ĭ���˳�������(�Զ�����ջ)         ��" << endl;
					cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
					cout << "��   top = " << s->top << "                 size = " << s->size << "                    " << endl;
					cout << "��������������������������������������������������������������������������������������������������������������������" << endl;

					cout << "���ѡ��";
					int choice2;
					cin >> choice2;
					switch (choice2)
					{
					case 1:
						ElemType pushdata;
						cout << "������Ҫ��ջ�����ݣ�";
						cin >> pushdata;
						pushStack(s, pushdata);
						system("pause"); break;

					case 2:
						ElemType * popdata;
						popdata = new ElemType;
						popStack(s, popdata);
						cout << "��ջ������Ϊ��" << *popdata << endl;
						system("pause"); break;

					case 3:
						isEmptyStack(s);
						system("pause"); break;

					case 4:
						isFullStack(s);
						system("pause"); break;

					case 5:
						ElemType * topdata;
						topdata = new ElemType;
						getTopStack(s, topdata);
						cout << "ջ��Ԫ��Ϊ��" << *topdata << endl;
						system("pause"); break;

					case 6:
						clearStack(s);
						system("pause"); break;

					case 7:
						ElemType * length;
						length = new ElemType;
						stackLength(s, length);
						cout << "ջ����Ϊ" << *length << endl;
						system("pause"); break;

					case 0:
						destroyStack(s);
						return 0;
					default:
						destroyStack(s);
						return 0;
					}

				}
			}
			case 2:
				return 0;
			default:
			{
				return 0;
			}
		}

	system("pause");
	return 0;
}


