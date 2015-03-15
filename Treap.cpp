#include "Treap.h"
#include <stack>

Treap::Treap()
{
	root = nullptr;
}


Treap::~Treap()
{
	clear(root);
}


void Treap::clear(TreapNode * root)
{
	if (root)
	{
		clear(root->left);
		clear(root->right);
		delete root;
	}
}


void Treap::rotateWithLeftChild(TreapNode *& parrent)
{
	std::swap(parrent->key, parrent->left->key);
	std::swap(parrent->priority, parrent->left->priority);
	
	TreapNode * tmp = parrent;
	parrent = parrent->left;
	
	parrent->right = tmp; //roditelq stava dqsno dete
	
	tmp->left = tmp->left->right; // roditelq vzema dqsnoto ete na lqvoto si dete
}


void Treap::rotateWithRigthChild(TreapNode *& parrent)
{
	std::swap(parrent->key, parrent->right->key);
	std::swap(parrent->priority, parrent->right->priority);
	
	TreapNode * tmp = parrent; 
	parrent = parrent->right;

	parrent->left = tmp; //roditelq stava dqsno dete

	tmp->right = tmp->right->left;

}

void Treap::removeHelper(TreapNode *& node, int key)
{
	if (node == nullptr)
		return;

	if (node->key < key)
		removeHelper(node->right, key);
	else if (node->key > key)
		removeHelper(node->left, key);
	else
	{//match found
		// node priority !!! need to change
		/// if (!node->left && !node->right) 
		// if(onlu one child :))

		if (node->left->priority < node->priority)
			rotateWithLeftChild(node);
		else
			rotateWithRigthChild(node);
		
		if (node != nullptr)
			removeHelper(node, key);
		else
		{
			delete node->left;
			node->left = nullptr;
		}
	}
}


void Treap::remove(int key)
{
	removeHelper(root, key);
}


bool findKey(TreapNode * node, int key)
{
	if (node == nullptr)
		return false;
	
	if (node->key == key)
		return true;
	else if (node->key > key)
	{
		findKey(node->left, key);
	}
	else
	{
		findKey(node->right, key);
	}
	
}


bool Treap::containsKey(int key) const
{
	if (root->key == key)
		return true;
	return findKey(root, key);
}


void Treap::insertIntoSubtree(TreapNode *& node, int & key)
{
	if (node == nullptr)
		node = new TreapNode(key);
	else if (node->key > key)
	{
		insertIntoSubtree(node->left, key);
		if (node->left->priority < node->priority)
			rotateWithLeftChild(node);
	}
	else 
	{
		insertIntoSubtree(node->right, key);
		if (node->left->priority < node->priority)
			rotateWithRigthChild(node);
	}
}


void Treap::insert(int key)
{
	insertIntoSubtree(root, key);
}
