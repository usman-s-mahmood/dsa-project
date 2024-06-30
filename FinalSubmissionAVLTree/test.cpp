#include "AVLTree.cpp"

int main() 
{
    AVLTree<int> obj;
    obj.insertNode(10);
    obj.insertNode(20);
    obj.insertNode(30);
    obj.insertNode(40);
    obj.insertNode(50);
    obj.insertNode(25);
    cout << "Inorder traversal of the constructed AVL tree is: ";
    obj.inOrder();
    obj.deleteNode(10);
    cout << "Inorder traversal after deletion of 10: ";
    obj.inOrder();
    obj.diameter();
    obj.successor(25);
    obj.height_of_node(25);
    int arr[] = {20, 25, 30, 40, 50};
    obj.balanceFactor();
    // cout << "Before deleting all the nodes of tree: " << obj.isEmpty() << endl;
    // for (int i = 0; i < 5; i++)
    //     obj.deleteNode(arr[i]);
    // cout << "After deleting all the nodes of tree: " << obj.isEmpty() << endl;
    return 0;
}
