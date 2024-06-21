#include "RedBlackTree.h"

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
bool RedBlackTree<T>::search(T value)
{
    if (!isEmpty())
    {
        if (value == this->root->data)
        {
            cout << "Value found at root Node!" << endl;
            return true;
        }
        struct Node<T> *temp = this->root;
        while (temp != nullptr)
        {
            if (value == temp->data)
            {
                cout << "Value found in the tree!" << endl;
                return true;
            }
            else if (value < temp->data)
                temp = temp->leftChild; 
            else
                temp = temp->rightChild; 
        }
    }
    cout << "Tree is empty! Value is not found" << endl;
    return false;
}

template <class T>
void RedBlackTree<T>::height()
{
    
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

template <class T>
void RedBlackTree<T>::HEIGHT(struct Node<T> *root)
{
    
}