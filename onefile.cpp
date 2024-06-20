#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node<T> *leftChild;
    struct Node<T> *rightChild;
    char color;
};

template <class T>
class Tree
{
    protected:
        struct Node<T> *root;
    public:
        Tree();
        virtual void insertNode(T) = 0;
        virtual bool deleteNode(T) = 0;
        ~Tree()
        {
            delete this->root;
        }
};


template <class T>
Tree<T>::Tree()
{
    this->root = nullptr;
}


template <class T>
class RedBlackTree: public Tree<T>
{
    protected:
        void INORDER(struct Node<T> *root);
        void PREORDER(struct Node<T> *root);
        void POSTORDER(struct Node<T> *root);
    public:
        RedBlackTree();
        void insertNode(T);
        bool deleteNode(T);
        void inorderTraversal();
        void preorderTraversal();
        void postorderTraversal();
        bool search();
        bool isEmpty();
        void balancingFactor();
        void singleRotation();
        void doubleRotation();
        void diameter();
        void maxValue();
        void minValue();
        void successor(T);
        void predecessor(T);
        ~RedBlackTree(){}
};

template <class T>
RedBlackTree<T>::RedBlackTree():
    Tree<T>::Tree()
{}

template <class T>
void RedBlackTree<T>::insertNode(T value)
{
    
}

template <class T>
bool RedBlackTree<T>::deleteNode(T value)
{
    return false;
}

template <class T>
void RedBlackTree<T>::inorderTraversal()
{
    if (!isEmpty())
    {
        this->INORDER(this->root);
        cout << endl;
        return;
    }
    cout << "Invalid Operation! Empty Tree can't be used with this function" << endl;
}

template <class T>
void RedBlackTree<T>::preorderTraversal()
{
    if (!isEmpty())
    {
        this->PREORDER(this->root);
        cout << endl;
        return;
    }
    cout << "Invalid Operation! Empty Tree can't be used with this function" << endl;
}

template <class T>
void RedBlackTree<T>::postorderTraversal()
{
    if (!isEmpty())
    {
        this->POSTORDER(this->root);
        cout << endl;
        return;
    }
    cout << "Invalid Operation! Empty Tree can't be used with this function" << endl;
}

template <class T>
bool RedBlackTree<T>::isEmpty()
{
    return this->root == nullptr;
}

template <class T>
bool RedBlackTree<T>::search()
{
    return false;
}

template <class T>
void RedBlackTree<T>::balancingFactor()
{
    
}

template <class T>
void RedBlackTree<T>::singleRotation()
{
    
}

template <class T>
void RedBlackTree<T>::doubleRotation()
{
    
}

template <class T>
void RedBlackTree<T>::diameter()
{
    
}

template <class T>
void RedBlackTree<T>::maxValue()
{
    
}

template <class T>
void RedBlackTree<T>::minValue()
{
    
}

template <class T>
void RedBlackTree<T>::successor(T)
{
    
}

template <class T>
void RedBlackTree<T>::predecessor(T)
{
    
}

template <class T>
void RedBlackTree<T>::INORDER(struct Node<T> *root)
{
    if(!isEmpty())
    {
        INORDER(root->leftChild);
        cout << root->data << ' ';
        INORDER(root->rightChild);
    }
}

template <class T>
void RedBlackTree<T>::PREORDER(struct Node<T> *root)
{
    if (!isEmpty())
    {
        cout << root->data << ' ';
        PREORDER(root->leftChild);
        PREORDER(root->rightChild);
    }
}

template <class T>
void RedBlackTree<T>::POSTORDER(struct Node<T> *root)
{
    if (!isEmpty())
    {
        POSTORDER(root->leftChild);
        POSTORDER(root->rightChild);
        cout << root->data << ' ';
    }
}