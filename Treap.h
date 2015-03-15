#include<random>
#include<iostream>
class TreapNode
{
public:
	TreapNode(int k)
	{
		std::cout << "TreapNode created with data: " << key << std::endl;
		key = k;
		priority = (float)rand();// RAND_MAX;
		left = 0;
		right = 0;
	}
	~TreapNode()
	{
		std::cout << "TreapNode deleted with data: " << key << std::endl;
	}
	int key;	// key provided by user
	float priority;	// node's generated priority
	TreapNode* left;	// pointer for the left subtree
	TreapNode* right;	// pointer for the right subtree
};

class Treap
{

public:
	Treap();
	~Treap();

	/**
	* Inserts a node in the treap with the provided @key
	*
	* @param key: key to be inserted
	*/
	void insert(int key);

	/**
	* Removes the node from the treap with the provided @key
	*
	* @param key: key to be removed
	*/
	void remove(int key);

	/**
	* Checks whether a given @key is already in the treap
	*
	* @param key: key to be searched for
	* @return true, if the key is in the treap, and false, otherwise
	*/
	bool containsKey(int key) const;

private:
	TreapNode * root;
	void removeHelper(TreapNode *& node, int key);
	void insertIntoSubtree(TreapNode *& node, int & key);
	void rotateWithLeftChild(TreapNode *& parrent);
	void rotateWithRigthChild(TreapNode *& parrent);
	void clear(TreapNode * root);

	Treap& operator=(const Treap&); // Do not implement me!
	Treap(const Treap&); // Do not implement me!
};