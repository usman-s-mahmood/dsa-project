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
class AVLTree: public Tree<T>
{
    protected:
        void INORDER(struct Node<T> *root);
        void PREORDER(struct Node<T> *root);
        void POSTORDER(struct Node<T> *root);
        void HEIGHT(struct Node<T> *root);
    public:
        AVLTree();
        void insertNode(T);
        bool deleteNode(T);
        void inorderTraversal();
        void preorderTraversal();
        void postorderTraversal();
        bool search();
        void height();
        bool isEmpty();
        void balancingFactor();
        void singleRotation();
        void doubleRotation();
        void diameter();
        void maxValue();
        void minValue();
        void successor(T);
        void predecessor(T);
        ~AVLTree(){}
};

template <class T>
AVLTree<T>::AVLTree():
    Tree<T>::Tree()
{}

template <class T>
void AVLTree<T>::insertNode(T value)
{
    
}

template <class T>
bool AVLTree<T>::deleteNode(T value)
{
    return false;
}

template <class T>
void AVLTree<T>::inorderTraversal()
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
void AVLTree<T>::preorderTraversal()
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
void AVLTree<T>::postorderTraversal()
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
bool AVLTree<T>::isEmpty()
{
    return this->root == nullptr;
}

template <class T>
bool AVLTree<T>::search()
{
    return false;
}

template <class T>
void AVLTree<T>::height()
{
    
}

template <class T>
void AVLTree<T>::balancingFactor()
{
    
}

template <class T>
void AVLTree<T>::singleRotation()
{
    
}

template <class T>
void AVLTree<T>::doubleRotation()
{
    
}

template <class T>
void AVLTree<T>::diameter()
{
    
}

template <class T>
void AVLTree<T>::maxValue()
{
    
}

template <class T>
void AVLTree<T>::minValue()
{
    
}

template <class T>
void AVLTree<T>::successor(T)
{
    
}

template <class T>
void AVLTree<T>::predecessor(T)
{
    
}

template <class T>
void AVLTree<T>::INORDER(struct Node<T> *root)
{
    if(!isEmpty())
    {
        INORDER(root->leftChild);
        cout << root->data << ' ';
        INORDER(root->rightChild);
    }
}

template <class T>
void AVLTree<T>::PREORDER(struct Node<T> *root)
{
    if (!isEmpty())
    {
        cout << root->data << ' ';
        PREORDER(root->leftChild);
        PREORDER(root->rightChild);
    }
}

template <class T>
void AVLTree<T>::POSTORDER(struct Node<T> *root)
{
    if (!isEmpty())
    {
        POSTORDER(root->leftChild);
        POSTORDER(root->rightChild);
        cout << root->data << ' ';
    }
}


template <class T>
void AVLTree<T>::HEIGHT(struct Node<T> *root)
{
    
}


int main()
{
    AVLTree<int> obj;
    return 0;
}