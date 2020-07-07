#ifndef BinarySearchTreeFunc_H
#define BinarySearchTreeFunc_H
#include<iostream>
#include "BinarySearchTree.h"
using namespace std;

// create a new node
template <class T>
Node<T>* BSTree<T>::getNode(T val) {
	Node<T>* newNode;
	newNode = new Node<T>();
	newNode->key = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// insert a new node into BST - non recursive function
template <class T>
Node<T>* BSTree<T>::insertNode(Node<T>* root, T val) {
	if (root == NULL)  // BST was empty
		return getNode(val);  // create the first node

	Node<T>* tmpNode = root;
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
template <class T>
Node<T>* BSTree<T>::insertNode2(Node<T>* root, T val) {
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
template<class T>
void BSTree<T>::preorder(Node<T>* root) {
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
//Find the max value
template<class T>
Node<T>* BSTree<T>::findMax(Node<T>* root) 
{
	//While the right pointer is not null cycle through the tree
	while (root->right != nullptr) 
	{
		//Keep moving right till there is not a pointer to the right
		root = root->right;
	}
	//Return the max value
	return root;
}
//Find the min value
template<class T>
Node<T>* BSTree<T>::findMin(Node<T>* root)
{
	//While the left pointer is not null cycle through the tree
	while (root->left != nullptr)
	{
		//Keep moving left till there is not a pointer to the left
		root = root->left;
	}
	//Return the min value
	return root;
}
//Delte node function
template<class T>
Node<T>* BSTree<T>::deleteNode(Node<T>* root, T key)
{
	//Pointer to store parent node of current node
	Node<T>* parent = nullptr;
	//Start with root node
	Node<T>* currentNode = root;
	//Serach key in BST and set its parent pointer
	searchKey(currentNode, key, parent);
	//Return if key is not found in the tree
	if (currentNode == nullptr)
		return NULL;
	//case 1: node has no child
	if (currentNode->left == nullptr && currentNode->right == nullptr)
	{
		/*if node to be deleted is not a root node, then set its
		parent left/right child to null*/
		if (currentNode != root)
		{
			if (parent->left == currentNode)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		//if tree has only root node, delete it and set root to null
		else
			root = nullptr;
		//deallocate the memory
		free(currentNode); // or delete currentNode

	}
	//case 2: node has one child
	else if (currentNode->left && currentNode->right)
	{
		//find its in-order successor node
		Node<T>* successor = findMin(currentNode->right);
		//Store successor value
		T value = successor->key;
		/*Recursively delete the successor. Note that the successor
		will have at-most one child(right child)*/
		deleteNode(root, successor->key);
		//Copy the value of successor to current node
		currentNode->key = value;
	}
	//case 3: node with 2 children
	else
	{
		//find child node
		Node<T>* child = (currentNode->left) ? currentNode->left : currentNode->right;
		/*if node to be deleted is not a root node, then set
		its parent to our child*/
		if (currentNode != root)
		{
			if (currentNode == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}
		//if node to be deleted is root node, then set the root to child
		else
			root = child;
		//deallocate the memory
		free(currentNode);
	}
}
//Search key function
template<class T>
void BSTree<T>::searchKey(Node<T>*& current, T key, Node<T>*& parent)
{
	//traverse the tree and search for the key
	while (current != nullptr && current->key != key) {
		//update parent node as current node
		parent = current;

		//if given key is less than the current node, go to left subtree
		//else go to right subtree
		if (key < current->key) {
			current = current->left;
		}
		else
			current = current->right;
	}
}
#endif  //BinarySearchTreeFunc_H