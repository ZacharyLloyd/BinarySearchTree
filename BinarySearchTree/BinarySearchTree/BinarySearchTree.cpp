#include<iostream>
#include "BinarySearchTree.h"
using namespace std;

// create a new node
Node* BSTree::getNode(int val) {
	Node* newNode;
	newNode = new Node();
	newNode->key = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// insert a new node into BST - non recursive function
Node* BSTree::insertNode(Node* root, int val) {
	if (root == NULL)  // BST was empty
		return getNode(val);  // create the first node

	Node* tmpNode = root;
	while (tmpNode != NULL) {  // loop until end of tree nodes
		// process right node
		if (tmpNode->key < val) {
			if (tmpNode->right == NULL) {  // found the spot to insert
				tmpNode->right = getNode(val);
				break;
			}
			else {  // continue on the right branch
				tmpNode = tmpNode->right;
				continue;
			}
		}

		// process left node
		if (tmpNode->key > val) {
			if (tmpNode->left == NULL) {  // found the spot to insert
				tmpNode->left = getNode(val);
				break;
			}
			else {  // continue on the left branch
				tmpNode = tmpNode->left;
				continue;
			}
		}
	}

	return root;
}

// insert a new node into BST - recursive function
Node* BSTree::insertNode2(Node* root, int val) {
	// found Null node to insert new one
	if (root == NULL)
		return getNode(val);

	// traverse right node if input value is greater than key
	if (root->key < val)
		root->right = insertNode2(root->right, val);

	// traverse left node if input value is less than key
	if (root->key > val)
		root->left = insertNode2(root->left, val);

	return root;
}

// preorder traversal - root, left, right
void BSTree::preorder(Node* root) {
	// stop when Null node is reached
	if (root == NULL)
		return;

	// process root node
	cout << root->key << " ";

	// process left node
	preorder(root->left);

	// process right node
	preorder(root->right);
}

