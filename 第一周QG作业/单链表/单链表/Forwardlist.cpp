#include"Forwardlist.h"

/*
 * ��ʼ������
 */
QGForwardList::QGForwardList()
{
    cout << "�����ȳ�ʼ��������ܶ�������к�������..." << endl;
    Node* p = 0;
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
        tail->next = p;
        tail = p;
        tail->next = 0;
        cout << "�������������Ҫ�洢������(����), ����0������" << endl;
        cin >> x;
        cout << "�����������Ϊ: " << x << endl;
    }
};



/*
 * ��������
 */
QGForwardList::~QGForwardList() 
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
void QGForwardList::printList() {
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
QGForwardList::ElemType& QGForwardList::front()
{
    return head->next->data;
};



/*
 * �������������һ��Ԫ�ص�����
 */
QGForwardList::ElemType& QGForwardList::back()
{
    return tail->data;
};



/*
 * �������һ��Ԫ��ǰ���Ԫ��e
 */
bool QGForwardList::push_front(ElemType& e) 
{
    Node* frontAddNode = new Node;
    frontAddNode->next = head->next;
    frontAddNode->data = e;
    head->next = frontAddNode;
    
    return 0;
};



/*
 * ɾ�������һ��Ԫ��
 */
bool QGForwardList::pop_front() 
{
    cout << "����ɾ����һ��Ԫ��..." << endl;
    Node* p;
    p = head->next;
    head->next = p->next;
    delete p;
    p = 0;

    cout << "ɾ����ɣ�" << endl;
    return 0;
};



/*
 * ���������һ��Ԫ�غ����Ԫ��e
 */
bool QGForwardList::push_back(ElemType& e) 
{
    Node* TailAddNode = new Node;
    tail->next = TailAddNode;
    TailAddNode->data = e;
    TailAddNode->next = 0;
    tail = TailAddNode;

    return 0;
};



/*
 * ɾ���������һ��Ԫ��
 */
bool QGForwardList::pop_back() 
{
    cout << "����ɾ�����һ��Ԫ��..." << endl;
    Node* p=head->next;
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
bool QGForwardList::insert(unsigned int index, ElemType& e) 
{
    cout << "������..." << endl;
    Node* p;
    Node* q;
    Node* NewNode = new Node;

    p = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
    }

    q = p->next;
    p->next = NewNode;
    NewNode->next = q;
    NewNode->data = e;

    q = 0;
    p = 0; 
    cout << "������ϣ�" << endl;

    return 0;
};



/*
 * ɾ������λ��Ԫ��
 */
bool QGForwardList::erase(unsigned int index) 
{
    cout << "����ɾ��ָ��λ�õ�Ԫ��" << endl;
    Node* p;
    Node* q;

    p = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
    }
    q = p->next;
    delete p;

    p = head->next;
    for (int i = 0; i < index-2; i++)
    {
        p = p->next;
    }
    p->next = q;

    p = 0L;
    q = 0;
    cout << "ɾ����ɣ�" << endl;

    return 0;
};



/*
 * �������
 */
bool QGForwardList::clear()
{
    cout << "��������б�..." << endl;
    Node* p;
    Node* q;
    p = head->next;
    do{
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
bool QGForwardList::contain(ElemType& e)
{   
    cout << "���ڲ���Ԫ��..." << endl;
    ElemType temp = 0;
    Node* p= head->next;
    while (p != tail)
    {
        if (p->data == e)
            temp = 1;
        p = p->next;
    }
    if(p->data == e)
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
unsigned int QGForwardList::size() 
{
    ElemType i=0;
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
bool QGForwardList::traverse(void (*visit)(ElemType& e)) 
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



/*
 * ��ת����1234��ת����4321
 */
bool QGForwardList::reverse() 
{
    cout << "��ת������..." << endl;
    Node* p,* phead,* temp;
    phead = head->next;
    p = 0;
    while (phead != 0) {
        temp = p;
        p = phead;
        phead = phead->next;
        p->next = temp;
    }
    head->next = p;

    temp = head->next;
    while (temp->next != 0)
        temp = temp->next;
    tail = temp;

    temp = 0;
    p = 0;
    phead = 0;

    cout << "��ת��ɣ�" << endl;
    return 0;
};



/*
 * �����л�
 */
bool QGForwardList::isLoop() 
{
    Node* slow;
    Node* quick;
    slow = head;
    quick = head;
    do {
        if (quick == 0 || quick->next == 0) {
            cout << "�ⲻ��һ��ѭ������" << endl;
            break;
        }
        quick = quick->next->next;
        slow = slow->next;
    } while (quick != slow); 
    while (quick == slow)
        cout << "����һ��ѭ������" << endl;


    return 0;
};



/*
 * ż�ڵ㷴ת��1234��ת����2143
 */
bool QGForwardList::reverseEven()
{
    cout << "ż�ڵ㷴ת������..." << endl;
    Node* p = head->next;
    Node* q = head->next->next;
    Node* t = q ->next;
    Node* a = head;

    ElemType i = size();
    i = i / 2;
    cout << i << endl;
    for (;i>0; i--)
    {
        a->next = q;
        q->next = p;
        p->next = t;

        if (i > 1)
        {
            a = p;
            p = p->next;
            q = q->next->next->next;
            t = t->next->next;
        }
    }

    cout << "��ת��ɣ�" << endl;
    return 0;
};



/*
 * �����м�ڵ�
 */
QGForwardList::ElemType& QGForwardList::middleElem()
{ 
    Node* quick;
    Node* slow;
    ElemType i = 0;
    quick = head->next;
    slow = head->next;
    while (quick->next != 0 && quick->next->next != 0) 
    {
        quick = quick->next->next;
        slow = slow->next;
    }
    
    return slow->data;

};

