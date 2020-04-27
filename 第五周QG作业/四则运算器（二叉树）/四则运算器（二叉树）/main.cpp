#include"LinkStack.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int calculate(BiTree* root);


void InfixToPrefix(const string infix, string& prefix)//中缀转前缀
{
    LinkcharStack* stack = new LinkcharStack;
    initLcharStack(stack);

    map<char, int> priority;                    // 符号优先级
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;

    int infix_length = infix.size();            // 中缀表达式的字符长度
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
    // 剩余的全部出栈
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
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃ 四则运算计算器(二叉树)                                 ┃" << endl;
        cout << "┣════════════════════════════════════════════════════════┫" << endl;
        cout << "┃ 请输入你的计算表达式                                   ┃" << endl;
        cout << "┃ 可使用的运算符有：+ - * / ()                           ┃" << endl;
        cout << "┃                                                        ┃" << endl;
        cout << "┃ 输入q可退出程序                                        ┃" << endl;
        cout << "┃                                                        ┃" << endl;
        cout << "┃ 注意：                                                 ┃" << endl;
        cout << "┃   1. 暂时仅支持输入正整数0到9                          ┃" << endl;
        cout << "┃   2. 除了操作数和可用运算符之外的字符(字母等)将自动忽略┃" << endl;
        cout << "┃   3. 连续输入运算符，默认忽略连续输入的后续运算符      ┃" << endl;
        cout << "┃   4. 请在英文环境下输入表达式，否则无法得出正确结果    ┃" << endl;
        cout << "┣════════════════════════════════════════════════════════┫" << endl;
        cout << "┃                                                         " << endl;
        cout << "┃                                                         " << endl;
        cout << "┃                                                         " << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        cout << "你的输入：";
        string infix;
        cin >> infix;

        if (infix[0] == '+' || infix[0] == '-' || infix[0] == '*' || infix[0] == '/')
        {
            cout << "计算表达式语法错误，请检查并重新输入！" << endl;
            system("pause");
            system("cls");
            cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
            cout << "┃ 四则运算计算器(二叉树)                                 ┃" << endl;
            cout << "┣════════════════════════════════════════════════════════┫" << endl;
            cout << "┃ 请输入你的计算表达式                                   ┃" << endl;
            cout << "┃ 可使用的运算符有：+ - * / ()                           ┃" << endl;
            cout << "┃                                                        ┃" << endl;
            cout << "┃ 输入q可退出程序                                        ┃" << endl;
            cout << "┃                                                        ┃" << endl;
            cout << "┃ 注意：                                                 ┃" << endl;
            cout << "┃   1. 暂时仅支持输入正整数0到9                          ┃" << endl;
            cout << "┃   2. 除了操作数和可用运算符之外的字符(字母等)将自动忽略┃" << endl;
            cout << "┃   3. 连续输入运算符，默认忽略连续输入的后续运算符      ┃" << endl;
            cout << "┃   4. 请在英文环境下输入表达式，否则无法得出正确结果    ┃" << endl;
            cout << "┣════════════════════════════════════════════════════════┫" << endl;
            cout << "┃                                                         " << endl;
            cout << "┃                                                         " << endl;
            cout << "┃                                                         " << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
            cout << "你的输入：";
            cin >> infix;
        }
        string prefix;
        InfixToPrefix(infix, prefix);


        system("cls");
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃ 四则运算计算器(二叉树)                                 ┃" << endl;
        cout << "┣════════════════════════════════════════════════════════┫" << endl;
        cout << "┃ 请输入你的计算中缀表达式                               ┃" << endl;
        cout << "┃ 可使用的运算符有：+ - * / ()                           ┃" << endl;
        cout << "┃                                                        ┃" << endl;
        cout << "┃ 输入q可退出程序                                        ┃" << endl;
        cout << "┃                                                        ┃" << endl;
        cout << "┃ 注意：                                                 ┃" << endl;
        cout << "┃   1. 暂时仅支持输入正整数0到9                          ┃" << endl;
        cout << "┃   2. 除了操作数和可用运算符之外的字符(字母等)将自动忽略┃" << endl;
        cout << "┃   3. 连续输入运算符，默认忽略连续输入的后续运算符      ┃" << endl;
        cout << "┃   4. 请在英文环境下输入表达式，否则无法得出正确结果    ┃" << endl;
        cout << "┣════════════════════════════════════════════════════════┫" << endl;
        cout << "┃所提供表达式已转化为前缀表达式: " << prefix << endl;
        cout << "┃                                                         " << endl;
        cout << "┃                                                         " << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        cout << "按任意键进行计算..." << endl;
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
        destroyLdStack(stack);//销毁栈


        int num = calculate(root);
        cout << "计算结果："<<num << endl;
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