#include"qglist.h"

int main(void)
{
    system("color F0");
    QGList textList;    //初始化链表
    textList.printList();

    while (1)
    {

        system("cls");
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┣《双向链表操作菜单》                        ┃" << endl;
        cout << "┣*你可以对单链表做以下操作(输入数字来选择)***┫" << endl;
        cout << "┣══════════════════════┫" << endl;
        cout << "┣ 1  删除链表并退出程序                      ┃" << endl;
        cout << "┣ 2  输出完整链表                            ┃" << endl;
        cout << "┣ 3  清空链表                                ┃" << endl;
        cout << "┣ 4  其他输出类操作（子菜单）                ┃" << endl;
        cout << "┣ 5  其他删除类操作（子菜单）                ┃" << endl;
        cout << "┣ 6  增添和转换类等其他操作（子菜单）        ┃" << endl;
        cout << "┣**一般操作完成后都会自动输出一次完整链表**  ┃" << endl;
        cout << "┣*输入未提供数字将默认执行1操作*             ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        cout << "你的选择：";



        int num1, num2, num3, num4;
        cin >> num1;
        switch (num1)
        {
        case 1: 
            return 0;

        case 2:
            textList.printList(); break;

        case 3:
            textList.clear(); break;

        case 4:
        {
            system("cls");
            cout << "┏━━━━━━━━━━━━━━━━━━━━┓" << endl;
            cout << "┣其他输出类操作（子菜单)                 ┃" << endl;
            cout << "┣════════════════════┫" << endl;
            cout << "┣1  输出链表的第一个元素                 ┃" << endl;
            cout << "┣2  输出链表的最后一个元素               ┃" << endl;
            cout << "┣ *输入未提供数字将退出当前菜单*         ┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━┛" << endl;
            cout << "你的选择：";
            cin >> num2;
            switch (num2)
            {
            case 1:
                cout << textList.front() << endl;
                break;
            case 2:
                cout << textList.back() << endl;
                break;
            default:
                break;
            }break;
        }
        case 5: {
            system("cls");
            cout << "┏━━━━━━━━━━━━━━━━━━━━┓" << endl;
            cout << "┣其他删除类操作（子菜单）                ┃" << endl;
            cout << "┣════════════════════┫" << endl;
            cout << "┣1  删除链表的第一个元素                 ┃" << endl;
            cout << "┣2  删除链表的最后一个元素               ┃" << endl;
            cout << "┣3  删除你指定位置的元素                 ┃" << endl;
            cout << "┣*输入未提供数字将退出当前菜单*          ┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━┛" << endl;
            cout << "你的选择：";
            cin >> num3;
            switch (num3)
            {
            case 1:
                textList.pop_front();
                textList.printList(); break;
            case 2:
                textList.pop_back();
                textList.printList(); break;
            case 3:
                cout << "请输入指定的位置(整数)：" << endl;
                unsigned int erasenum = 0;
                cin >> erasenum;
                textList.erase(erasenum);
                textList.printList(); break;

            }break;
        }
        case 6: {
            system("cls");
            cout << "┏━━━━━━━━━━━━━━━━━━━━┓" << endl;
            cout << "┣增添和转换类等其他操作（子菜单）        ┃" << endl;
            cout << "┣════════════════════┫" << endl;
            cout << "┣1  在第一个元素前新添加一个元素         ┃" << endl;
            cout << "┣2  在最后一个元素后新添加一个元素       ┃" << endl;
            cout << "┣3  查找指定元素是否存在于列表           ┃" << endl;
            cout << "┣*输入未提供数字将退出当前菜单*          ┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━┛" << endl;
            cout << "你的选择：";
            cin >> num4;
            switch (num4)
            {
            case  1:
                cout << "输入你要添加的元素数据：" << endl;
                QGList::ElemType p_front;
                cin >> p_front;
                textList.push_front(p_front);
                textList.printList(); break;
            case  2:
                cout << "输入你要添加的元素数据：" << endl;
                QGList::ElemType p_back;
                cin >> p_back;
                textList.push_back(p_back);
                textList.printList(); break;

            case  3:
                cout << "输入你要查找的元素数据：" << endl;
                QGList::ElemType pcontain;
                cin >> pcontain;
                textList.contain(pcontain);
                textList.printList(); break;

            default:
                break;
            }break;
        }

        default:
            return 0;
        }
        system("pause");
    }

    system("pause");
    return 0;
}