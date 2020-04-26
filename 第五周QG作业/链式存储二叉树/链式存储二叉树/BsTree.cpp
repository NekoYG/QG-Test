#include"BsTree.h"

bool BsTree::CreateBiTree(BiTree& T)
{
	ElemType s;
	string temp;
	cout << "�������Ĺ�������������������������������" << endl;
	cout << "��ʾ������������Ϻ���Ҫ������#�����ĵݹ鹹��ֹͣ" << endl;
	cout << "��ʾ������0��ֱ���˳�����" << endl;
	cout << "������һ���ַ�(������ַ�ֻʶ���һ��)��";
	cin >> temp;
	s = temp[0];
	if (s == '0') {
		exit(-1);
	}
	if (s == '#') {
		T = NULL;
	}
	else {
		//�������
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




//��ʼ��ѭ������
void BsTree::InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
//�ж϶ӿ�
bool BsTree::IsEmpty(SqQueue& Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}

//���һ��Ԫ��
bool BsTree::EnQueue(SqQueue& Q, BiTree x) {
	//�ж϶��Ƿ���
	if (Q.front == (Q.rear + 1) % MaxSize) {
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;

	return true;
}


//����һ��Ԫ��
bool  BsTree::DeQueue(SqQueue& Q, BiTree& x) {
	//�ж϶����Ƿ�Ϊ��
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
	//����������
	while (!IsEmpty(Q)) {
		DeQueue(Q, p);
		cout << " " << p->data;
		//������ӽ�����Ӳ��գ�����
		if (p->lchild != NULL) {
			EnQueue(Q, p->lchild);
		}
		//������ӽ���Һ��Ӳ��գ�����
		if (p->rchild != NULL) {
			EnQueue(Q, p->rchild);
		}
	}
}