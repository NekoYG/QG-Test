#include"SqStack.h"
#include<iostream>
using namespace std;

int main(void)
{

	system("color F0");

		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
		cout << "┃ 主菜单                                                 ┃" << endl;
		cout << "┣════════════════════════════════════════════════════════┫" << endl;
		cout << "┣ 1   创建顺序栈(基于数组）并进行相关操作                ┃" << endl;
		cout << "┣ 2   退出本程序                                         ┃" << endl;
		cout << "┃                                                        ┃" << endl;
		cout << "┃                                                        ┃" << endl;
		cout << "┃ 输入未提供数字默认退出本程序                           ┃" << endl;
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
		cout << "你的输入：";
		int choice1;
		cin >> choice1;
		switch (choice1)
		{
			case 1:
			{//创建顺序栈(基于数组）并进行相关操作
				system("cls");
				cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "┃ 你需要先创建一个栈！                                   ┃" << endl;
				cout << "┃                                                        ┃" << endl;
				cout << "┃ 请输入你要创建的栈的长度（整数）                       ┃" << endl;
				cout << "┃                                                        ┃" << endl;
				cout << "┃                                                        ┃" << endl;
				cout << "┃                                                        ┃" << endl;
				cout << "┃                                                        ┃" << endl;
				cout << "┃                                                        ┃" << endl;
				cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
				cout << "你的输入：";
				int size;
				SqStack* s;
				s = new SqStack;
				cin >> size;
				initStack(s, size);
				while (1)
				{

					system("cls");
					cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
					cout << "┃ 顺序栈(基于数组）相关操作                              ┃" << endl;
					cout << "┣════════════════════════════════════════════════════════┫" << endl;
					cout << "┃ 1   入栈                    6   清空栈                 ┃" << endl;
					cout << "┃ 2   出栈                    7   检测栈长度             ┃" << endl;
					cout << "┃ 3   判断栈是否为空                                     ┃" << endl;
					cout << "┃ 4   判断栈是否为满                                     ┃" << endl;
					cout << "┃ 5   得到栈顶元素            0   退出程序               ┃" << endl;
					cout << "┃  输入未提供数字或者0默认退出本程序(自动销毁栈)         ┃" << endl;
					cout << "┣════════════════════════════════════════════════════════┫" << endl;
					cout << "┃   top = " << s->top << "                 size = " << s->size << "                    " << endl;
					cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

					cout << "你的选择：";
					int choice2;
					cin >> choice2;
					switch (choice2)
					{
					case 1:
						ElemType pushdata;
						cout << "输入你要入栈的数据：";
						cin >> pushdata;
						pushStack(s, pushdata);
						system("pause"); break;

					case 2:
						ElemType * popdata;
						popdata = new ElemType;
						popStack(s, popdata);
						cout << "出栈的数据为：" << *popdata << endl;
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
						cout << "栈顶元素为：" << *topdata << endl;
						system("pause"); break;

					case 6:
						clearStack(s);
						system("pause"); break;

					case 7:
						ElemType * length;
						length = new ElemType;
						stackLength(s, length);
						cout << "栈长度为" << *length << endl;
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


