#ifndef BinarySearchTree_H
#define BinarySearchTree_H

#include<iostream>

// data structure for each node (leaf) in the tree
class Node {
public:
	int key;
	Node* left;
	Node* right;
};

// BST starts with root node
class BSTree {
public:
	Node* root;
	BSTree() {
		root = NULL;
	}
	Node* insertNode(Node* root, int val);  // non recursive function
	Node* insertNode2(Node* root, int val);  // recursive function 
	void preorder(Node* root);  // display using preorder traversal
	Node* findMax(Node* root);  // find max function 
	Node* findMin(Node* root);  // find min function 
	Node* deleteNode(Node* root, int val);  // delete function
	void searchKey(Node*& current, int key, Node*& parent); //Search function used for deleting


private:
	Node* getNode(int val);  //create a new node to insert new data
};

#endif  //BinarySearchTree_H