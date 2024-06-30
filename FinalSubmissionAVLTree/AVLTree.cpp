#include "AVLTree.h"


template <class T>
AVLTree<T>::AVLTree():
    Tree<T>::Tree()
{}

template <class T>
void AVLTree<T>::insertNode(T value)
{
    this->root = insertHelper(this->root, value);
}

template <class T>
bool AVLTree<T>::deleteNode(T value)
{
    if (!isEmpty()) {
        if (search(value))
        {
            this->root = deleteHelper(this->root, value);
            cout << value << " is deleted from the tree" << endl;
            return true;
        }
        return false;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return false;
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
int AVLTree<T>::height_of_node(int value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            struct Node<T> *temp  = this->root;
            while (true)
            {
                if (temp->data == value)
                    break;
                if (value < temp->data)
                    temp = temp->leftChild;
                else
                    temp = temp->rightChild;
            }
            T ht = height(temp);
            cout << "Height of " << value << " is: " << ht << endl;
            return ht;
            
        }
        return 0;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return 0;
}

template <class T>
void AVLTree<T>::balanceFactorHelper(Node<T> *root) {
    if (root != nullptr) {
        balanceFactorHelper(root->leftChild);
        int leftHeight = (root->leftChild != nullptr) ? root->leftChild->height : 0;
        int rightHeight = (root->rightChild != nullptr) ? root->rightChild->height : 0;
        int balanceFactor = leftHeight - rightHeight;
        cout << "Node: " << root->data << " Balance Factor: " << balanceFactor << endl;
        balanceFactorHelper(root->rightChild);
    }
}

template <class T>
void AVLTree<T>::balanceFactor() {
    if (!isEmpty()) {
        balanceFactorHelper(this->root);
    } else {
        cout << "Invalid Operation! Tree is Empty" << endl;
    }
}
template <class T>
void AVLTree<T>::singleRotation()
{
    if (!isEmpty())
    {
        cout << "Enter 1 for single left rotation and 2 for single right rotation: ";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            this->leftRotate(this->root);
            cout << "Inorder Traversal after single left rotate" << endl;
            this->inOrder();
            return ;
        }
        else if (ch == 2)
        {
            this->rightRotate(this->root);
            cout << "Inorder Traversal after single right rotate" << endl;
            this->inOrder();
            return ;
        }
        else
        {
            cout << "Invalid Option!" << endl;
            return ;
        }
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
}

template <class T>
void AVLTree<T>::doubleRotation()
{
    if (!isEmpty())
    {
        cout << "Enter 1 for double left rotation and 2 for double right rotation: ";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            this->leftRotate(this->root);
            this->leftRotate(this->root);
            cout << "Inorder Traversal after double left rotate" << endl;
            this->inOrder();
            return ;
        }
        else if (ch == 2)
        {
            this->rightRotate(this->root);
            this->rightRotate(this->root);
            cout << "Inorder Traversal after double right rotate" << endl;
            this->inOrder();
            return ;
        }
        else
        {
            cout << "Invalid Option!" << endl;
            return ;
        }
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return ;
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

// -- --

template <class T>
int AVLTree<T>::height(Node<T> *node) 
{
    return node ? node->height : 0;
}

template <class T>
int AVLTree<T>::getBalance(Node<T> *node) 
{
    return node ? height(node->leftChild) - height(node->rightChild) : 0;
}

template <class T>
Node<T>* AVLTree<T>::rightRotate(Node<T> *y) 
{
    Node<T> *x = y->leftChild;
    Node<T> *T2 = x->rightChild;
    x->rightChild = y;
    y->leftChild = T2;
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    return x;
}

template <class T>
Node<T>* AVLTree<T>::leftRotate(Node<T> *x) 
{
    Node<T> *y = x->rightChild;
    Node<T> *T2 = y->leftChild;
    y->leftChild = x;
    x->rightChild = T2;
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
    return y;
}

template <class T>
Node<T>* AVLTree<T>::insertHelper(Node<T> *node, T value) 
{
    if (node == nullptr) 
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = value;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (value < node->data)
        node->leftChild = insertHelper(node->leftChild, value);
    else if (value > node->data)
        node->rightChild = insertHelper(node->rightChild, value);
    else
        return node;

    node->height = 1 + max(height(node->leftChild), height(node->rightChild));

    int balance = getBalance(node);

    if (balance > 1 && value < node->leftChild->data)
        return rightRotate(node);

    if (balance < -1 && value > node->rightChild->data)
        return leftRotate(node);

    if (balance > 1 && value > node->leftChild->data) {
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->rightChild->data) {
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node;
}

template <class T>
Node<T>* AVLTree<T>::deleteHelper(Node<T> *root, T value) 
{
    if (root == nullptr)
        return root;

    if (value < root->data)
        root->leftChild = deleteHelper(root->leftChild, value);
    else if (value > root->data)
        root->rightChild = deleteHelper(root->rightChild, value);
    else 
    {
        if ((root->leftChild == nullptr) || (root->rightChild == nullptr)) 
        {
            Node<T> *temp = root->leftChild ? root->leftChild : root->rightChild;
            if (temp == nullptr) 
            {
                temp = root;
                root = nullptr;
            } 
            else
                *root = *temp;
            delete temp;
        } 
        else 
        {
            Node<T> *temp = minValueNode(root->rightChild);
            root->data = temp->data;
            root->rightChild = deleteHelper(root->rightChild, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->leftChild), height(root->rightChild));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->leftChild) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->leftChild) < 0) 
    {
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->rightChild) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->rightChild) > 0) 
    {
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }

    return root;
}

template <class T>
Node<T>* AVLTree<T>::minValueNode(Node<T> *node) 
{
    Node<T> *current = node;
    while (current->leftChild != nullptr)
        current = current->leftChild;
    return current;
}

template <class T>
void AVLTree<T>::inOrderHelper(Node<T> *root) 
{
    if (root != nullptr) 
    {
        inOrderHelper(root->leftChild);
        cout << root->data << ' ';
        inOrderHelper(root->rightChild);
    }
}


template <class T>
void AVLTree<T>::inOrder() 
{
    if (!isEmpty()) 
    {
        inOrderHelper(this->root);
        cout << endl;
    } 
    else
        cout << "Invalid Operation! Tree is Empty" << endl;
}


template <class T>
void AVLTree<T>::postOrderHelper(Node<T> *root) 
{
    if (root != nullptr) 
    {
        postOrderHelper(root->leftChild);
        postOrderHelper(root->rightChild);
        cout << root->data << ' ';
    }
}

template <class T>
void AVLTree<T>::preOrderHelper(struct Node<T> *root)
{
    if (root != nullptr)
    {
        cout << root->data << ' ';
        preOrderHelper(root->leftChild);
        preOrderHelper(root->rightChild);
    }
}

template <class T>
void AVLTree<T>::preOrder() 
{
    if (!isEmpty()) 
    {
        preOrderHelper(this->root);
        cout << endl;
    } 
    else 
        cout << "Invalid Operation! Tree is Empty" << endl;
}

template <class T>
void AVLTree<T>::postOrder() 
{
    if (!isEmpty()) {
        postOrderHelper(this->root);
        cout << endl;
    } 
    else 
    {
        cout << "Invalid Operation! Tree is Empty" << endl;
    }
}

template <class T>
int AVLTree<T>::diameterHelper(Node<T> *root, int &height) 
{
    if (root == nullptr) 
    {
        height = 0;
        return 0;
    }

    int leftHeight = 0, rightHeight = 0;
    int leftDiameter = diameterHelper(root->leftChild, leftHeight);
    int rightDiameter = diameterHelper(root->rightChild, rightHeight);

    height = max(leftHeight, rightHeight) + 1;

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

template <class T>
int AVLTree<T>::diameter() 
{
    if (!isEmpty())
    {
        int height = 0,
            d = diameterHelper(this->root, height);
        cout << "Diameter of tree is: " << d << endl;
        return d;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return -1;
}

template <class T>
int AVLTree<T>::size_of_tree()
{
    if (!isEmpty())
    {
        int size = 0;
        this->tree_size(this->root, size);
        cout << "Size of Tree is: " << size << endl;
        return size;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return 0;
}

template <class T>
AVLTree<T>::~AVLTree()
{
    int size = 0,
        itr = 0;
    tree_size(this->root, size);
    int arr[size] = {0};
    convert_to_array(this->root, itr, arr);
    for (int i = 0; i < size; i++)
        this->deleteHelper(this->root, arr[i]);
    Tree<T>::~Tree();
}

template <class T>
T AVLTree<T>::parent_node(T value)
{
    if (!isEmpty())
    {
        if (search(value))
        {
            if (value == this->root->data)
            {
                cout << "This value is of Root node and root has no parent" << endl;
                return T();
            }
            T parent_value = T();
            PARENT(this->root, value, parent_value);
            cout << "Parent Node of " << value << " is: " << parent_value << endl;
            return parent_value;
        }
        return 0;
    }
    cout << "Invalid Operation! Tree is empty" << endl;
    return 0;
}

template <class T>
int AVLTree<T>::root_value()
{
    if (!isEmpty())
    {
        T rootVal = T();
        rootVal = this->root->data;
        cout << "Value of Root is: " << rootVal << endl;
        return rootVal;
    }
    cout << "Invalid Operation! Tree is Empty" << endl;
    return 0;
}

// -- -- 
