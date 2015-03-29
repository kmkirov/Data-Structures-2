#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "avl_tree_interface.h"
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string getName()
{
	return "Dimitar Ivanov Georgiev";
}

string getMoodleName()
{
	return "Ayreon";
}


string getFacultyNumber()
{
	return "11111";
}

template <class T>
class AVLTree : public  AVLTreeInterface<T>
{
   // int size;
    //Node<T>* root;
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

template <class T>
AVLTree<T>::AVLTree()
{
}

template <class T>
AVLTree<T>::~AVLTree()
{
}

template <class T>
int AVLTree<T>::getSize() const
{
	return this->size;
}


template <class T>
void AVLTree<T>::insertNode(T value)
{
}

template <class T>
Node<T>* AVLTree<T>::findNode(T value)
{
	return NULL;
}

template <class T>
void AVLTree<T>::deleteNode(T value)
{
}

#endif // AVL_TREE_HPP
