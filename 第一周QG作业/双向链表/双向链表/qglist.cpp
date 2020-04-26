#include"qglist.h"

/*
 * 初始化链表
 */
QGList::QGList()
{
    cout << "必须先初始化链表才能对链表进行后续操作..." << endl;
    Node* p;
    ElemType x;
    head = new Node;
    head->next = 0;
    tail = head;

    cout << "请输入你需要存储的数据(整数), 输入0来结束." << endl;
    cin >> x;
    cout << "你输入的数据为: " << x << endl;

    while (x != 0)
    {
        p = new Node;
        p->data = x;
        p->next = 0;
        p->prior = tail;
        tail->next = p;
        tail = p;

        cout << "请继续输入你需要存储的数据(整数), 输入0来结束" << endl;
        cin >> x;
        cout << "你输入的数据为: " << x << endl;
    }
};


/*
 * 销毁链表
 */
QGList::~QGList() 
{
    cout << "正在删除整个链表..." << endl;
    Node* p = head;

    while (p)
    {
        Node* q = p->next;
        delete p;
        p = q;
    }
    cout << "链表已经删除！" << endl;
};


/*
 * print函数，打印每个元素的数据
 */
void QGList::printList() 
{
    cout << "print函数进行中..." << endl;
    Node* p;
    p = head->next;
    while (p != tail)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << " 完成!" << endl;;
};


/*
 * 返回链表中第一个元素的引用
 */
QGList::ElemType& QGList::front()
{
    return head->next->data;
};


/*
 * 返回链表中最后一个元素的引用
 */
QGList::ElemType& QGList::back() 
{
    return tail->data;
};



/*
 * 在链表第一个元素前添加元素e
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
 * 删除链表第一个元素
 */
bool QGList::pop_front() 
{
    cout << "正在删除第一个元素..." << endl;
    Node* p;
    p = head->next;
    p->next->prior = head;
    head->next = p->next;
    delete p;
    p = 0;

    cout << "删除完成！" << endl;
    return 0;
};

/*
 * 在链表最后一个元素后添加元素e
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
 * 删除链表最后一个元素
 */
bool QGList::pop_back() 
{
    cout << "正在删除最后一个元素..." << endl;
    Node* p = head->next;
    ElemType t = 0;
    while (p->next->next != 0)
        p = p->next;
    delete tail;
    tail = p;
    tail->next = 0;

    cout << "删除完成！" << endl;
    return 0;
};

/*
 * 在链表的第index + 1个元素前插入元素e
 */
bool QGList::insert(unsigned int index, ElemType& e) 
{
    cout << "插入中..." << endl;
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
    cout << "插入完毕！" << endl;

    return 0;
};

/*
 * 删除任意位置元素
 */
bool QGList::erase(unsigned int index) 
{
    cout << "正在删除指定位置的元素" << endl;
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
    cout << "删除完成！" << endl;

    return 0;
};

/*
 * 清空链表
 */
bool QGList::clear() 
{
    cout << "正在清空列表..." << endl;
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
    cout << "清空完成！" << endl;

    return 0;
};

/*
 * 查找元素是否存在
 */
bool QGList::contain(ElemType& e) 
{
    cout << "正在查找元素..." << endl;
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
        cout << "你查找的元素存在于链表" << endl;
    else
        cout << "你查找的元素不存在于链表" << endl;
    return 0;
};

/*
 * 返回链表中元素的数量
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
 * 遍历链表, 对每个元素调用visit指向的函数
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