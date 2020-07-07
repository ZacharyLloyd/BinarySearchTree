/*
   BST:  binary search tree, with Preorder traversal - root, left, right
 */
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

/* input data stream:  50 80 90 30 60 40 10 85 45

		   50
		 /    \
	   30      80
	  /  \     /  \
	10   40   60   90
		   \      /
		   45    85
*/

int main() {
	BSTree myBST = BSTree();
	BSTree myBST2 = BSTree();

	// Insert into BST using non-recursive functioin
	myBST.root = myBST.insertNode(myBST.root, 50);
	myBST.root = myBST.insertNode(myBST.root, 80);
	myBST.root = myBST.insertNode(myBST.root, 90);
	myBST.root = myBST.insertNode(myBST.root, 30);
	myBST.root = myBST.insertNode(myBST.root, 60);
	myBST.root = myBST.insertNode(myBST.root, 40);
	myBST.root = myBST.insertNode(myBST.root, 10);
	myBST.root = myBST.insertNode(myBST.root, 85);
	myBST.root = myBST.insertNode(myBST.root, 45);

	// Display BST using preorder traversal
	myBST.preorder(myBST.root);
	cout << endl;

	// Insert into BST using recursive functioin
	myBST2.root = myBST2.insertNode2(myBST2.root, 50);
	myBST2.root = myBST2.insertNode2(myBST2.root, 80);
	myBST2.root = myBST2.insertNode2(myBST2.root, 90);
	myBST2.root = myBST2.insertNode2(myBST2.root, 30);
	myBST2.root = myBST2.insertNode2(myBST2.root, 60);
	myBST2.root = myBST2.insertNode2(myBST2.root, 40);
	myBST2.root = myBST2.insertNode2(myBST2.root, 10);
	myBST2.root = myBST2.insertNode2(myBST2.root, 85);
	myBST2.root = myBST2.insertNode2(myBST2.root, 45);

	// Display BST using preorder traversal
	myBST.preorder(myBST2.root);
	cout << endl;
	return 0;
}

