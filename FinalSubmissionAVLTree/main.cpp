/*
**** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** 
|   Data Structures and Algorithms Project: Self Balancing BST using AVL Techniques     |
|   Submitted to: Ms. Ayesha Nadeem                                                     |
|   Group Members:                                                                      |
|   Ayesha Arif (L1F22BSCS0820)                                                         |
|   Fatima Asad Khan (L1F22BSCS0840)                                                    |
|   Zehab Faisal (L1F22BSCS0881)                                                        |
|   M. Usman Shahid (L1F22BSCS1057)                                                     |
**** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** 
*/

#include "AVLTree.cpp"

void printLine(string content, char border = '*', int width = 80) {
    int contentLength = content.length();
    int padding = (width - contentLength - 2) / 2;
    cout << border << string(padding, ' ') << content << string(padding, ' ');
    if ((contentLength + 2) % 2 != width % 2)
        cout << " ";
    cout << border << endl;
}


int main()
{
    AVLTree<int> obj;
    int ch = -1;
    string borderLine(80, '*');
    cout << borderLine << endl;
    printLine("Data Structures and Algorithms Project");
    printLine("Self Balancing BST using AVL Techniques");
    cout << borderLine << endl;
    printLine("Submitted to: Ms. Ayesha Nadeem");
    cout << borderLine << endl;
    printLine("Group Members:");
    printLine("Ayesha Arif (L1F22BSCS0820)");
    printLine("Fatima Asad Khan (L1F22BSCS0840)");
    printLine("Zehab Faisal (L1F22BSCS0881)");
    printLine("M. Usman Shahid (L1F22BSCS1057)");
    cout << borderLine << endl;
    while (ch != 0)
    {
        cout << "Welcome to AVL Tree Demonstration System!" << endl
            << "1. To insert a value" << endl
            << "2. To delete a value" << endl
            << "3. To search a value" << endl
            << "4. To perform Inorder Traversal" << endl
            << "5. To perform Preorder Traversal" << endl
            << "6. To perform Postorder Traversal" << endl
            << "7. To calculate height of a node" << endl
            << "8. To know the value of root" << endl
            << "9. To perform single rotation" << endl
            << "10. To perform double rotation" << endl
            << "11. To calculate diameter of tree" << endl
            << "12. To Find minimum element in tree" << endl
            << "13. To Find maximum element in tree" << endl
            << "14. To Find Successor of a node" << endl
            << "15. To Find Predecessor of a node" << endl
            << "16. To Find Parent of a node" << endl
            << "17. To Find left child of a node" << endl
            << "18. To Find right child of a node" << endl
            << "19. To calculate balancing factor of tree" << endl
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
            obj.inOrder();
            system("pause");
        }
        else if (ch == 5)
        {
            obj.preOrder();
            system("pause");
        }
        else if (ch == 6)
        {
            obj.postOrder();
            system("pause");
        }
        else if (ch == 7)
        {
            cout << "Enter the value of a node to find it's height: ";
            int value;
            cin >> value;
            obj.height_of_node(value);
            system("pause");
        }
        else if (ch == 8)
        {
            obj.root_value();
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
            obj.inOrder();
            cout << "Enter a value within this range to check it's successor";
            int value;
            cin >> value;
            obj.successor(value);
            system("pause");
        }
        else if (ch == 15)
        {
            obj.inOrder();
            cout << "Enter a value within this range to check it's predecessor";
            int value;
            cin >> value;
            obj.predecessor(value);
            system("pause");
        }
        else if (ch == 16)
        {
            obj.inOrder();
            cout << "Enter a number within this range to know the value of it's parent node: ";
            int value;
            cin >> value;
            obj.parent_node(value);
            system("pause");
        }
        else if (ch == 17)
        {
            obj.inOrder();
            cout << "Enter a number within this range to know the value of it's left child: ";
            int value;
            cin >> value;
            obj.left_child(value);
            system("pause");
        }
        else if (ch == 18)
        {
            obj.inOrder();
            cout << "Enter a number within this range to caluculate the value of it's right child: ";
            int value;
            cin >> value;
            obj.right_child(value);
            system("pause");
        }
        else if (ch == 19)
        {
            obj.balanceFactor();
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