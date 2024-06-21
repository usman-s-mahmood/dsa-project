#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>

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
        bool search(T);
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
bool AVLTree<T>::search(T value)
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
    int ch = -1;
    while (ch != 0)
    {
        cout << "Welcome to AVL Tree Demonstration System!" << endl
            << "1. To insert a value" << endl
            << "2. To delete a value" << endl
            << "3. To search a value" << endl
            << "4. To perform Inorder Traversal" << endl
            << "5. To perform Preorder Traversal" << endl
            << "6. To perform Postorder Traversal" << endl
            << "7. To calculate height of tree" << endl
            << "8. To calculate balancing factor of tree" << endl
            << "9. To perform single rotation" << endl
            << "10. To perform double rotation" << endl
            << "11. To calculate diameter of tree" << endl
            << "12. To Find minimum element in tree" << endl
            << "13. To Find maximum element in tree" << endl
            << "14. To Find Successor of a node" << endl
            << "15. To Find Predecessor of a node" << endl
            << "0. To exit" << endl
        << "Enter your Choice: ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter a value for insertion: ";
            int value;
            cin >> value;
            obj.insertNode(value);
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 2)
        {
            cout << "Enter a value for deletion: ";
            int value;
            cin >> value;
            obj.deleteNode(value);
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 3)
        {
            cout << "Enter a value for searching: ";
            int value;
            cin >> value;
            obj.search(value);
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 4)
        {
            obj.inorderTraversal();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 5)
        {
            obj.preorderTraversal();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 6)
        {
            obj.postorderTraversal();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 7)
        {
            obj.height();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 8)
        {
            obj.balancingFactor();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 9)
        {
            obj.singleRotation();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 10)
        {
            obj.doubleRotation();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 11)
        {
            obj.diameter();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 12)
        {
            obj.minValue();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 13)
        {
            obj.maxValue();
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 14)
        {
            obj.inorderTraversal();
            cout << "Enter a value within this range to check it's successor";
            int value;
            cin >> value;
            obj.successor(value);
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 15)
        {
            obj.inorderTraversal();
            cout << "Enter a value within this range to check it's predecessor";
            int value;
            cin >> value;
            obj.successor(value);
            cout << "press any key to continue" << endl;
            getch();
        }
        else if (ch == 0)
        {
            cout << "Program Terminated!" << endl;
            break;
        }
        else
        {
            cout << "Invalid Option! Program Terminated" << endl;
            break;
        }
    }
    return 0;
}