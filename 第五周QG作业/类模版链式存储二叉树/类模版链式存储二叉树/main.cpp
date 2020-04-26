#include"BinaryTree.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
//
// ���Զ�����. 
//
int main(void)
{
    const size_t MAX_SIZE = 100;
    char szPreOrder[MAX_SIZE] = { '\0' };

    cout << "������������ڵ�����ǰ�����У�" << endl;
    while (!cin.getline(szPreOrder, MAX_SIZE))
    {
        cout << "�������. " << endl;
        cout << "��������: ";
        cin.clear();
        cin.sync();
    }

    BinaryTree<char> binTree(szPreOrder, strlen(szPreOrder), ' ');

    //
    // ����������. 
    //
    cout << "ǰ�������";
    binTree.traversal(BinaryTree<char>::PRE_ORDER);

    cout << endl << "���������";
    binTree.traversal(BinaryTree<char>::IN_ORDER);

    cout << endl << "���������";
    binTree.traversal(BinaryTree<char>::POST_ORDER);
    cout << endl;


    cout << "���ߣ�" << binTree.getHeight() << endl;
    cout << "�ڵ㣺" << binTree.getNumberOfNode() << endl;

    return EXIT_SUCCESS;
}