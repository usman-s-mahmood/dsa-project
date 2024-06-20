#include "Tree.cpp"

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
        ~RedBlackTree()
        {
            Tree<T>::~Tree();
        }
};