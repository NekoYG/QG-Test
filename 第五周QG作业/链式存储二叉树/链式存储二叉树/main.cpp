#include"BsTree.h"
#include <malloc.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	BiTree T;
	BsTree tree;
	cout << tree.CreateBiTree(T) << endl;
	cout << "ǰ�������";
	tree.PreOrder(T);
	cout << endl;
	cout << "���������";
	tree.InOrder(T);
	cout << endl;
	cout << "���������";
	tree.PostOrder(T);
	cout << endl;
	cout << "��α�����";
	tree.LeverOrder(T);
	cout << endl;
	tree.delAllNode(T);
	cout << "����ɾ��...";
	return 0;
}
