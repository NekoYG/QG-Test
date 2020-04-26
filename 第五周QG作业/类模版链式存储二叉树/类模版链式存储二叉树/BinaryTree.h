#include <cstdlib>
#include <cstring>
#include <iostream>

// 二叉树类模版前置声明
template <typename T> class BinaryTree;

//
// 二叉树节点类模版. 
//
template <typename T>
class Node
{
    friend class BinaryTree<T>;
public:
    T data;
    Node<T>* pLeftChild, * pRightChild;

public:
    Node(const T& data):
        data(data), 
        pLeftChild(NULL), 
        pRightChild(NULL)
    {
        NULL;
    }
};

//
// 二叉树类模版 
//
template <typename T>
class BinaryTree
{
private:
    Node<T>* pRoot;

private:
    void create(Node<T>** ppRoot, T** ppArray, int* piSize, const T& delim);
    void clear(Node<T>* pRoot);
    void preOrder(Node<T>* pRoot) const;
    void inOrder(Node<T>* pRoot) const;
    void postOrder(Node<T>* pRoot) const;
    size_t height(Node<T>* pRoot) const;
    size_t count(Node<T>* pRoot) const;

public:
    // 遍历类型. 
    enum TraversalType {
        PRE_ORDER,
        IN_ORDER,
        POST_ORDER
    };

public:
    BinaryTree(T* array, int size, const T& delim);
    ~BinaryTree();
    void traversal(const TraversalType type) const;
    size_t getHeight() const;
    size_t getNumberOfNode() const;
};





template <typename T>
void BinaryTree<T>::create(Node<T>** ppRoot,T** ppArray,int* piSize,const T& delim)
{
    if (0 < *piSize && delim != **ppArray)
    {
        *ppRoot = new Node<T>(**ppArray);
        create(&((*ppRoot)->pLeftChild), &(++ * ppArray), &(-- * piSize), delim);
        create(&((*ppRoot)->pRightChild), &(++ * ppArray), &(-- * piSize), delim);
    }
}
//
// 删除所有节点. 
//
template <typename T>
void BinaryTree<T>::clear(Node<T>* pRoot)
{
    if (NULL != pRoot)
    {
        clear(pRoot->pLeftChild);
        clear(pRoot->pRightChild);
        delete pRoot;
    }
}

//
// 前序遍历. 
//
template <typename T>
void BinaryTree<T>::preOrder(Node<T>* pRoot) const
{
    if (NULL != pRoot)
    {
        std::cout << pRoot->data << " ";
        preOrder(pRoot->pLeftChild);
        preOrder(pRoot->pRightChild);
    }
}

//
// 中序遍历. 
//
template <typename T>
void BinaryTree<T>::inOrder(Node<T>* pRoot) const
{
    if (NULL != pRoot)
    {
        inOrder(pRoot->pLeftChild);
        std::cout << pRoot->data << " ";
        inOrder(pRoot->pRightChild);
    }
}

//
// 后序遍历. 
//
template <typename T>
void BinaryTree<T>::postOrder(Node<T>* pRoot) const
{
    if (NULL != pRoot)
    {
        postOrder(pRoot->pLeftChild);
        postOrder(pRoot->pRightChild);
        std::cout << pRoot->data << " ";
    }
}

//
// 通过后序遍历方式计算二叉树高度. 
//
template <typename T>
size_t BinaryTree<T>::height(Node<T>* pRoot) const
{
    static size_t h = 0, leftHeight = 0, rightHeight = 0;

    if (NULL != pRoot)
    {
        leftHeight = height(pRoot->pLeftChild);
        rightHeight = height(pRoot->pRightChild);

        h = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
    else {
        h = 0;
    }

    return h;
}

//
// 通过前序遍历方式计算二叉树节点数. 
//
template <typename T>
size_t BinaryTree<T>::count(Node<T>* pRoot) const
{
    static size_t counter = 0;

    if (NULL != pRoot) {
        counter = count(pRoot->pLeftChild) + count(pRoot->pRightChild) + 1;
    }
    else {
        counter = 0;
    }
    return counter;
}


template <typename T>
inline BinaryTree<T>::BinaryTree(T* array, int size, const T& delim)
{
    create(&pRoot, &array, &size, delim);
}


template <typename T>
inline BinaryTree<T>::~BinaryTree(void)
{
    clear(pRoot);
}

//
// 根据控制标识选择遍历方式. 
// 
template <typename T>
void BinaryTree<T>::traversal(const TraversalType type) const
{
    switch (type)
    {
    case PRE_ORDER:   preOrder(pRoot);  break;
    case IN_ORDER:   inOrder(pRoot);   break;
    case POST_ORDER:   postOrder(pRoot); break;
    }
}


template <typename T>
size_t BinaryTree<T>::getHeight(void) const
{
    return height(pRoot);
}


template <typename T>
size_t BinaryTree<T>::getNumberOfNode(void) const
{
    return count(pRoot);
}
