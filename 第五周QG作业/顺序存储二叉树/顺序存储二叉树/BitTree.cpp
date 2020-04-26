#include"BitTree.h"
#include<iostream>

using namespace std;

//����������
void BitTree::creat_tree(SqBiTree& t)
{
        cout << "�������������(�����ַ�������β��#����������";
        int i = 0;
        char ch;
        while ((ch = getchar()) != '#')
        {
            i++;
            t[i] = ch;
        }
        t[0] = i;
}

//��ȡ������㣨λ�ã������ӵĽ��λ��
int BitTree::LeftChild_locate(SqBiTree& t, int node)
{
    if ((2 * node) > t[0])
        return -1;
    else
        return 2 * node;
}
//��ȡ������㣨λ�ã����Һ��ӵĽ��λ��
int BitTree::RightChild_locate(SqBiTree& t, int node)
{
    if ((2 * node + 1) > t[0])
        return -1;
    else
        return 2 * node + 1;
}

//�������
void BitTree::level_order(SqBiTree& t)
{
    for (int i = 1; i <= t[0]; i++)
        if (t[i] != '#')
            cout << t[i] << " ";
}
//�������
void BitTree::pre_order(SqBiTree& t, int i)
{
    if (t[0] <= 0)
    {
        cout << "����!" << endl;
    }
    else
    {
        if (t[i] != '#')
            cout << t[i] << " ";
        if (LeftChild_locate(t, i) != -1)    //������ӽ����ڣ��ݹ�
            pre_order(t, LeftChild_locate(t, i));
        if (RightChild_locate(t, i) != -1)    //������ӽ����ڣ��ݹ�
            pre_order(t, RightChild_locate(t, i));
    }
}
//�������
void BitTree::mid_order(SqBiTree& t, int i)
{
    if (t[0] <= 0)
    {
        cout << "����!" << endl;
    }
    else
    {
        if (LeftChild_locate(t, i) != -1)    //������ӽ����ڣ��ݹ�
            mid_order(t, LeftChild_locate(t, i));
        if (t[i] != '#')
            cout << t[i] << " ";
        if (RightChild_locate(t, i) != -1)    //������ӽ����ڣ��ݹ�
            mid_order(t, RightChild_locate(t, i));
    }
}
//�������
void BitTree::back_order(SqBiTree& t, int i)
{
    if (t[0] <= 0)
    {
        cout << "����!" << endl;
    }
    else
    {
        if (LeftChild_locate(t, i) != -1)    //������ӽ����ڣ��ݹ�
            back_order(t, LeftChild_locate(t, i));
        if (RightChild_locate(t, i) != -1)    //������ӽ����ڣ��ݹ�
            back_order(t, RightChild_locate(t, i));
        if (t[i] != '#')
            cout << t[i] << " ";
    }
}


