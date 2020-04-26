#include"Forwardlist.h"

int main(void)
{
    system("color F0");
    QGForwardList textList;    //初始化链表
    textList.printList();

    while (1)
    {

        system("cls");
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┣《单链表操作菜单》                          ┃" << endl;
        cout << "┣*你可以对单链表做以下操作(输入数字来选择)***┫" << endl;
        cout << "┣══════════════════════┫" << endl;
        cout << "┣ 1  获得Head的地址                          ┃" << endl;
        cout << "┣ 2  输出完整链表                            ┃" << endl;
        cout << "┣ 3  清空链表                                ┃" << endl;
        cout << "┣ 4  其他输出类操作（子菜单）                ┃" << endl;
        cout << "┣ 5  其他删除类操作（子菜单）                ┃" << endl;
        cout << "┣ 6  增添和转换类等其他操作（子菜单）        ┃" << endl;
        cout << "┣ 0  删除链表并退出程序                      ┃" << endl;
        cout << "┣**一般操作完成后都会自动输出一次完整链表****┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        cout << "你的选择：";



        int num1, num2, num3, num4;
        cin >> num1;
        switch (num1)
        {
        case 1:
            cout << &QGForwardList::head << endl; break;

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
            cout << "┣4  反转链表(1234反转后变成4321)         ┃" << endl;
            cout << "┣5  偶节点反转，1234反转后变成2143       ┃" << endl;
            cout << "┣6  链表判环                             ┃" << endl;
            cout << "┣7  返回链表中间节点                     ┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━┛" << endl;
            cout << "你的选择：";
            cin >> num4;
            switch (num4)
            {
            case  1:
                cout << "输入你要添加的元素数据：" << endl;
                QGForwardList::ElemType p_front;
                cin >> p_front;
                textList.push_front(p_front);
                textList.printList(); break;
            case  2:
                cout << "输入你要添加的元素数据：" << endl;
                QGForwardList::ElemType p_back;
                cin >> p_back;
                textList.push_back(p_back);
                textList.printList(); break;

            case  3:
                cout << "输入你要查找的元素数据：" << endl;
                QGForwardList::ElemType pcontain;
                cin >> pcontain;
                textList.contain(pcontain);
                textList.printList(); break;
            case  4:
                textList.reverse();
                textList.printList(); break;
            case  5:
                textList.reverseEven();
                textList.printList(); break;
            case  6:
                textList.isLoop();
                textList.printList(); break;
            case  7:
                textList.middleElem(); break;
            default:
                break;
            }break;
        }
        case 0: {
            return 0;

        }
        default:
            break;
        }
        system("pause");
    }

    system("pause");
    return 0;
}