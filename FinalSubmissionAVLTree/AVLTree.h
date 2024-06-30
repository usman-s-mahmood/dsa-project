#include "Tree.cpp"

template <class T>
class AVLTree: public Tree<T>
{
    protected:
        T max_value_pro(struct Node<T> *root); // done
        T min_value_pro(struct Node<T> *root); // done
        void tree_size(struct Node<T> *root, int &size); // done
        void convert_to_array(struct Node<T> *root, int &itr, int *arr); // REM: use it in destructor for efficient memory handling // done
        void SEARCH(struct Node<T> *root, T value, bool &check); // done
        void PARENT(struct Node<T> *root, T value, T &parent_value); // done
        void LEFTCHILD(struct Node<T> *root, T value, T &child_value); // done 
        void RIGHTCHILD(struct Node<T> *root, T value, T &child_value); // done

        void preOrderHelper(Node<T> *root);
        void postOrderHelper(Node<T> *root);

        // -- --
        int height(Node<T> *node);
        int getBalance(Node<T> *node);
        Node<T>* rightRotate(Node<T> *y);
        Node<T>* leftRotate(Node<T> *x);
        Node<T>* insertHelper(Node<T> *node, T value);
        Node<T>* deleteHelper(Node<T> *node, T value);
        Node<T>* minValueNode(Node<T> *node); // REM: Don't use loop based approach
        void inOrderHelper(Node<T> *root);
        int diameterHelper(Node<T> *root, int &height); // REM: Try to use for loop in tests file
        void balanceFactorHelper(Node<T> *root);
        // -- -- 

    public:
        AVLTree();
        void insertNode(T); // done
        bool deleteNode(T); // done
        bool search(T); // done
        int height_of_node(int); 
        bool isEmpty(); // done
        void singleRotation();
        void doubleRotation();
        // void diameter();
        T maxValue(); // done
        T minValue(); // done
        void successor(T); // REM: use array technique to find successor and predecessor of it by converting non linear D.S. to linear D.S. // done
        void predecessor(T); // done
        T right_child(T); // done
        T left_child(T); // done
        T parent_node(T);

        void inOrder();
        void preOrder();
        void postOrder();
        int diameter();
        int size_of_tree();
        void balanceFactor();
        int root_value();
        ~AVLTree();
};