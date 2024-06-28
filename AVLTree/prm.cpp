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
        virtual bool deleteNode(T) = 0;
        ~Tree();
};

template <class T>
Tree<T>::Tree()
{
    this->root = nullptr;
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
        bool deleteNode(T);
        bool isEmpty();
        void inOrder();
        ~AVLTree();
};

template <class T>
AVLTree<T>::AVLTree():
    Tree<T>::Tree()
{}

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
bool AVLTree<T>::isEmpty()
{
    return (this->root == nullptr);
}

template <class T>
void AVLTree<T>::insertNode(T value)
{

}

template <class T>
bool AVLTree<T>::deleteNode(T value)
{
    if (!isEmpty())
    {
        // delete the node with value
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return false;
}

template <class T>
void AVLTree<T>::inOrder()
{
    if (!isEmpty())
    {
        INORDER(this->root);
        cout << endl;
    }
    cout << "Invalid Operation! Tree is Empty" << endl;
    return ;
}

template <class T>
AVLTree<T>::~AVLTree()
{
    Tree<T>::~Tree();
}
int main()
{
    AVLTree<int> obj;
    return 0;
}

