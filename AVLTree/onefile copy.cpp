#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>

using namespace std;

template <class T>
struct Node {
    T data;
    struct Node<T>* leftChild;
    struct Node<T>* rightChild;
    int height;
};

template <class T>
class Tree {
protected:
    struct Node<T>* root;
public:
    Tree();
    virtual void insertNode(T) = 0;
    virtual bool deleteNode(T) = 0;
    virtual bool isEmpty() = 0;
    virtual ~Tree() {
        delete this->root;
    }
};

template <class T>
Tree<T>::Tree() {
    this->root = nullptr;
}

template <class T>
class AVLTree : public Tree<T> {
protected:
    int height(struct Node<T>* n);
    int getBalanceFactor(struct Node<T>* n);
    struct Node<T>* rightRotate(struct Node<T>* y);
    struct Node<T>* leftRotate(struct Node<T>* x);
    struct Node<T>* insert(struct Node<T>* node, T key);
    struct Node<T>* deleteNodeHelper(struct Node<T>* root, T key);
    struct Node<T>* minValueNode(struct Node<T>* node);
    struct Node<T>* maxValueNode(struct Node<T>* node);
    struct Node<T>* successorNode(struct Node<T>* node);
    struct Node<T>* predecessorNode(struct Node<T>* node);
    void inorder(struct Node<T>* node);
    void preorder(struct Node<T>* node);
    void postorder(struct Node<T>* node);
    int heightHelper(struct Node<T>* node);
    int diameterHelper(struct Node<T>* node, int& height);
    void calculateBalanceFactor(struct Node<T>* node);

public:
    AVLTree();
    void insertNode(T key);
    bool deleteNode(T key);
    bool search(T value);
    bool isEmpty();
    void balancingFactor();
    void singleRotation();
    void doubleRotation();
    void diameter();
    void maxValue();
    void minValue();
    void successor(T key);
    void predecessor(T key);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void height();
    ~AVLTree() {
        Tree<T>::~Tree();
    }
};

template <class T>
AVLTree<T>::AVLTree() : Tree<T>() {}

template <class T>
int AVLTree<T>::height(struct Node<T>* n) {
    return n == nullptr ? 0 : n->height;
}

template <class T>
int AVLTree<T>::getBalanceFactor(struct Node<T>* n) {
    return n == nullptr ? 0 : height(n->leftChild) - height(n->rightChild);
}

template <class T>
struct Node<T>* AVLTree<T>::rightRotate(struct Node<T>* y) {
    struct Node<T>* x = y->leftChild;
    struct Node<T>* T2 = x->rightChild;

    x->rightChild = y;
    y->leftChild = T2;

    y->height = fmax(height(y->leftChild), height(y->rightChild)) + 1;
    x->height = fmax(height(x->leftChild), height(x->rightChild)) + 1;

    return x;
}

template <class T>
struct Node<T>* AVLTree<T>::leftRotate(struct Node<T>* x) {
    struct Node<T>* y = x->rightChild;
    struct Node<T>* T2 = y->leftChild;

    y->leftChild = x;
    x->rightChild = T2;

    x->height = fmax(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = fmax(height(y->leftChild), height(y->rightChild)) + 1;

    return y;
}

template <class T>
struct Node<T>* AVLTree<T>::insert(struct Node<T>* node, T key) {
    if (node == nullptr) {
        struct Node<T>* newNode = new Node<T>();
        newNode->data = key;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->data)
        node->leftChild = insert(node->leftChild, key);
    else if (key > node->data)
        node->rightChild = insert(node->rightChild, key);
    else
        return node;

    node->height = 1 + fmax(height(node->leftChild), height(node->rightChild));

    int balance = getBalanceFactor(node);

    if (balance > 1 && key < node->leftChild->data)
        return rightRotate(node);

    if (balance < -1 && key > node->rightChild->data)
        return leftRotate(node);

    if (balance > 1 && key > node->leftChild->data) {
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->rightChild->data) {
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node;
}

template <class T>
struct Node<T>* AVLTree<T>::minValueNode(struct Node<T>* node) {
    struct Node<T>* current = node;

    while (current->leftChild != nullptr)
        current = current->leftChild;

    return current;
}

template <class T>
struct Node<T>* AVLTree<T>::maxValueNode(struct Node<T>* node) {
    struct Node<T>* current = node;

    while (current->rightChild != nullptr)
        current = current->rightChild;

    return current;
}

template <class T>
struct Node<T>* AVLTree<T>::successorNode(struct Node<T>* node) {
    if (node == nullptr || node->rightChild == nullptr)
        return nullptr;

    struct Node<T>* current = node->rightChild;
    while (current->leftChild != nullptr)
        current = current->leftChild;

    return current;
}

template <class T>
struct Node<T>* AVLTree<T>::predecessorNode(struct Node<T>* node) {
    if (node == nullptr || node->leftChild == nullptr)
        return nullptr;

    struct Node<T>* current = node->leftChild;
    while (current->rightChild != nullptr)
        current = current->rightChild;

    return current;
}

template <class T>
struct Node<T>* AVLTree<T>::deleteNodeHelper(struct Node<T>* root, T key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->leftChild = deleteNodeHelper(root->leftChild, key);
    else if (key > root->data)
        root->rightChild = deleteNodeHelper(root->rightChild, key);
    else {
        if ((root->leftChild == nullptr) || (root->rightChild == nullptr)) {
            struct Node<T>* temp = root->leftChild ? root->leftChild : root->rightChild;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            struct Node<T>* temp = minValueNode(root->rightChild);

            root->data = temp->data;

            root->rightChild = deleteNodeHelper(root->rightChild, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + fmax(height(root->leftChild), height(root->rightChild));

    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->leftChild) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalanceFactor(root->leftChild) < 0) {
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->rightChild) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalanceFactor(root->rightChild) > 0) {
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }

    return root;
}

template <class T>
void AVLTree<T>::insertNode(T key) {
    this->root = insert(this->root, key);
}

template <class T>
bool AVLTree<T>::deleteNode(T key) {
    this->root = deleteNodeHelper(this->root, key);
    return (this->root != nullptr);
}

template <class T>
bool AVLTree<T>::search(T value) {
    if (isEmpty()) {
        return false;
    }

    struct Node<T>* temp = this->root;
    while (temp != nullptr) {
        if (value == temp->data) {
            return true;
        } else if (value < temp->data) {
            temp = temp->leftChild;
        } else {
            temp = temp->rightChild;
        }
    }
    return false;
}

template <class T>
bool AVLTree<T>::isEmpty() {
    return this->root == nullptr;
}

template <class T>
void AVLTree<T>::calculateBalanceFactor(struct Node<T>* node) {
    if (node != nullptr) {
        calculateBalanceFactor(node->leftChild);
        cout << "Node: " << node->data << ", Balance Factor: " << getBalanceFactor(node) << endl;
        calculateBalanceFactor(node->rightChild);
    }
}

template <class T>
void AVLTree<T>::balancingFactor() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        calculateBalanceFactor(this->root);
    }
}

template <class T>
void AVLTree<T>::singleRotation() {
    cout << "Single Rotation can be either left or right rotation, depending on the tree's balance state." << endl;
    // This method is already implemented as leftRotate and rightRotate
}

template <class T>
void AVLTree<T>::doubleRotation() {
    cout << "Double Rotation can be either left-right or right-left rotation, depending on the tree's balance state." << endl;
    // This method is already handled in the insert and delete functions through the existing rotations
}

template <class T>
void AVLTree<T>::diameter() {
    int height = 0;
    cout << "Diameter of the tree: " << diameterHelper(this->root, height) << endl;
}

template <class T>
int AVLTree<T>::diameterHelper(struct Node<T>* node, int& height) {
    if (node == nullptr) {
        height = 0;
        return 0;
    }

    int leftHeight = 0, rightHeight = 0;
    int leftDiameter = diameterHelper(node->leftChild, leftHeight);
    int rightDiameter = diameterHelper(node->rightChild, rightHeight);

    height = fmax(leftHeight, rightHeight) + 1;

    return fmax(leftHeight + rightHeight + 1, fmax(leftDiameter, rightDiameter));
}

template <class T>
void AVLTree<T>::maxValue() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        struct Node<T>* maxNode = maxValueNode(this->root);
        cout << "Maximum value: " << maxNode->data << endl;
    }
}

template <class T>
void AVLTree<T>::minValue() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        struct Node<T>* minNode = minValueNode(this->root);
        cout << "Minimum value: " << minNode->data << endl;
    }
}

template <class T>
void AVLTree<T>::successor(T key) {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
        return;
    }

    struct Node<T>* current = this->root;
    while (current != nullptr) {
        if (key < current->data) {
            current = current->leftChild;
        } else if (key > current->data) {
            current = current->rightChild;
        } else {
            break;
        }
    }

    if (current == nullptr) {
        cout << "Key not found in the tree." << endl;
        return;
    }

    struct Node<T>* succ = successorNode(current);
    if (succ != nullptr) {
        cout << "Successor of " << key << " is: " << succ->data << endl;
    } else {
        cout << "No successor found for " << key << endl;
    }
}

template <class T>
void AVLTree<T>::predecessor(T key) {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
        return;
    }

    struct Node<T>* current = this->root;
    while (current != nullptr) {
        if (key < current->data) {
            current = current->leftChild;
        } else if (key > current->data) {
            current = current->rightChild;
        } else {
            break;
        }
    }

    if (current == nullptr) {
        cout << "Key not found in the tree." << endl;
        return;
    }

    struct Node<T>* pred = predecessorNode(current);
    if (pred != nullptr) {
        cout << "Predecessor of " << key << " is: " << pred->data << endl;
    } else {
        cout << "No predecessor found for " << key << endl;
    }
}

template <class T>
void AVLTree<T>::inorder(struct Node<T>* node) {
    if (node != nullptr) {
        inorder(node->leftChild);
        cout << node->data << " ";
        inorder(node->rightChild);
    }
}

template <class T>
void AVLTree<T>::preorder(struct Node<T>* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorder(node->leftChild);
        preorder(node->rightChild);
    }
}

template <class T>
void AVLTree<T>::postorder(struct Node<T>* node) {
    if (node != nullptr) {
        postorder(node->leftChild);
        postorder(node->rightChild);
        cout << node->data << " ";
    }
}

template <class T>
void AVLTree<T>::inorderTraversal() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        inorder(this->root);
        cout << endl;
    }
}

template <class T>
void AVLTree<T>::preorderTraversal() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        preorder(this->root);
        cout << endl;
    }
}

template <class T>
void AVLTree<T>::postorderTraversal() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        postorder(this->root);
        cout << endl;
    }
}

template <class T>
void AVLTree<T>::height() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        cout << "Height of the tree: " << heightHelper(this->root) << endl;
    }
}

template <class T>
int AVLTree<T>::heightHelper(struct Node<T>* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return fmax(heightHelper(node->leftChild), heightHelper(node->rightChild)) + 1;
    }
}

// int main() {
//     AVLTree<int> tree;

//     // Inserting nodes
//     tree.insertNode(10);
//     tree.insertNode(20);
//     tree.insertNode(30);
//     tree.insertNode(40);
//     tree.insertNode(50);
//     tree.insertNode(25);

//     cout << "Inorder traversal: ";
//     tree.inorderTraversal();

//     cout << "Preorder traversal: ";
//     tree.preorderTraversal();

//     cout << "Postorder traversal: ";
//     tree.postorderTraversal();

//     cout << "Height of the tree: ";
//     tree.height();

//     cout << "Balancing factors: " << endl;
//     tree.balancingFactor();

//     cout << "Diameter of the tree: ";
//     tree.diameter();

//     cout << "Max value in the tree: ";
//     tree.maxValue();

//     cout << "Min value in the tree: ";
//     tree.minValue();

//     int key = 30;
//     cout << "Successor of " << key << ": ";
//     tree.successor(key);

//     cout << "Predecessor of " << key << ": ";
//     tree.predecessor(key);

//     key = 40;
//     cout << "Deleting node " << key << " from the tree." << endl;
//     tree.deleteNode(key);

//     cout << "Inorder traversal after deletion: ";
//     tree.inorderTraversal();

//     return 0;
// }



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

// some more cautious code
/*
#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>

using namespace std;

template <class T>
struct Node {
    T data;
    struct Node<T>* leftChild;
    struct Node<T>* rightChild;
    int height;
};

template <class T>
class Tree {
protected:
    struct Node<T>* root;
public:
    Tree();
    virtual void insertNode(T) = 0;
    virtual bool deleteNode(T) = 0;
    virtual bool isEmpty() = 0;
    ~Tree() {
        delete this->root;
    }
};

template <class T>
Tree<T>::Tree() {
    this->root = nullptr;
}

template <class T>
class AVLTree : public Tree<T> {
protected:
    int height(struct Node<T>* n);
    int getBalanceFactor(struct Node<T>* n);
    struct Node<T>* rightRotate(struct Node<T>* y);
    struct Node<T>* leftRotate(struct Node<T>* x);
    struct Node<T>* insert(struct Node<T>* node, T key);
    struct Node<T>* deleteNodeHelper(struct Node<T>* root, T key);
    struct Node<T>* minValueNode(struct Node<T>* node);
    struct Node<T>* maxValueNode(struct Node<T>* node);
    struct Node<T>* successorNode(struct Node<T>* node);
    struct Node<T>* predecessorNode(struct Node<T>* node);
    void inorder(struct Node<T>* node);
    void preorder(struct Node<T>* node);
    void postorder(struct Node<T>* node);
    int heightHelper(struct Node<T>* node);
    int diameterHelper(struct Node<T>* node, int& height);
    void calculateBalanceFactor(struct Node<T>* node);

public:
    AVLTree();
    void insertNode(T key);
    bool deleteNode(T key);
    bool search(T value);
    bool isEmpty();
    void balancingFactor();
    void singleRotation();
    void doubleRotation();
    void diameter();
    void maxValue();
    void minValue();
    void successor(T key);
    void predecessor(T key);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void height();
    ~AVLTree() {
        
    }
};

template <class T>
AVLTree<T>::AVLTree() : Tree<T>() {}

template <class T>
int AVLTree<T>::height(struct Node<T>* n) {
    return n == nullptr ? 0 : n->height;
}

template <class T>
int AVLTree<T>::getBalanceFactor(struct Node<T>* n) {
    return n == nullptr ? 0 : height(n->leftChild) - height(n->rightChild);
}

template <class T>
struct Node<T>* AVLTree<T>::rightRotate(struct Node<T>* y) {
    struct Node<T>* x = y->leftChild;
    struct Node<T>* T2 = x->rightChild;

    x->rightChild = y;
    y->leftChild = T2;

    y->height = fmax(height(y->leftChild), height(y->rightChild)) + 1;
    x->height = fmax(height(x->leftChild), height(x->rightChild)) + 1;

    return x;
}

template <class T>
struct Node<T>* AVLTree<T>::leftRotate(struct Node<T>* x) {
    struct Node<T>* y = x->rightChild;
    struct Node<T>* T2 = y->leftChild;

    y->leftChild = x;
    x->rightChild = T2;

    x->height = fmax(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = fmax(height(y->leftChild), height(y->rightChild)) + 1;

    return y;
}

template <class T>
struct Node<T>* AVLTree<T>::insert(struct Node<T>* node, T key) {
    if (node == nullptr) {
        struct Node<T>* newNode = new Node<T>();
        newNode->data = key;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->data)
        node->leftChild = insert(node->leftChild, key);
    else if (key > node->data)
        node->rightChild = insert(node->rightChild, key);
    else
        return node;

    node->height = 1 + fmax(height(node->leftChild), height(node->rightChild));

    int balance = getBalanceFactor(node);

    if (balance > 1 && key < node->leftChild->data)
        return rightRotate(node);

    if (balance < -1 && key > node->rightChild->data)
        return leftRotate(node);

    if (balance > 1 && key > node->leftChild->data) {
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->rightChild->data) {
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node;
}

template <class T>
struct Node<T>* AVLTree<T>::minValueNode(struct Node<T>* node) {
    struct Node<T>* current = node;

    while (current->leftChild != nullptr)
        current = current->leftChild;

    return current;
}

template <class T>
struct Node<T>* AVLTree<T>::maxValueNode(struct Node<T>* node) {
    struct Node<T>* current = node;

    while (current->rightChild != nullptr)
        current = current->rightChild;

    return current;
}

template <class T>
struct Node<T>* AVLTree<T>::successorNode(struct Node<T>* node) {
    if (node == nullptr || node->rightChild == nullptr)
        return nullptr;

    struct Node<T>* current = node->rightChild;
    while (current->leftChild != nullptr)
        current = current->leftChild;

    return current;
}

template <class T>
struct Node<T>* AVLTree<T>::predecessorNode(struct Node<T>* node) {
    if (node == nullptr || node->leftChild == nullptr)
        return nullptr;

    struct Node<T>* current = node->leftChild;
    while (current->rightChild != nullptr)
        current = current->rightChild;

    return current;
}

template <class T>
struct Node<T>* AVLTree<T>::deleteNodeHelper(struct Node<T>* root, T key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->leftChild = deleteNodeHelper(root->leftChild, key);
    else if (key > root->data)
        root->rightChild = deleteNodeHelper(root->rightChild, key);
    else {
        if ((root->leftChild == nullptr) || (root->rightChild == nullptr)) {
            struct Node<T>* temp = root->leftChild ? root->leftChild : root->rightChild;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            struct Node<T>* temp = minValueNode(root->rightChild);

            root->data = temp->data;

            root->rightChild = deleteNodeHelper(root->rightChild, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + fmax(height(root->leftChild), height(root->rightChild));

    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->leftChild) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalanceFactor(root->leftChild) < 0) {
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->rightChild) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalanceFactor(root->rightChild) > 0) {
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }

    return root;
}

template <class T>
void AVLTree<T>::insertNode(T key) {
    this->root = insert(this->root, key);
}

template <class T>
bool AVLTree<T>::deleteNode(T key) {
    this->root = deleteNodeHelper(this->root, key);
    return (this->root != nullptr);
}

template <class T>
bool AVLTree<T>::search(T value) {
    if (isEmpty()) {
        return false;
    }

    struct Node<T>* temp = this->root;
    while (temp != nullptr) {
        if (value == temp->data) {
            return true;
        } else if (value < temp->data) {
            temp = temp->leftChild;
        } else {
            temp = temp->rightChild;
        }
    }
    return false;
}

template <class T>
bool AVLTree<T>::isEmpty() {
    return this->root == nullptr;
}

template <class T>
void AVLTree<T>::calculateBalanceFactor(struct Node<T>* node) {
    if (node != nullptr) {
        calculateBalanceFactor(node->leftChild);
        cout << "Node: " << node->data << ", Balance Factor: " << getBalanceFactor(node) << endl;
        calculateBalanceFactor(node->rightChild);
    }
}

template <class T>
void AVLTree<T>::balancingFactor() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        calculateBalanceFactor(this->root);
    }
}

template <class T>
void AVLTree<T>::singleRotation() {
    cout << "Single Rotation can be either left or right rotation, depending on the tree's balance state." << endl;
    // This method is already implemented as leftRotate and rightRotate
}

template <class T>
void AVLTree<T>::doubleRotation() {
    cout << "Double Rotation can be either left-right or right-left rotation, depending on the tree's balance state." << endl;
    // This method is already handled in the insert and delete functions through the existing rotations
}

template <class T>
void AVLTree<T>::diameter() {
    int height = 0;
    cout << "Diameter of the tree: " << diameterHelper(this->root, height) << endl;
}

template <class T>
int AVLTree<T>::diameterHelper(struct Node<T>* node, int& height) {
    if (node == nullptr) {
        height = 0;
        return 0;
    }

    int leftHeight = 0, rightHeight = 0;
    int leftDiameter = diameterHelper(node->leftChild, leftHeight);
    int rightDiameter = diameterHelper(node->rightChild, rightHeight);

    height = fmax(leftHeight, rightHeight) + 1;

    return fmax(leftHeight + rightHeight + 1, fmax(leftDiameter, rightDiameter));
}

template <class T>
void AVLTree<T>::maxValue() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        struct Node<T>* maxNode = maxValueNode(this->root);
        cout << "Maximum value: " << maxNode->data << endl;
    }
}

template <class T>
void AVLTree<T>::minValue() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        struct Node<T>* minNode = minValueNode(this->root);
        cout << "Minimum value: " << minNode->data << endl;
    }
}

template <class T>
void AVLTree<T>::successor(T key) {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
        return;
    }

    struct Node<T>* current = this->root;
    while (current != nullptr) {
        if (key < current->data) {
            current = current->leftChild;
        } else if (key > current->data) {
            current = current->rightChild;
        } else {
            break;
        }
    }

    if (current == nullptr) {
        cout << "Key not found in the tree." << endl;
        return;
    }

    struct Node<T>* succ = successorNode(current);
    if (succ != nullptr) {
        cout << "Successor of " << key << " is: " << succ->data << endl;
    } else {
        cout << "No successor found for " << key << endl;
    }
}

template <class T>
void AVLTree<T>::predecessor(T key) {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
        return;
    }

    struct Node<T>* current = this->root;
    while (current != nullptr) {
        if (key < current->data) {
            current = current->leftChild;
        } else if (key > current->data) {
            current = current->rightChild;
        } else {
            break;
        }
    }

    if (current == nullptr) {
        cout << "Key not found in the tree." << endl;
        return;
    }

    struct Node<T>* pred = predecessorNode(current);
    if (pred != nullptr) {
        cout << "Predecessor of " << key << " is: " << pred->data << endl;
    } else {
        cout << "No predecessor found for " << key << endl;
    }
}

template <class T>
void AVLTree<T>::inorder(struct Node<T>* node) {
    if (node != nullptr) {
        inorder(node->leftChild);
        cout << node->data << " ";
        inorder(node->rightChild);
    }
}

template <class T>
void AVLTree<T>::preorder(struct Node<T>* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorder(node->leftChild);
        preorder(node->rightChild);
    }
}

template <class T>
void AVLTree<T>::postorder(struct Node<T>* node) {
    if (node != nullptr) {
        postorder(node->leftChild);
        postorder(node->rightChild);
        cout << node->data << " ";
    }
}

template <class T>
void AVLTree<T>::inorderTraversal() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        inorder(this->root);
        cout << endl;
    }
}

template <class T>
void AVLTree<T>::preorderTraversal() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        preorder(this->root);
        cout << endl;
    }
}

template <class T>
void AVLTree<T>::postorderTraversal() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        postorder(this->root);
        cout << endl;
    }
}

template <class T>
void AVLTree<T>::height() {
    if (isEmpty()) {
        cout << "Tree is empty." << endl;
    } else {
        cout << "Height of the tree: " << heightHelper(this->root) << endl;
    }
}

template <class T>
int AVLTree<T>::heightHelper(struct Node<T>* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return fmax(heightHelper(node->leftChild), heightHelper(node->rightChild)) + 1;
    }
}

int main() {
    AVLTree<int> tree;

    // Inserting nodes
    tree.insertNode(10);
    tree.insertNode(20);
    tree.insertNode(30);
    tree.insertNode(40);
    tree.insertNode(50);
    tree.insertNode(25);

    cout << "Inorder traversal: ";
    tree.inorderTraversal();

    cout << "Preorder traversal: ";
    tree.preorderTraversal();

    cout << "Postorder traversal: ";
    tree.postorderTraversal();

    cout << "Height of the tree: ";
    tree.height();

    cout << "Balancing factors: " << endl;
    tree.balancingFactor();

    cout << "Diameter of the tree: ";
    tree.diameter();

    cout << "Max value in the tree: ";
    tree.maxValue();

    cout << "Min value in the tree: ";
    tree.minValue();

    int key = 30;
    cout << "Successor of " << key << ": ";
    tree.successor(key);

    cout << "Predecessor of " << key << ": ";
    tree.predecessor(key);

    key = 40;
    cout << "Deleting node " << key << " from the tree." << endl;
    tree.deleteNode(key);

    cout << "Inorder traversal after deletion: ";
    tree.inorderTraversal();

    return 0;
}

*/