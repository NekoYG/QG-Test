#include"BitTree.h"

int main()
{
    cout << "����������..." << endl;
    SqBiTree sbt;
    BitTree tree;
    //����˳�������
    tree.creat_tree(sbt);

    cout << "���������" << endl;
    tree.level_order(sbt);
    cout << endl;

    cout << "���������" << endl;
    tree.pre_order(sbt, 1);
    cout << endl;

    cout << "���������" << endl;
    tree.mid_order(sbt, 1);
    cout << endl;

    cout << "����������" << endl;
    tree.back_order(sbt, 1);
    cout << endl;
    return 0;
}