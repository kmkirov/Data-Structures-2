#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "avl_tree_interface.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
//class Node
//{
//public:
//	Node<T> *parent;
//	Node<T> *leftChild, *rightChild;
//	int height;
//	T value;
//};
using namespace std;

string getName() 
{
	return "KMKirov";
}

string getMoodleName() 
{
	return "KMKirov";
}


string getFacultyNumber() 
{
	return "1234";
}

template <class T>
class AVLTree : public  AVLTreeInterface<T>
{
	void clean(Node<T>* root);
	void insertRecursive(Node<T>*& node, Node<T>* parent, T value);
	void leftRotate(Node<T> *&parentNode);
	void rightRotate(Node<T> *&parentNode);
	Node<T> * findRecursive(Node<T>* node, T value);
	int getChilderMaxHeight(Node<T>* node);
	void checkHeight(Node<T> *& node);
	int getHeight(Node<T>* node);
	void balance(Node<T>*& node);
	void AVLTree<T>::doubleRotate(Node<T>*& node, bool startWithLeft);
	void removeRecursive(Node<T>*& node, T value);
public:
	AVLTree();
	virtual ~AVLTree();

		/* Returns the number of nodes in the tree. 0 in case of empty tree. */
	virtual int getSize() const;

	/* Inserts the given value as node in the tree. */
	virtual void insertNode(T value);

    /* Finds a node with value equal to the given parameter. Returns NULL if no such is found. */
	virtual Node<T>* findNode(T value);

	/* Deletes a node with the given value from the tree.
	   If the value is not found in the tree no modification to the tree should be made.
	*/
	virtual void deleteNode(T value);
};


template<class T>
Node<T> * AVLTree<T>::findRecursive(Node<T>* node, T value)
{
	if (node->value == value)
		return node;
	else if (node->value > value)
		return findRecursive(node->leftChild, value);
	else
		return findRecursive(node->rightChild, value);
}


template <class T>
void AVLTree<T>::clean(Node<T>* root)
{
	if (root)
	{
		clean(root->leftChild);
		clean(root->rightChild);
		delete root;
	}
}


template <class T>
AVLTree<T>::AVLTree()
{
	this->root = nullptr;
	this->size = 0;

}


template <class T>
AVLTree<T>::~AVLTree()
{
	clean(this->root);
}


template <class T>
int AVLTree<T>::getSize() const
{
	return this->size;
}


template <class T>
void AVLTree<T>::insertNode(T value)
{
	if (this->root == nullptr)
	{
		this->root = new Node<T>();
		this->root->value = value;
		this->root->parent = nullptr;
	}
	else if (this->root->value > value)
	{
		insertRecursive(this->root->leftChild, root, value);
		//checkHeight(this->root);
	}
	else
	{
		insertRecursive(this->root->rightChild, root, value);
		//checkHeight(this->root);
	}
	balance(this->root);
	++this->size;
}


template <class T>
int AVLTree<T>::getHeight(Node<T>* node)
{
	return node == nullptr ? 0 : node->height;
}

template<class T>
void AVLTree<T>::checkHeight(Node<T> *& node)// parent node
{
	throw;
}


template <class T>
void AVLTree<T>::insertRecursive(Node<T>*& node, Node<T>* parent, T value)
 {
	if (node == nullptr)
	{
		node = new Node<T>();
		node->parent = parent;
		node->value = value;	
		
	}
	else if (node->value > value)
		insertRecursive(node->leftChild, node, value);
	else
		insertRecursive(node->rightChild, node, value);
	balance(node);
}


//template <class T>
//void AVLTree<T>::doubleRotate(Node<T>*& node, bool startWithLeft)
//{
//	if (!startWithLeft)
//	{
//		leftRotate(node->rightChild);
//		rightRotate(node);
//	}
//	else
//	{	
//		rightRotate(node->leftChild);
//		leftRotate(node);
//	}
//}


template <class T>
void AVLTree<T>::balance(Node<T>*& node)
{
	if (node == nullptr)
		return;

	if (getHeight(node->leftChild) - getHeight(node->rightChild) > 1)
	{
		if (getHeight(node->leftChild->leftChild) >= getHeight(node->leftChild->rightChild))
			rightRotate(node);
		else
		{
			leftRotate(node->leftChild);
			rightRotate(node);
		}
	}
	else if (getHeight(node->rightChild) - getHeight(node->leftChild) > 1)
	{
		if (getHeight(node->rightChild->rightChild) >= getHeight(node->rightChild->leftChild))
			leftRotate(node);
		else
		{
			rightRotate(node->rightChild);
			leftRotate(node);
		}
	}
	node->height = max(getHeight(node->rightChild), getHeight(node->leftChild)) + 1;
}

template<class T>
int AVLTree<T>::getChilderMaxHeight(Node<T>* node)
{
	return node == nullptr ? 0 : max(getHeight(node->leftChild), getHeight(node->rightChild));
}


template<class T>
void AVLTree<T>::leftRotate(Node<T> *&parentNode)// da si opravq parrent :S
{
	if (parentNode == nullptr || parentNode->rightChild == nullptr)
		return;
	Node<T>*  rightChild = parentNode->rightChild;
	// father ...
	if (rightChild->leftChild)
		rightChild->leftChild->parent = parentNode;
	rightChild->parent = parentNode->parent;
	parentNode->parent = rightChild;
	// movement
	parentNode->rightChild = rightChild->leftChild;
	rightChild->leftChild = parentNode;// moje da zacikli tuk
	parentNode = rightChild;
	// height
	parentNode->height = getChilderMaxHeight(parentNode) + 1;
	parentNode->leftChild->height = getChilderMaxHeight(parentNode->leftChild) + 1;
}


template<class T>
void AVLTree<T>::rightRotate(Node<T> *&parentNode)
{
	if (parentNode == nullptr || parentNode->leftChild == nullptr)
		return;
	Node<T> *  leftChild = parentNode->leftChild;
	// father's need to be set for unit tests
	if (leftChild->rightChild)
		leftChild->rightChild->parent = parentNode;
	leftChild->parent = parentNode->parent;
	parentNode->parent = leftChild;
	// most important.. move the pointers
	parentNode->leftChild = leftChild->rightChild;
	leftChild->rightChild = parentNode;// moje da zacikli tuk
	parentNode = leftChild;
	// setting height for moved nodes
	parentNode->height = getChilderMaxHeight(parentNode) + 1;
	parentNode->rightChild->height = getChilderMaxHeight(parentNode->rightChild) + 1;
}


template <class T>
Node<T>* AVLTree<T>::findNode(T value)
{
	return findRecursive(this->root, value);
}


template <class T>
Node<T>* findMin(Node<T>* node)
{
	if (node == nullptr)
		return node;
	Node<T> * tmp = node;
	while (tmp->leftChild)
	{
		tmp = tmp->leftChild;
	}
	return tmp;
}

template <class T>
void AVLTree<T>::removeRecursive(Node<T>*& node, T value)
{
	if (node == nullptr)
		return;
	if (node->value > value)
		removeRecursive(node->leftChild, value);
	else if (node->value < value)
		removeRecursive(node->rightChild, value);
	else if (node->leftChild && node->rightChild)
	{
		node->value = findMin(node->rightChild)->value;
		removeRecursive(node->rightChild, node->value);
	}
	else
	{
		Node<T> * oldNode = node;
		node = node->leftChild ? node->leftChild : node->rightChild;
		delete oldNode;
		--this->size;
		
	}
	balance(node);
}

template <class T>
void AVLTree<T>::deleteNode(T value)
{
	removeRecursive(this->root, value);
	balance(this->root);
}

#endif // AVL_TREE_HPP