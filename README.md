# Data Structures And Algorithms Project: Self Balancing Tree (AVL/Red Black Tree)

*This Project is to demonstrate the behaviour of a self balancing tree data structure by using either Red Black Tree Approach or AVL Tree Approach*

***Project Structure:** *

This project contains a header file *Tree.h* that contains the structure of Node required for tree and the abstract class of tree data structure that is used to extend the actual self balancing tree class.

The concrete class of self balancing tree contains the following functions:

**Insertion:**

Inserting a new node into the AVL tree while maintaining the AVL property, i.e., ensuring that the balance factor of every node is either -1, 0, or 1.

**Deletion:**

Removing a node from the AVL tree while maintaining balance. After deletion, the tree must still satisfy the AVL property.

**Search:**

Searching for a specific key or value in the AVL tree. This operation utilizes the binary search property of the tree to efficiently find the desired node.

<h3>Traversals:</h2>

**Inorder Traversal:**

Visit the nodes of the tree in sorted order.

**Preorder Traversal:**

Visit the current node before its children.

**Postorder Traversal:**

Visit the children of the current node before the node itself.

**Height Calculation:**

Calculating the height of the AVL tree, which is the maximum number of edges in any path from the root node to a leaf node. This operation is crucial for determining the balance factor of each node.

**Balancing Factor Calculation:**

Calculating the balance factor of each node in the AVL tree. The balance factor is defined as the height of the right subtree minus the height of the left subtree. It helps identify which nodes violate the AVL property.

<h3>Rotation Operations:</h3>

**Single Rotation (Left or Right):**

Perform a rotation to restore balance in a subtree that has become unbalanced due to an insertion or deletion.

**Double Rotation (Left-Right or Right-Left):**

Perform a combination of two single rotations to restore balance in a subtree.

 

**Diameter Calculation:**

Finding the diameter of the AVL tree, which is the length of the longest path between any two nodes in the tree. This operation provides insights into the overall structure of the tree.

**Minimum and Maximum Finding:**

Finding the node with the minimum or maximum key value in the AVL tree. These operations are efficient due to the binary search tree property.

**Successor and Predecessor Finding:**

Finding the successor (smallest key greater than the given key) or predecessor (largest key smaller than the given key) of a node in the AVL tree.

---



<h3>Main Function for driving ADT Code</h3>

The main function is a menu driven  code that allows the user to test all the edge cases of  this ADT. An object of AVLTree class is made at initial and then the control is transfered to a while that will show user with the driver code and exit procedure
