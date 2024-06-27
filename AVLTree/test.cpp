#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    struct Node<T> *leftChild;
    struct Node<T> *rightChild;
    int height;
};

template <class T>
class Tree
{
    protected:
        struct Node<T> *root;
    public:
        Tree();
        virtual void insertNode(T) = 0;
        virtual void deleteNode(T) = 0;
        ~Tree();
};

template <class T>
Tree<T>::Tree()
{
    this->root == nullptr;
}

template <class T>
Tree<T>::~Tree()
{
    delete this->root;
}

template <class T>
class AVLTree: public Tree<T>
{
    protected:
        void INORDER(struct Node<T> *root);
    public:
        AVLTree();
        void insertNode(T);
        void deleteNode(T);
        void inOrder();
        bool isEmpty();
        ~AVLTree();
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
void AVLTree<T>::deleteNode(T value)
{

}

template <class T>
bool AVLTree<T>::isEmpty()
{
    return (this->root == nullptr);
}

template <class T>
void AVLTree<T>::inOrder()
{
    if (!isEmpty())
    {
        INORDER(this->root);
        cout << endl;
        return ;
    }
    cout << "Invalid Operation! Tree is Empty" << endl;
    return ;
}

template <class T>
void AVLTree<T>::INORDER(struct Node<T> *root)
{
    if (root != nullptr)
    {
        INORDER(root->leftChild);
        cout << root->data << ' ';
        INORDER(root->rightChild);
    }
}

template <class T>
AVLTree<T>::~AVLTree()
{
    Tree<T>::Tree();
}

int main()
{
    
    return 0;
}