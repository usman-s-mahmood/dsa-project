#include "AVLTree.h"

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
        bool check = false;
        SEARCH(this->root, value, check);
        if (check)
        {
            cout << "Value is Present in the AVL Tree!" << endl;
            return true;
        }
        else
        {
            cout << "Value is not found!" << endl;
            return false;
        }
    }
    cout << "Invalid Operation! Tree is Empty" << endl;
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
T AVLTree<T>::max_value_pro(struct Node<T> *root)
{
    if (root->rightChild != nullptr)
        return max_value_pro(root->rightChild);
    else
        return root->data;
}

template <class T>
T AVLTree<T>::min_value_pro(struct Node<T> *root)
{
    if (root->leftChild != nullptr)
        return min_value_pro(root->leftChild);
    else
        return root->data;
}

template <class T>
T AVLTree<T>::maxValue()
{
    if (!isEmpty())
    {
        T max = max_value_pro(this->root);
        cout << "Max Value is: " << max << endl;
        return max;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return T();
}

template <class T>
T AVLTree<T>::minValue()
{
    if (!isEmpty())
    {
        T min = min_value_pro(this->root);
        cout << "Minimum value is: " << min << endl;
        return min;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return T();
}
template <class T>
void AVLTree<T>::successor(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            int size = 0,
                itr = 0; 
            tree_size(this->root, size);
            T arr[size] = {0};
            convert_to_array(this->root, itr, arr);
            for (int i = 0; i < size; i++)
                if (arr[i] == value)
                {
                    cout << "Successor of " << value << " is: " << arr[i+1] << endl;
                    break;
                }
            return ;
        }
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void AVLTree<T>::predecessor(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            int size = 0,
                itr = 0; 
            tree_size(this->root, size);
            T arr[size] = {0};
            convert_to_array(this->root, itr, arr);
            for (int i = 0; i < size; i++)
                if (arr[i+1] == value)
                {
                    cout << "Predecessor of " << arr[i+1] << " is " << arr[i] << endl;
                    break;
                }
            return ;
        }
        return ;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
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

template <class T>
void AVLTree<T>::tree_size(struct Node<T> *root, int &size)
{
    if (root != nullptr)
    {
        tree_size(root->leftChild, size);
        size += 1;
        tree_size(root->rightChild, size);
    }
}

template <class T>
void AVLTree<T>::convert_to_array(struct Node<T> *root, int &itr, int *arr)
{
    if (root != nullptr)
    {
        convert_to_array(root->leftChild, itr, arr);
        arr[itr] = root->data;
        itr += 1;
        convert_to_array(root->rightChild, itr, arr);
    }
}

template <class T>
void AVLTree<T>::SEARCH(struct Node<T> *root, T value, bool &check)
{
    if (root != nullptr)
    {
        SEARCH(root->leftChild, value, check);
        if (root->data == value)
        {
            check = true;
            return ;
        }
        SEARCH(root->rightChild, value, check);
    }
}

template <class T>
void AVLTree<T>::PARENT(struct Node<T> *root, T value, T &parent_value)
{
    if (root->leftChild->data == value || root->rightChild->data == value)
    {
        parent_value = root->data;
        return ;
    }
    else if (root->leftChild == nullptr && root->rightChild)
        return ;
    else
    {
        if (value < root->data)
            PARENT(root->leftChild, value, parent_value);
        else
            PARENT(root->rightChild, value, parent_value);
    }
}

template <class T>
void AVLTree<T>::LEFTCHILD(struct Node<T> *root, T value, T &child_value)
{
    if (root->data == value && root->leftChild != nullptr)
    {
        child_value = root->leftChild->data;
        return ;
    }
    else if (root->leftChild == nullptr && root->rightChild == nullptr)
        return ;
    else
    {
        if (value < root->data)
            LEFTCHILD(root->leftChild, value, child_value);
        else
            LEFTCHILD(root->rightChild, value, child_value);
    }
}

template <class T>
void AVLTree<T>::RIGHTCHILD(struct Node<T> *root, T value, T &child_value)
{
    if (root->data == value && root->rightChild != nullptr)
    {
        child_value = root->rightChild->data;
        return ;
    }
    else if (root->leftChild == nullptr && root->rightChild == nullptr)
        return ;
    else
    {
        if (value < root->data)
            RIGHTCHILD(root->leftChild, value, child_value);
        else
            RIGHTCHILD(root->rightChild, value, child_value);
    }
}

template <class T>
T AVLTree<T>::right_child(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            T child_value = T();
            RIGHTCHILD(this->root, value, child_value);
            if (child_value != T())
            {
                cout << "Right Child of " << value << " is: " << child_value << endl;
                return child_value;
            }
            else
            {
                cout << value << " does not have any right child" << endl;
                return T();
            }
        }
        return T();
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return T();
}

template <class T>
T AVLTree<T>::left_child(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            T child_value = T();
            LEFTCHILD(this->root, value, child_value);
            if (child_value != T())
            {
                cout << "Left Child of " << value << " is: " << child_value << endl;
                return child_value;
            }
            else
            {
                cout << value << " does not have any left child" << endl;
                return T();   
            }
        }
        return T();
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return T();
}