#include"BsTree.h"
#include <malloc.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	BiTree T;
	BsTree tree;
	cout << tree.CreateBiTree(T) << endl;
	cout << "前序遍历：";
	tree.PreOrder(T);
	cout << endl;
	cout << "中序遍历：";
	tree.InOrder(T);
	cout << endl;
	cout << "后序遍历：";
	tree.PostOrder(T);
	cout << endl;
	cout << "层次遍历：";
	tree.LeverOrder(T);
	cout << endl;
	tree.delAllNode(T);
	cout << "树已删除...";
	return 0;
}
