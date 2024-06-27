#include "AVLTree.cpp"

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
            system("pause");
        }
        else if (ch == 2)
        {
            cout << "Enter a value for deletion: ";
            int value;
            cin >> value;
            obj.deleteNode(value);
            system("pause");
        }
        else if (ch == 3)
        {
            cout << "Enter a value for searching: ";
            int value;
            cin >> value;
            obj.search(value);
            system("pause");
        }
        else if (ch == 4)
        {
            obj.inorderTraversal();
            system("pause");
        }
        else if (ch == 5)
        {
            obj.preorderTraversal();
            system("pause");
        }
        else if (ch == 6)
        {
            obj.postorderTraversal();
            system("pause");
        }
        else if (ch == 7)
        {
            obj.height();
            system("pause");
        }
        else if (ch == 8)
        {
            obj.balancingFactor();
            system("pause");
        }
        else if (ch == 9)
        {
            obj.singleRotation();
            system("pause");
        }
        else if (ch == 10)
        {
            obj.doubleRotation();
            system("pause");
        }
        else if (ch == 11)
        {
            obj.diameter();
            system("pause");
        }
        else if (ch == 12)
        {
            obj.minValue();
            system("pause");
        }
        else if (ch == 13)
        {
            obj.maxValue();
            system("pause");
        }
        else if (ch == 14)
        {
            obj.inorderTraversal();
            cout << "Enter a value within this range to check it's successor";
            int value;
            cin >> value;
            obj.successor(value);
            system("pause");
        }
        else if (ch == 15)
        {
            obj.inorderTraversal();
            cout << "Enter a value within this range to check it's predecessor";
            int value;
            cin >> value;
            obj.successor(value);
            system("pause");
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