#pragma once
#include<iostream>//for debug
#include<vector>



struct BSTNode
{
	int data;
	BSTNode * left;
	BSTNode * right;
	BSTNode * parrent;
	int level;


	BSTNode(int d, BSTNode * parrent, int level)
	{
		this->level = level ; //za print
		std::cout << "prost konstruktor" << d << std::endl;
		left = nullptr;
		right = nullptr;
		this->parrent = parrent;
		data = d;
	}


	BSTNode(int d, BSTNode * left, BSTNode * right,BSTNode * parrent, int level)
	{
		this->level = level;
		std::cout << "slojen konstruktor" << d << std::endl;
		this->left = left;
		this->right = right;
		this->parrent = parrent;
		data = d;
	}


	~BSTNode()
	{
		std::cout << "destruction of node" << data <<std::endl;
	}
};


class BSTreeInt
{
private:
	unsigned int _size;
	BSTNode * root;
	void clear(BSTNode * a);//ok
	BSTNode * findNode(int data, BSTNode * startNode);//ok nz dali raboti :)
	
	void addNodeRecursive(int data, BSTNode * currNode, BSTNode * par);//ok
	void printRecursive(BSTNode * node);//ok
	void recursiveDeleteNode(BSTNode * current, int data);
<<<<<<< HEAD
=======
	void arrangeRotationParrent(BSTNode * pivot, BSTNode * parrent, bool left);
	void decreaseLevelDown(BSTNode * node);
	void increaseLevelDown(BSTNode * node);
>>>>>>> stack + queue + bst added.
public:
	vector<BSTNode*> q;
	void deleteNode(int data);
	void bst(BSTNode * startNode);
	BSTreeInt();//ok
	~BSTreeInt();//ok
	void addNode(int data);//ok
	int removeNode();
	bool rotateLeft(int data);
	bool rotateRight(int data);
	void printAllNodes();//ok
	void bst1();
<<<<<<< HEAD
	//TODO
	void rotateLeft();
	void rotateRight();
};

=======
	BSTNode * findNode(int data);
	void rotateLeft(BSTNode * pivot);
	void rotateRight(BSTNode * pivot);
};


BSTNode * BSTreeInt::findNode(int data)
{
	return findNode(data, root);
}


void BSTreeInt::rotateLeft(BSTNode * pivot)
{
	if (pivot->parrent->right != pivot)
		return;
	BSTNode * parrent = pivot->parrent;
	BSTNode * pivotLeftChild = pivot->left;
	pivot->left = parrent;
	parrent->right = pivotLeftChild;
	arrangeRotationParrent(pivot,parrent);	
}


void BSTreeInt::rotateRight(BSTNode * pivot)
{
	if (pivot->parrent->left != pivot)
		return;
	BSTNode * parrent = pivot->parrent;
	BSTNode * pivotRightChild = pivot->right;
	pivot->right = parrent;//1
	parrent->left = pivotRightChild;//2
	BSTNode * parrentFather = parrent->parrent;
	arrangeRotationParrent(pivot, parrent);
}


void BSTreeInt::arrangeRotationParrent(BSTNode * pivot, BSTNode * parrent, bool left)
{
	BSTNode * parrentFather = parrent->parrent;

	if (parrent->parrent == nullptr)
	{
		root = pivot;
		parrent->parrent = pivot; //root case
		pivot->parrent = nullptr;
	}
	else
	{
		if (parrentFather->left == parrent)
			parrentFather->left = pivot;
		else
			parrentFather->right = pivot;

		parrent->parrent = pivot;
		pivot->parrent = parrentFather;
	}
	pivot->level--;
	if (left == true)// edno ot poddyrvetata trqbva da si ostava na sushtata dulbochina
	{
		increaseLevelDown(pivot->left->left);
		decreaseLevelDown(pivot->right);
	}
	else
	{
		increaseLevelDown(pivot->left);// trqbva da se testva
		decreaseLevelDown(pivot->right->right);
	}
}


void BSTreeInt::increaseLevelDown(BSTNode * node)
{
	if (node == nullptr)
		return;
	node->level++;
	increaseLevelDown(node->left);
	increaseLevelDown(node->right);

}

void BSTreeInt::decreaseLevelDown(BSTNode * node)
{
	if (node == nullptr)
		return;
	node->level--;
	decreaseLevelDown(node->left);
	decreaseLevelDown(node->right);

}

>>>>>>> stack + queue + bst added.
BSTNode * findMin(BSTNode * node)//find min element :)
{
	while (node->left)
		node = node->left;
	return node;
}

void BSTreeInt::recursiveDeleteNode(BSTNode * current, int data)// not tested
{
	if (current == nullptr)
		return;
	if (current->data = data)
	{
		if (current->left && current->right)//ima 2 deca
		{
			BSTNode * minmax = findMin(current->right);
			current->data = minmax->data;
			BSTNode * parDeleted = minmax->parrent;
			if (parDeleted->left == minmax)
				parDeleted->left = nullptr;
			else
				parDeleted->right = nullptr;
			delete minmax;
		}
		else
		{// ima edno ili nula deca
			BSTNode * parrent = findMin(current->parrent);
			if (current->left)
			{
				if (parrent->left == current)
					parrent->left = current->left;
				if (parrent->right == current)
					parrent->right = current->right;
				
			}
			if (current->right)
			{
				if (parrent->left == current)
					parrent->left = current->right;
				if (parrent->right == current)
					parrent->right = current->right;
			}
			delete current;
		}
		--_size;
	}
	else if (current->data > data)
	{
		recursiveDeleteNode(current->left, data);
	}
	else
	{
		recursiveDeleteNode(current->right, data);
	}
}


void BSTreeInt::deleteNode(int data)
{
	recursiveDeleteNode(root, data);
}


void BSTreeInt::printRecursive(BSTNode * node)
{
	if (node)
	{
		printRecursive(node->left);
		std::cout << node->data <<" "<< node->level << endl;
		printRecursive(node->right);
	}
}


void BSTreeInt::bst1()
{
	bst(root);
}


void BSTreeInt::bst(BSTNode * node)
{
	if (node == nullptr)
		return;

	q.push_back(node);
	cout << node->data << endl;
	if (node->left)
		bst(node->left);
	if (node->right)
			bst(node->right);
	if (q.empty())
		cout << endl;
}


void printGraphic(BSTNode* root)
{
	if (root)
	{
		cout << root->data << endl;
		if (root->left)
			cout << '/';
		if (root-> right)
			std::cout << '\\' ;
		std::cout << endl;
	}
}


void BSTreeInt::printAllNodes()
{
	printRecursive(root);
}


BSTNode * BSTreeInt::findNode(int data, BSTNode * startNode)
{
	if (startNode->data == data)
		return startNode;
	else
	{
		if (startNode->data > data)
<<<<<<< HEAD
			findNode(data, startNode->left);
		else
			findNode(data, startNode->right);
	}
	return nullptr;
=======
			return findNode(data, startNode->left);
		else
			return findNode(data, startNode->right);
	}
>>>>>>> stack + queue + bst added.
}


BSTreeInt::BSTreeInt()
{
	root = nullptr;
	_size = 0;
}


void BSTreeInt::clear(BSTNode* a)
{
	if (a != nullptr)
	{
		if (a->left != nullptr)
			clear(a->left);
		if (a->right != nullptr)
			clear(a->right);
		delete a;
	}
}


BSTreeInt::~BSTreeInt()
{
	clear(root);
}


void BSTreeInt::addNodeRecursive(int data, BSTNode * currNode, BSTNode * parrent)
{
	if (parrent == nullptr)
		return;
	
	if (currNode == nullptr)
	{
		if (parrent->data > data)
			parrent->left = new BSTNode(data, parrent, parrent->level + 1);
		else
			parrent->right = new BSTNode(data, parrent, parrent->level + 1);
	}
	else
	{
		if (currNode->data > data)
			addNodeRecursive(data, currNode->left, currNode);
		else
			addNodeRecursive(data, currNode->right, currNode);
	}
}
 

void BSTreeInt::addNode(int data)
{
	if (root == nullptr)
	{
		std::cout << "root added" << data << std::endl;
		this->root = new BSTNode(data,nullptr,0);
		++_size;
		return;
	}
	else
	{
		if (root->data == data)//same data
			return;
		if (root->data > data)
			addNodeRecursive(data, root->left, root);
		else
			addNodeRecursive(data, root->right, root);
	}
}


vector<BSTNode *> getLevel(int level, vector<BSTNode*> opashka);


void printLevels(vector<BSTNode *> & a)
{
	vector<BSTNode *> tmp;
	int lvl = 0;
	while (1)
	{
		tmp = getLevel(lvl, a);
		
		if (tmp.empty())
			break;

		for (auto * elem : tmp)
		{
			cout << elem->data<<' ';
		}
		
		cout << "level: " <<lvl << endl;
		for (auto * elem : tmp)
		{
			if (elem->left)
				cout << "/";
			else
				cout << "()";
			if (elem->right)
				cout << "\\";
			else
				cout << "()";
			cout << ' ';
		}
		cout << endl;
		++lvl;
	}
}


vector<BSTNode *> getLevel(int level, vector<BSTNode*> opashka)
{
	vector<BSTNode *> tmp;
	for (auto * elem : opashka)
		if (elem->level == level)
			tmp.push_back(elem);
	return tmp;		
}

