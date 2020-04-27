#include"LinkStack.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int calculate(BiTree* root);


void InfixToPrefix(const string infix, string& prefix)//��׺תǰ׺
{
    LinkcharStack* stack = new LinkcharStack;
    initLcharStack(stack);

    map<char, int> priority;                    // �������ȼ�
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;

    int infix_length = infix.size();            // ��׺���ʽ���ַ�����
    prefix.reserve(infix_length);
    for (int i = infix_length - 1; i >= 0; --i) 
    {
        switch (infix[i]) 
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                prefix.push_back(infix[i]);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (!isEmptyLcharStack(stack)) 
                {
                    char* markTop = new char;
                    getTopLcharStack(stack, markTop);

                    while (*markTop != ')' && priority[infix[i]] < priority[*markTop]) 
                    {
                        prefix.push_back(*markTop);
                        char* data = new char;
                        popLcharStack(stack, data);
                        delete data;
                        if (isEmptyLcharStack(stack)) {
                            break;
                        }
                        getTopLcharStack(stack, markTop);
                    }
                    delete markTop;
                }
                pushLcharStack(stack, infix[i]);
                break;
            case ')':
                pushLcharStack(stack, infix[i]);
                break;
            case '(':
            {
                char* markTop = new char;
                getTopLcharStack(stack, markTop);
                while (*markTop != ')') 
                {
                    prefix.push_back(*markTop);
                    char* data = new char;
                    popLcharStack(stack, data);
                    delete data;
                    getTopLcharStack(stack, markTop);
                }
                char* data = new char;
                popLcharStack(stack, data);
                delete data;
                break;
            }

        }
    }
    // ʣ���ȫ����ջ
    while (!isEmptyLcharStack(stack)) 
    {
        char* markTop = new char;
        getTopLcharStack(stack, markTop);
        prefix.push_back(*markTop);
        char* data = new char;
        popLcharStack(stack, data);
        delete data;
    }
    reverse(prefix.begin(), prefix.end());

    destroyLcharStack(stack);
}


int main(int argc, char const* argv[])
{
    while(1)
    {
        system("cls");
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�� �������������(������)                                 ��" << endl;
        cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
        cout << "�� ��������ļ�����ʽ                                   ��" << endl;
        cout << "�� ��ʹ�õ�������У�+ - * / ()                           ��" << endl;
        cout << "��                                                        ��" << endl;
        cout << "�� ����q���˳�����                                        ��" << endl;
        cout << "��                                                        ��" << endl;
        cout << "�� ע�⣺                                                 ��" << endl;
        cout << "��   1. ��ʱ��֧������������0��9                          ��" << endl;
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

        if (infix[0] == '+' || infix[0] == '-' || infix[0] == '*' || infix[0] == '/')
        {
            cout << "������ʽ�﷨�������鲢�������룡" << endl;
            system("pause");
            system("cls");
            cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "�� �������������(������)                                 ��" << endl;
            cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
            cout << "�� ��������ļ�����ʽ                                   ��" << endl;
            cout << "�� ��ʹ�õ�������У�+ - * / ()                           ��" << endl;
            cout << "��                                                        ��" << endl;
            cout << "�� ����q���˳�����                                        ��" << endl;
            cout << "��                                                        ��" << endl;
            cout << "�� ע�⣺                                                 ��" << endl;
            cout << "��   1. ��ʱ��֧������������0��9                          ��" << endl;
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
        string prefix;
        InfixToPrefix(infix, prefix);


        system("cls");
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�� �������������(������)                                 ��" << endl;
        cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
        cout << "�� ��������ļ�����׺���ʽ                               ��" << endl;
        cout << "�� ��ʹ�õ�������У�+ - * / ()                           ��" << endl;
        cout << "��                                                        ��" << endl;
        cout << "�� ����q���˳�����                                        ��" << endl;
        cout << "��                                                        ��" << endl;
        cout << "�� ע�⣺                                                 ��" << endl;
        cout << "��   1. ��ʱ��֧������������0��9                          ��" << endl;
        cout << "��   2. ���˲������Ϳ��������֮����ַ�(��ĸ��)���Զ����ԩ�" << endl;
        cout << "��   3. ���������������Ĭ�Ϻ�����������ĺ��������      ��" << endl;
        cout << "��   4. ����Ӣ�Ļ�����������ʽ�������޷��ó���ȷ���    ��" << endl;
        cout << "�ǨT�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T��" << endl;
        cout << "�����ṩ���ʽ��ת��Ϊǰ׺���ʽ: " << prefix << endl;
        cout << "��                                                         " << endl;
        cout << "��                                                         " << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "����������м���..." << endl;
        system("pause");


        LinkdStack* stack = new LinkdStack;
        initLdStack(stack);
        int size = prefix.size();
        BiTree* t = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            if (prefix[i] == '0' || prefix[i] == '1' || prefix[i] == '2' || prefix[i] == '3' || prefix[i] == '4'
                || prefix[i] == '5' || prefix[i] == '6' || prefix[i] == '7' || prefix[i] == '8' || prefix[i] == '9')
            {
                BiTree* dat;
                dat = new BiTree;
                dat->data = prefix[i];

                dat->lchild = dat->rchild = 0;
                t = dat;
                pushLdStack(stack, t);
                //delete dat;
            }
            else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/')
            {
                BiTree* dat1 = NULL;
                BiTree* dat2 = NULL;
                BiTree* dat;
                dat = new BiTree;
                dat->data = prefix[i];

                dat1 = popLdStack(stack);
                dat2 = popLdStack(stack);
                dat->lchild = dat1;
                dat->rchild = dat2;
                t = dat;
                pushLdStack(stack, t);
                //delete dat;
            }
        }
        BiTree* root = NULL;
        root= popLdStack(stack);
        destroyLdStack(stack);//����ջ


        int num = calculate(root);
        cout << "��������"<<num << endl;
        return 0;
    }
}


int calculate(BiTree* root)
{
    int v1, v2;
    if (root->lchild == 0 && root->rchild == 0)
        return  root->data - '0';

    v1 = calculate(root->lchild);
    v2 = calculate(root->rchild);
    switch (root->data)
    {
    case '+':
        return v1 + v2;
    case '-':
        return v1 - v2;
    case '*':
        return v1 * v2;
    case '/':
        if (v2 != 0)
            return v1 / v2;
        else
            abort();
    default:
        abort();
    }
};