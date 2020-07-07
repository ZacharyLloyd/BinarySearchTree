#ifndef BinarySearchTree_H
#define BinarySearchTree_H

#include<iostream>

// data structure for each node (leaf) in the tree
template <class T>
class Node {
public:
	T key;
	Node* left;
	Node* right;
};

// BST starts with root node
template<class T>
class BSTree {
public:
	Node<T>* root;
	BSTree() {
		root = NULL;
	}
	Node<T>* insertNode(Node<T>* root, T val);  // non recursive function
	Node<T>* insertNode2(Node<T>* root, T val);  // recursive function 
	void preorder(Node<T>* root);  // display using preorder traversal
	Node<T>* findMin(Node<T>* root);  // find min function 
	Node<T>*findMax(Node<T>* root); //find max function
	Node<T>* deleteNode(Node<T>* root, T val);  // delete function
	void searchKey(Node<T>*& current, T key, Node<T>*& parent); //Search function used for deleting


private:
	Node<T>* getNode(T val);  //create a new node to insert new data
};

#endif  //BinarySearchTree_H