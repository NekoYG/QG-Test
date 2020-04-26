#include"BsTree.h"

bool BsTree::CreateBiTree(BiTree& T)
{
	ElemType s;
	string temp;
	cout << "二叉树的构建——————————————" << endl;
	cout << "提示：数据输入完毕后需要输入多次#将树的递归构建停止" << endl;
	cout << "提示：输入0可直接退出程序" << endl;
	cout << "请输入一个字符(输入多字符只识别第一个)：";
	cin >> temp;
	s = temp[0];
	if (s == '0') {
		exit(-1);
	}
	if (s == '#') {
		T = NULL;
	}
	else {
		//创建结点
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = s;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return true;
};

void BsTree::delAllNode(BiTree& T)
{

	if (T != NULL)

	{

		delAllNode(T->lchild);

		delAllNode(T->rchild);

		delete T;

	}

}


bool BsTree::PreOrder(BiTree& T) {
	if (T == NULL) {
		return 0;
	}
	cout << " " << T->data;
	PreOrder(T->lchild);
	PreOrder(T->rchild);
	return true;
}



bool BsTree::InOrder(BiTree& T) {
	if (T == NULL) {
		return 0;
	}
	InOrder(T->lchild);

	cout << " " << T->data;

	InOrder(T->rchild);
	return true;
}



bool BsTree::PostOrder(BiTree& T) {
	if (T == NULL) {
		return 0;
	}
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	cout << " " << T->data;
	return true;
}




//初始化循环队列
void BsTree::InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
//判断队空
bool BsTree::IsEmpty(SqQueue& Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}

//入队一个元素
bool BsTree::EnQueue(SqQueue& Q, BiTree x) {
	//判断队是否满
	if (Q.front == (Q.rear + 1) % MaxSize) {
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;

	return true;
}


//出队一个元素
bool  BsTree::DeQueue(SqQueue& Q, BiTree& x) {
	//判断队列是否为空
	if (Q.front == Q.rear) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}


void BsTree::LeverOrder(BiTree& T) {
	SqQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T);
	//将根结点入队
	while (!IsEmpty(Q)) {
		DeQueue(Q, p);
		cout << " " << p->data;
		//如果出队结点左孩子不空，进队
		if (p->lchild != NULL) {
			EnQueue(Q, p->lchild);
		}
		//如果出队结点右孩子不空，进队
		if (p->rchild != NULL) {
			EnQueue(Q, p->rchild);
		}
	}
}