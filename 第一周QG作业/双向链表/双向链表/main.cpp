#include"qglist.h"

int main(void)
{
    system("color F0");
    QGList textList;    //��ʼ������
    textList.printList();

    while (1)
    {

        system("cls");
        cout << "������������������������������������������������" << endl;
        cout << "�ǡ�˫����������˵���                        ��" << endl;
        cout << "��*����ԶԵ����������²���(����������ѡ��)***��" << endl;
        cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
        cout << "�� 1  ɾ�������˳�����                      ��" << endl;
        cout << "�� 2  �����������                            ��" << endl;
        cout << "�� 3  �������                                ��" << endl;
        cout << "�� 4  ���������������Ӳ˵���                ��" << endl;
        cout << "�� 5  ����ɾ����������Ӳ˵���                ��" << endl;
        cout << "�� 6  �����ת����������������Ӳ˵���        ��" << endl;
        cout << "��**һ�������ɺ󶼻��Զ����һ����������**  ��" << endl;
        cout << "��*����δ�ṩ���ֽ�Ĭ��ִ��1����*             ��" << endl;
        cout << "������������������������������������������������" << endl;
        cout << "���ѡ��";



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
            cout << "��������������������������������������������" << endl;
            cout << "�����������������Ӳ˵�)                 ��" << endl;
            cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
            cout << "��1  �������ĵ�һ��Ԫ��                 ��" << endl;
            cout << "��2  �����������һ��Ԫ��               ��" << endl;
            cout << "�� *����δ�ṩ���ֽ��˳���ǰ�˵�*         ��" << endl;
            cout << "��������������������������������������������" << endl;
            cout << "���ѡ��";
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
            cout << "��������������������������������������������" << endl;
            cout << "������ɾ����������Ӳ˵���                ��" << endl;
            cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
            cout << "��1  ɾ������ĵ�һ��Ԫ��                 ��" << endl;
            cout << "��2  ɾ����������һ��Ԫ��               ��" << endl;
            cout << "��3  ɾ����ָ��λ�õ�Ԫ��                 ��" << endl;
            cout << "��*����δ�ṩ���ֽ��˳���ǰ�˵�*          ��" << endl;
            cout << "��������������������������������������������" << endl;
            cout << "���ѡ��";
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
                cout << "������ָ����λ��(����)��" << endl;
                unsigned int erasenum = 0;
                cin >> erasenum;
                textList.erase(erasenum);
                textList.printList(); break;

            }break;
        }
        case 6: {
            system("cls");
            cout << "��������������������������������������������" << endl;
            cout << "�������ת����������������Ӳ˵���        ��" << endl;
            cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
            cout << "��1  �ڵ�һ��Ԫ��ǰ�����һ��Ԫ��         ��" << endl;
            cout << "��2  �����һ��Ԫ�غ������һ��Ԫ��       ��" << endl;
            cout << "��3  ����ָ��Ԫ���Ƿ�������б�           ��" << endl;
            cout << "��*����δ�ṩ���ֽ��˳���ǰ�˵�*          ��" << endl;
            cout << "��������������������������������������������" << endl;
            cout << "���ѡ��";
            cin >> num4;
            switch (num4)
            {
            case  1:
                cout << "������Ҫ��ӵ�Ԫ�����ݣ�" << endl;
                QGList::ElemType p_front;
                cin >> p_front;
                textList.push_front(p_front);
                textList.printList(); break;
            case  2:
                cout << "������Ҫ��ӵ�Ԫ�����ݣ�" << endl;
                QGList::ElemType p_back;
                cin >> p_back;
                textList.push_back(p_back);
                textList.printList(); break;

            case  3:
                cout << "������Ҫ���ҵ�Ԫ�����ݣ�" << endl;
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