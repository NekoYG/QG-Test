#include"BinaryTree.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
//
// 测试二叉树. 
//
int main(void)
{
    const size_t MAX_SIZE = 100;
    char szPreOrder[MAX_SIZE] = { '\0' };

    cout << "请输入二叉树节点数据前序序列：" << endl;
    while (!cin.getline(szPreOrder, MAX_SIZE))
    {
        cout << "输入错误. " << endl;
        cout << "重新输入: ";
        cin.clear();
        cin.sync();
    }

    BinaryTree<char> binTree(szPreOrder, strlen(szPreOrder), ' ');

    //
    // 遍历二叉树. 
    //
    cout << "前序遍历：";
    binTree.traversal(BinaryTree<char>::PRE_ORDER);

    cout << endl << "中序遍历：";
    binTree.traversal(BinaryTree<char>::IN_ORDER);

    cout << endl << "后序遍历：";
    binTree.traversal(BinaryTree<char>::POST_ORDER);
    cout << endl;


    cout << "树高：" << binTree.getHeight() << endl;
    cout << "节点：" << binTree.getNumberOfNode() << endl;

    return EXIT_SUCCESS;
}