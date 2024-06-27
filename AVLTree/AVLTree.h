#include "Tree.cpp"

template <class T>
class AVLTree: public Tree<T>
{
    protected:
        void INORDER(struct Node<T> *root);
        void PREORDER(struct Node<T> *root);
        void POSTORDER(struct Node<T> *root);
        void HEIGHT(struct Node<T> *root);
        T max_value_pro(struct Node<T> *root);
        T min_value_pro(struct Node<T> *root);
        void tree_size(struct Node<T> *root, int &size);
        void convert_to_array(struct Node<T> *root, int &itr, int *arr);
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
        T maxValue();
        T minValue();
        void successor(T); // use array technique to find successor and predecessor of it
        void predecessor(T);
        ~AVLTree()
        {
            Tree<T>::~Tree();
        }
};