/*
   BST:  binary search tree, with Preorder traversal - root, left, right
 */
#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTreeFunc.h"
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
	/*BSTree myBST = BSTree();*/
	BSTree<double> myBST = BSTree<double>();

	//NOT USED FOR ASSIGNMENT
	//// Insert into BST using non-recursive functioin
	//myBST.root = myBST.insertNode(myBST.root, 50);
	//myBST.root = myBST.insertNode(myBST.root, 80);
	//myBST.root = myBST.insertNode(myBST.root, 90);
	//myBST.root = myBST.insertNode(myBST.root, 30);
	//myBST.root = myBST.insertNode(myBST.root, 60);
	//myBST.root = myBST.insertNode(myBST.root, 40);
	//myBST.root = myBST.insertNode(myBST.root, 10);
	//myBST.root = myBST.insertNode(myBST.root, 85);
	//myBST.root = myBST.insertNode(myBST.root, 45);

	//// Display BST using preorder traversal
	//myBST.preorder(myBST.root);
	//cout << endl;
	//END NOT USED FOR ASSIGNMENT

	// Insert into BST using recursive functioin
	myBST.root = myBST.insertNode2(myBST.root, 50);
	myBST.root = myBST.insertNode2(myBST.root, 80);
	myBST.root = myBST.insertNode2(myBST.root, 90);
	myBST.root = myBST.insertNode2(myBST.root, 30);
	myBST.root = myBST.insertNode2(myBST.root, 60);
	myBST.root = myBST.insertNode2(myBST.root, 40);
	myBST.root = myBST.insertNode2(myBST.root, 10);
	myBST.root = myBST.insertNode2(myBST.root, 85);
	myBST.root = myBST.insertNode2(myBST.root, 45);

	// Display BST using preorder traversal
	myBST.preorder(myBST.root);
	//Finding the max value
	Node<double>* myNodeMax = myBST.findMax(myBST.root);
	cout << "\nThe max is = " << myNodeMax->key << endl;
	//Finding the min value
	Node<double>* myNodeMin = myBST.findMin(myBST.root);
	cout << "The min is = " << myNodeMin->key << endl;
	system("pause");

	//Delete 85
	myBST.deleteNode(myBST.root, 85);
	// Display BST using preorder traversal
	myBST.preorder(myBST.root);
	//Finding the max value
	Node<double>* myNodeMax2 = myBST.findMax(myBST.root);
	cout << "\nThe max is = " << myNodeMax2->key << endl;
	//Finding the min value
	Node<double>* myNodeMin2 = myBST.findMin(myBST.root);
	cout << "The min is = " << myNodeMin2->key << endl;
	system("pause");

	//Delete 90
	myBST.deleteNode(myBST.root, 90);
	// Display BST using preorder traversal
	myBST.preorder(myBST.root);
	//Finding the max value
	Node<double>* myNodeMax3 = myBST.findMax(myBST.root);
	cout << "\nThe max is = " << myNodeMax3->key << endl;
	//Finding the min value
	Node<double>* myNodeMin3 = myBST.findMin(myBST.root);
	cout << "The min is = " << myNodeMin3->key << endl;
	system("pause");

	//Delete 10
	myBST.deleteNode(myBST.root, 10);
	// Display BST using preorder traversal
	myBST.preorder(myBST.root);
	//Finding the max value
	Node<double>* myNodeMax4 = myBST.findMax(myBST.root);
	cout << "\nThe max is = " << myNodeMax4->key << endl;
	//Finding the min value
	Node<double>* myNodeMin4 = myBST.findMin(myBST.root);
	cout << "The min is = " << myNodeMin4->key << endl;
	system("pause");

	//Quit program
	return 0;
}

