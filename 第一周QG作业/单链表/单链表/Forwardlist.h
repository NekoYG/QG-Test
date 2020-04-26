#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__
#include<iostream>
using namespace std;
/*
 * ��������
 */
class QGForwardList {

public:
	typedef int ElemType;

	struct Node 
	{
		ElemType data;
		struct Node* next;
	};
	Node* head;
	Node* tail;
	
public:

	/*
	 * ��ʼ������
	 */
	QGForwardList();


	/*
	* ��������
	*/
	~QGForwardList();

	void printList();//��ԭͷ�ļ������ϲ���һ��print����
	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	ElemType& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	ElemType& back();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(ElemType& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(ElemType& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, ElemType& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(ElemType& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(ElemType& e));

	/*
	 * ��ת����1234��ת����4321
	 */
	bool reverse();

	/*
	 * �����л�
	 */
	bool isLoop();

	/*
	 * ż�ڵ㷴ת��1234��ת����2143
	 */
	bool reverseEven();

	/*
	 * �����м�ڵ�
	 */
	ElemType& middleElem();
};

#endif
