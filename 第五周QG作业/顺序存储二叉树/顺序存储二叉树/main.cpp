#include"BitTree.h"

int main()
{
    cout << "创建二叉树..." << endl;
    SqBiTree sbt;
    BitTree tree;
    //创建顺序二叉树
    tree.creat_tree(sbt);

    cout << "层序遍历：" << endl;
    tree.level_order(sbt);
    cout << endl;

    cout << "先序遍历：" << endl;
    tree.pre_order(sbt, 1);
    cout << endl;

    cout << "中序遍历：" << endl;
    tree.mid_order(sbt, 1);
    cout << endl;

    cout << "后续遍历：" << endl;
    tree.back_order(sbt, 1);
    cout << endl;
    return 0;
}