#include"LinkStack.h"
#include<iostream>
#include<string.h>
using namespace std;

int judge(char a,char b);

int main(void)
{	

		while (1)
		{
			system("cls");
			cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "�� �������������                                         ��" << endl;
			cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
			cout << "�� ��������ļ�����ʽ                                   ��" << endl;
			cout << "�� ��ʹ�õ�������У�+ - * / ����                         ��" << endl;
			cout << "�� ��Ҫ���븺����ʹ������     ������-1��                  ��" << endl;
			cout << "�� ����q���˳�����                                        ��" << endl;
			cout << "��                                                        ��" << endl;
			cout << "�� ע�⣺                                                 ��" << endl;
			cout << "��   1. ��ʱ��֧����������                                ��" << endl;
			cout << "��   2. ���˲������Ϳ��������֮����ַ�(��ĸ��)���Զ����ԩ�" << endl;
			cout << "��   3. ���������������Ĭ�Ϻ�����������ĺ��������      ��" << endl;
			cout << "��   4. ����Ӣ�Ļ�����������ʽ�������޷��ó���ȷ���    ��" << endl;
			cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
			cout << "��                                                         " << endl;
			cout << "��                                                         " << endl;
			cout << "��                                                         " << endl;
			cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "������룺";
			string infix;
			cin >> infix;

			if (infix == "q")
				return 0;
			LinkcharStack* stack = new LinkcharStack;
			initLcharStack(stack);
			string suffix = "                                                                                                                                    ";
			//�������ﲻ֪����ô������ֻ���ֶ���ʼ��һЩ�ո��ˡ�
			cout << suffix[0] << endl;
			int temp = 0;
			int jnum = 0;//ǰһλ��Ϊ����

			if (infix[0] == '+' || infix[0] == '-' || infix[0] == '*' || infix[0] == '/')
			{
				cout << "������ʽ�﷨�������鲢�������룡" << endl;
				system("pause");
				system("cls");
				cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
				cout << "�� �������������                                         ��" << endl;
				cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
				cout << "�� ��������ļ�����ʽ                                   ��" << endl;
				cout << "�� ��ʹ�õ�������У�+ - * / ����                         ��" << endl;
				cout << "�� ��Ҫ���븺����ʹ������     ������-1��                  ��" << endl;
				cout << "�� ����q���˳�����                                        ��" << endl;
				cout << "��                                                        ��" << endl;
				cout << "�� ע�⣺                                                 ��" << endl;
				cout << "��   1. ��ʱ��֧����������                                ��" << endl;
				cout << "��   2. ���˲������Ϳ��������֮����ַ�(��ĸ��)���Զ����ԩ�" << endl;
				cout << "��   3. ���������������Ĭ�Ϻ�����������ĺ��������      ��" << endl;
				cout << "��   4. ����Ӣ�Ļ�����������ʽ�������޷��ó���ȷ���    ��" << endl;
				cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
				cout << "��                                                         " << endl;
				cout << "��                                                         " << endl;
				cout << "��                                                         " << endl;
				cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
				cout << "������룺";
				cin >> infix;
			}


			int  judgeneganum = 0;
			for (int i = 0; infix[i]; i++)
			{
				if (infix[i] == '0' || infix[i] == '1' || infix[i] == '2' || infix[i] == '3' || infix[i] == '4'
					|| infix[i] == '5' || infix[i] == '6' || infix[i] == '7' || infix[i] == '8' || infix[i] == '9')//����ֱ���������׺���ʽstring
				{
					if (jnum == 0)
					{
						suffix[temp] = infix[i];
						temp++;
						jnum = 1;//���ǰһλΪ����
					}
					else if (jnum == 1)
					{
						suffix[temp] = infix[i];
						temp++;
					}
				}



				if (infix[i] == '(')//������ֱ����ջ
				{
					if (infix[i + 1] == '-')
					{}
					else
						pushLcharStack(stack, infix[i]);
				}
				if (infix[i] == ')')//������
				{
					if(judgeneganum ==1)
						judgeneganum = 0;
					else
					{
						if (jnum == 1)
						{
							suffix[temp] = ' ';
							temp++;
							jnum = 0;
						}
						char* t0;
						t0 = new char;
						getTopLcharStack(stack, t0);
						while (*t0 != '(')
						{
							char* t;
							t = new char;
							popLcharStack(stack, t);
							suffix[temp] = *t;
							temp++;
							getTopLcharStack(stack, t0);
							delete t;
						}
						delete t0;
					}
				}


				if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')//������ж�
				{
					if (infix[i-1]=='('&&infix[i]=='-')
					{
						judgeneganum = 1;
						char* t;
						t = new char;
						*t = '_';
						suffix[temp] = *t;
						temp++;
						delete t;
					}
					else
					{

						if (infix[i - 1] != '+' && infix[i - 1] != '-' && infix[i - 1] != '*' && infix[i - 1] != '/')
						{
							if (jnum == 1)
							{
								suffix[temp] = ' ';
								temp++;
								jnum = 0;
							}
							if (isEmptyLcharStack(stack) == SUCCESS)
								pushLcharStack(stack, infix[i]);
							else
							{
								char* t;
								t = new char;
								getTopLcharStack(stack, t);//��ȡջ��Ԫ��
								if (*t == '(' || judge(*t, infix[i]) == 1)
									pushLcharStack(stack, infix[i]);
								else
								{
									char* t1;
									t1 = new char;
									popLcharStack(stack, t1);
									suffix[temp] = *t1;
									temp++;

									char* t2;
									t2 = new char;
									getTopLcharStack(stack, t2);
									while (judge(*t2, infix[i]) == 0)
									{
										char* t3;
										t3 = new char;
										popLcharStack(stack, t3);
										suffix[temp] = *t3;
										temp++;
										delete t3;
										getTopLcharStack(stack, t2);
									}
									pushLcharStack(stack, infix[i]);
									delete t1;
									delete t2;
								}
								delete t;
							}
						}
					}
				}
			}
			if (jnum == 1)
			{
				suffix[temp] = ' ';
				temp++;
				jnum = 0;
			}
			while (isEmptyLcharStack(stack) == ERROR)
			{
				char* t;
				t = new char;
				popLcharStack(stack, t);
				if (*t != '(')
				{
					suffix[temp] = *t;
					temp++;
					delete t;
				}
			}
			suffix[temp] = '\0';

			clearLcharStack(stack);
			destroyLcharStack(stack);

			LinkdStack* dstack = new LinkdStack;
			initLdStack(dstack);
			judgeneganum = 0;
			int* t;
			t = new int;
			*t = suffix[0] - '0';
			pushLdStack(dstack, *t);
			delete t;

			for (int i = 1; suffix[i]; i++)
			{
				if (suffix[i] == '_')
					judgeneganum = 1;

				if (suffix[i] == '0' || suffix[i] == '1' || suffix[i] == '2' || suffix[i] == '3' || suffix[i] == '4'
					|| suffix[i] == '5' || suffix[i] == '6' || suffix[i] == '7' || suffix[i] == '8' || suffix[i] == '9')
				{
					if (suffix[i - 1] == '0' || suffix[i - 1] == '1' || suffix[i - 1] == '2' || suffix[i - 1] == '3' || suffix[i - 1] == '4'
						|| suffix[i - 1] == '5' || suffix[i - 1] == '6' || suffix[i - 1] == '7' || suffix[i - 1] == '8' || suffix[i - 1] == '9')
					{
						if (judgeneganum == 1)
						{
							double* a;
							a = new double;
							getTopLdStack(dstack, a);
							popLdStack(dstack, a);
							*a *= (-10);
							int temp;
							temp =suffix[i] - '0';
							*a = *a - (double)temp;
							pushLdStack(dstack, *a);
							delete a;
							judgeneganum = 0;
						}
						else 
						{
							double* a;
							a = new double;
							getTopLdStack(dstack, a);
							popLdStack(dstack, a);
							*a *= 10;
							int temp;
							temp = suffix[i] - '0';
							*a = *a + (double)temp;
							pushLdStack(dstack, *a);
							delete a;
						}
					}
					else
					{
						if (suffix[i + 1] == '0' || suffix[i + 1] == '1' || suffix[i + 1] == '2' || suffix[i + 1] == '3' || suffix[i + 1] == '4'
							|| suffix[i + 1] == '5' || suffix[i + 1] == '6' || suffix[i + 1] == '7' || suffix[i + 1] == '8' || suffix[i + 1] == '9')
						{
							double* a;
							a = new double;
							int temp;
							temp = suffix[i] - '0';
							*a = double(temp);
							pushLdStack(dstack, *a);
							delete a;
						}
						else
						{
							double* a;
							a = new double;
							int temp;
							temp = suffix[i] - '0';
							*a = 0-double(temp);
							pushLdStack(dstack, *a);
							delete a;
						}
					}
				}

				if (suffix[i] == '-')
				{
					double total = 0;
					double* t1 = new double;
					double* t2 = new double;
					popLdStack(dstack, t1);
					popLdStack(dstack, t2);
					total = *t1 + *t2;
					pushLdStack(dstack, total);
					delete t1;
					delete t2;
				}


				if (suffix[i] == '+')
				{
					double total = 0;
					double* t1 = new double;
					double* t2 = new double;
					popLdStack(dstack, t1);
					popLdStack(dstack, t2);
					total = *t2 - *t1;
					pushLdStack(dstack, total);
					delete t1;
					delete t2;
				}


				if (suffix[i] == '*')
				{
					double total = 0;
					double* t1 = new double;
					double* t2 = new double;
					popLdStack(dstack, t1);
					popLdStack(dstack, t2);
					total = total -((*t1) * (*t2));
					pushLdStack(dstack, total);
					delete t1;
					delete t2;
				}
				if (suffix[i] == '/')
				{
					double total;
					double* t1 = new double;
					double* t2 = new double;
					popLdStack(dstack, t1);
					popLdStack(dstack, t2);
					total = -((*t2) / (*t1));
					pushLdStack(dstack, total);
					delete t1;
					delete t2;
				}
			}

			double* total;
			total = new double;
			popLdStack(dstack, total);
			system("cls");
			cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "�� �������������                                         ��" << endl;
			cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
			cout << "�� ��������ļ�����ʽ                                   ��" << endl;
			cout << "�� ��ʹ�õ�������У�+ - * / ����                         ��" << endl;
			cout << "�� ��Ҫ���븺����ʹ������     ������-1��                  ��" << endl;
			cout << "�� ����q���˳�����                                        ��" << endl;
			cout << "��                                                        ��" << endl;
			cout << "�� ע�⣺                                                 ��" << endl;
			cout << "��   1. ��ʱ��֧����������                                ��" << endl;
			cout << "��   2. ���˲������Ϳ��������֮����ַ�(��ĸ��)���Զ����ԩ�" << endl;
			cout << "��   3. ���������������Ĭ�Ϻ�����������ĺ��������      ��" << endl;
			cout << "��   4. ����Ӣ�Ļ�����������ʽ�������޷��ó���ȷ���    ��" << endl;
			cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
			cout << "������ı��ʽ��ת��Ϊ��׺���ʽ��" << suffix << endl;
			cout << "��                                                         " << endl;
			cout << "����������" << *total << endl;
			cout << "��������������������������������������������������������������������������������������������������������������������" << endl;


			delete total;
			if (isEmptyLdStack(dstack) == SUCCESS)
				clearLdStack(dstack);
			destroyLdStack(dstack);





			system("pause");
		}
	return 0;
}


int judge(char a, char b)
{
	if (a =='*'||a=='/')
			return 0;
	
	if (a == '+' || a == '-')
	{
		if (b == '*' || b == '/')
			return 1;
		else
			return 0;
	}
}