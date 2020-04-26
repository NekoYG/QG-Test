#include"qglist.h"

/*
 * ��ʼ������
 */
QGList::QGList()
{
    cout << "�����ȳ�ʼ��������ܶ�������к�������..." << endl;
    Node* p;
    ElemType x;
    head = new Node;
    head->next = 0;
    tail = head;

    cout << "����������Ҫ�洢������(����), ����0������." << endl;
    cin >> x;
    cout << "�����������Ϊ: " << x << endl;

    while (x != 0)
    {
        p = new Node;
        p->data = x;
        p->next = 0;
        p->prior = tail;
        tail->next = p;
        tail = p;

        cout << "�������������Ҫ�洢������(����), ����0������" << endl;
        cin >> x;
        cout << "�����������Ϊ: " << x << endl;
    }
};


/*
 * ��������
 */
QGList::~QGList() 
{
    cout << "����ɾ����������..." << endl;
    Node* p = head;

    while (p)
    {
        Node* q = p->next;
        delete p;
        p = q;
    }
    cout << "�����Ѿ�ɾ����" << endl;
};


/*
 * print��������ӡÿ��Ԫ�ص�����
 */
void QGList::printList() 
{
    cout << "print����������..." << endl;
    Node* p;
    p = head->next;
    while (p != tail)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << " ���!" << endl;;
};


/*
 * ���������е�һ��Ԫ�ص�����
 */
QGList::ElemType& QGList::front()
{
    return head->next->data;
};


/*
 * �������������һ��Ԫ�ص�����
 */
QGList::ElemType& QGList::back() 
{
    return tail->data;
};



/*
 * �������һ��Ԫ��ǰ���Ԫ��e
 */
bool QGList::push_front(ElemType& e) 
{
    Node* frontAddNode = new Node;
    frontAddNode->next = head->next;
    frontAddNode->prior = head;
    frontAddNode->data = e;
    head->next = frontAddNode;

    return 0;
};

/*
 * ɾ�������һ��Ԫ��
 */
bool QGList::pop_front() 
{
    cout << "����ɾ����һ��Ԫ��..." << endl;
    Node* p;
    p = head->next;
    p->next->prior = head;
    head->next = p->next;
    delete p;
    p = 0;

    cout << "ɾ����ɣ�" << endl;
    return 0;
};

/*
 * ���������һ��Ԫ�غ����Ԫ��e
 */
bool QGList::push_back(ElemType& e) 
{
    Node* TailAddNode = new Node;
    tail->next = TailAddNode;
    TailAddNode->data = e;
    TailAddNode->next = 0;
    TailAddNode->prior = tail;
    tail = TailAddNode;

    return 0;
};

/*
 * ɾ���������һ��Ԫ��
 */
bool QGList::pop_back() 
{
    cout << "����ɾ�����һ��Ԫ��..." << endl;
    Node* p = head->next;
    ElemType t = 0;
    while (p->next->next != 0)
        p = p->next;
    delete tail;
    tail = p;
    tail->next = 0;

    cout << "ɾ����ɣ�" << endl;
    return 0;
};

/*
 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
 */
bool QGList::insert(unsigned int index, ElemType& e) 
{
    cout << "������..." << endl;
    Node* p;
    Node* q;
    Node* NewNode = new Node;

    p = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }

    q = p->next;
    p->next = NewNode;
    NewNode->prior = p;
    NewNode->next = q;
    q->prior = NewNode;
    NewNode->data = e;

    q = 0;
    p = 0;
    cout << "������ϣ�" << endl;

    return 0;
};

/*
 * ɾ������λ��Ԫ��
 */
bool QGList::erase(unsigned int index) 
{
    cout << "����ɾ��ָ��λ�õ�Ԫ��" << endl;
    Node* p;
    Node* q;

    p = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    q = p->next;
    delete p;

    p = head->next;
    for (int i = 0; i < index - 2; i++)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;

    p = 0;
    q = 0;
    cout << "ɾ����ɣ�" << endl;

    return 0;
};

/*
 * �������
 */
bool QGList::clear() 
{
    cout << "��������б�..." << endl;
    Node* p;
    Node* q;
    p = head->next;
    do {
        q = p->next;
        delete p;
        p = q;
    } while (p->next = 0);
    delete p;

    p = 0;
    q = 0;
    head->next = 0;
    cout << "�����ɣ�" << endl;

    return 0;
};

/*
 * ����Ԫ���Ƿ����
 */
bool QGList::contain(ElemType& e) 
{
    cout << "���ڲ���Ԫ��..." << endl;
    ElemType temp = 0;
    Node* p = head->next;
    while (p != tail)
    {
        if (p->data == e)
            temp = 1;
        p = p->next;
    }
    if (p->data == e)
        temp = 1;

    if (temp == 1)
        cout << "����ҵ�Ԫ�ش���������" << endl;
    else
        cout << "����ҵ�Ԫ�ز�����������" << endl;
    return 0;
};

/*
 * ����������Ԫ�ص�����
 */
unsigned int QGList::size() 
{
    ElemType i = 0;
    Node* p = head->next;
    while (p != tail)
    {
        i++;
        p = p->next;
    }
    i++;

    return i;
};

/*
 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
 */
bool QGList::traverse(void (*visit)(ElemType& e)) 
{
    Node* p;
    ElemType i;
    p = head->next;
    for (i = 0; p->next != NULL; i++) {}
    i++;
    for (int j = 0; j < i; j++)
    {
        (*visit)(p->data);
        p = p->next;
    }

    return 0;
};