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

	if (!parrent->left)
		return;
	TreapNode * tmp = parrent;
	TreapNode * new_root_oldChild = nullptr;
	if (parrent->left)
		 new_root_oldChild = parrent->left->right;

	parrent = parrent->left; // deteto stava roditel

	parrent->right = tmp; //roditelq stava dqsno dete
	if (parrent->right)
		parrent->right->left = new_root_oldChild; // pazim izgubenoto dete :)
}


void Treap::rotateWithRigthChild(TreapNode *& parrent)
{	
	if (!parrent->right)
		return;
	TreapNode * tmp = parrent; 
	
	TreapNode * left_child_child = nullptr;
	if (parrent->right)
		left_child_child = parrent->right->left;
	parrent = parrent->right; // deteto stava roditel

	parrent->left = tmp; //roditelq stava dqsno dete
	if (parrent->left)
		parrent->left->right = left_child_child; // lqvoto dete na noviq root stava  dqsno dete na stariq root
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
	
		if (node->left && node->right)
		{
			if (node->left->priority < node->right->priority)
				rotateWithLeftChild(node);
			else
				rotateWithRigthChild(node);
		}
		else if (node->left)
		{
			rotateWithLeftChild(node);
		}
		else if (node->right)
		{
			rotateWithRigthChild(node);
		}
		else
		{
			delete node;
			node = nullptr;
			//std::cout << "mmmmaaammmmkaaammmmu" << std::endl;
		}

		if (node != nullptr)
			removeHelper(node, key);
		else
		{
			//delete node->left;
			//node->left = nullptr;
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
		if (node->right->priority < node->priority)
			rotateWithRigthChild(node);
	}
}


void Treap::insert(int key)
{
	insertIntoSubtree(root, key);
}
