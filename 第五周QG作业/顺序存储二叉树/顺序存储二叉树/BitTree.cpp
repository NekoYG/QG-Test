#include"BitTree.h"
#include<iostream>

using namespace std;

//创建二叉树
void BitTree::creat_tree(SqBiTree& t)
{
        cout << "请输入你的数据(输入字符串，结尾以#来结束）：";
        int i = 0;
        char ch;
        while ((ch = getchar()) != '#')
        {
            i++;
            t[i] = ch;
        }
        t[0] = i;
}

//获取给定结点（位置）的左孩子的结点位置
int BitTree::LeftChild_locate(SqBiTree& t, int node)
{
    if ((2 * node) > t[0])
        return -1;
    else
        return 2 * node;
}
//获取给定结点（位置）的右孩子的结点位置
int BitTree::RightChild_locate(SqBiTree& t, int node)
{
    if ((2 * node + 1) > t[0])
        return -1;
    else
        return 2 * node + 1;
}

//层序遍历
void BitTree::level_order(SqBiTree& t)
{
    for (int i = 1; i <= t[0]; i++)
        if (t[i] != '#')
            cout << t[i] << " ";
}
//先序遍历
void BitTree::pre_order(SqBiTree& t, int i)
{
    if (t[0] <= 0)
    {
        cout << "空树!" << endl;
    }
    else
    {
        if (t[i] != '#')
            cout << t[i] << " ";
        if (LeftChild_locate(t, i) != -1)    //如果左子结点存在，递归
            pre_order(t, LeftChild_locate(t, i));
        if (RightChild_locate(t, i) != -1)    //如果右子结点存在，递归
            pre_order(t, RightChild_locate(t, i));
    }
}
//中序遍历
void BitTree::mid_order(SqBiTree& t, int i)
{
    if (t[0] <= 0)
    {
        cout << "空树!" << endl;
    }
    else
    {
        if (LeftChild_locate(t, i) != -1)    //如果左子结点存在，递归
            mid_order(t, LeftChild_locate(t, i));
        if (t[i] != '#')
            cout << t[i] << " ";
        if (RightChild_locate(t, i) != -1)    //如果右子结点存在，递归
            mid_order(t, RightChild_locate(t, i));
    }
}
//后序遍历
void BitTree::back_order(SqBiTree& t, int i)
{
    if (t[0] <= 0)
    {
        cout << "空树!" << endl;
    }
    else
    {
        if (LeftChild_locate(t, i) != -1)    //如果左子结点存在，递归
            back_order(t, LeftChild_locate(t, i));
        if (RightChild_locate(t, i) != -1)    //如果右子结点存在，递归
            back_order(t, RightChild_locate(t, i));
        if (t[i] != '#')
            cout << t[i] << " ";
    }
}


