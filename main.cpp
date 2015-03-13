#include<iostream>
#include "Deck.h"

using namespace std;

template<class T>
class BSTree
{
private:
	template<class NodeData>
	struct Node
	{
		NodeData data;
		Node<NodeData> * leftChildTree;
		Node<NodeData> * rightChildTree;
		Node<NodeData> * parrentNode;
		
		template <class NodeData>
		Node(NodeData d, Node<NodeData> * parrent)
		{
			cout << "Constructor of Node" << endl;
			leftChildTree = nullptr;
			rightChildTree = nullptr;
			parrentNode = parrent;
			data = d;
		}

		~Node()
		{
			cout << "destruction of node" << endl;
			if (leftChildTree !=nullptr)
				delete leftChildTree;
			if (rightChildTree != nullptr)
				delete rightChildTree;
			//delete parrentNode; // inache loop
		}
	};

	Node<T> * root;

	void clear(Node<T>* a);//not needed need to find why ?!
	Node<T> * findNode(T data);//ready
	//forbid ugly stuff
	BSTree(const BSTree& a) = delete;//ok
	BSTree & operator = (const BSTree & a) = delete;//ok
	Node<T> * findNodeRecursive(T data, Node<T>* node);//ready
	void recursiveAddNode(T data, Node<T> *node, Node<T>* parrentNode);//ready
	void recursivePrint(Node<T> * node);//ready
	void remove(T data, Node<T> * startDeletionNode);
	Node<T> * findMinElementOfTree(Node<T> * minFromCurrentNode);
	void deleteNode(Node<T> * node);
public:
	BSTree();//ready
	~BSTree();//ready
	void printBSTree();//ready
	//void printBSTreeGraphics();
	void insertNode(T data);//ready
	//TODO::
	bool removeNode(T data);//uj ready
	bool rotateLeft(T data);
	bool rotateRight(T data);
	bool hasNodeWithData(T data);//ready
};

template <class T>
bool BSTree<T>::rotateLeft(T data)
{
	Node<T> * nodeForDel = findNode(data);// vyzela okolko koito vurtim
	return true;
}



template<class T>
void BSTree<T>::deleteNode(typename BSTree<T>::Node<T> * nodeForDel)
{
	Node<T> * parrent = nodeForDel->parrentNode;
	if (parrent->leftChildTree == nodeForDel)
		parrent->leftChildTree = nullptr;
	else
		parrent->rightChildTree = nullptr;
	delete nodeForDel;
}


template<class T>
void BSTree<T>::remove(T data, typename BSTree<T>::Node<T> * startDeletionNode)
{
	Node<T> * nodeForDel = findNode(data);
	
	
	if (nodeForDel->leftChildTree != nullptr && nodeForDel->rightChildTree != nullptr)
	{//have two children
		Node<T> * smallesRightChild = findMinElementOfTree(nodeForDel->rightChildTree);
		nodeForDel->data = smallesRightChild->data;
		deleteNode(smallesRightChild);
	}
	if (nodeForDel->leftChildTree == nullptr && nodeForDel->rightChildTree == nullptr)
	{//don't have children case
		if (nodeForDel->leftChildTree != nullptr)
		{
			if (nodeForDel->parrentNode->leftChildTree == nodeForDel)
			
				nodeForDel->parrentNode->leftChildTree = nodeForDel->leftChildTree;
			else
				nodeForDel->parrentNode->rightChildTree = nodeForDel->leftChildTree;
		}
		else
		{//right node is nullptr
			if (nodeForDel->parrentNode->leftChildTree == nodeForDel)
			
				nodeForDel->parrentNode->leftChildTree = nodeForDel->rightChildTree;
			else
				nodeForDel->parrentNode->rightChildTree = nodeForDel->rightChildTree;
		}

		deleteNode(nodeForDel);
	}
	
}


template<class T>
typename BSTree<T>::Node<T> * findMinElementOfTree(typename BSTree<T>::Node<T>* minFromCurrentNode)
{
	Node<T> * tmp = minFromCurrentNode;
	if (minFromCurrentNode == nullptr)
		return minFromCurrentNode;
	while (tmp->leftChildTree != nullptr)
		tmp = tmp->leftChildTree;
	return tmp;
}


template<class T>
bool BSTree<T>::removeNode( T data )
{
	if (hasNodeWithData(data) == true)
	{
		remove(data, root);
		return true;
	}
	else
		return false;
}


template <class T>//ready
bool BSTree<T>::hasNodeWithData(T data)
{
	return nullptr != findNode(data);
}


template <class T>//ready
typename BSTree<T>::Node<T>* BSTree<T>::findNode(T data)
{
	if (root->data == data)
		return root;
	else
		return findNodeRecursive(data, root);

	return nullptr;
}


template <class T>//ready
typename BSTree<T>::Node<T>* BSTree<T>::findNodeRecursive(T data, typename  BSTree<T>::Node<T>* node)
{
	if (node == nullptr)
		return node;
	if (node->data == data)
		return node;
	else if (node->data > data)
		return findNodeRecursive(data, node->rightChildTree);
	else
		return findNodeRecursive(data, node->leftChildTree);

	return node;
}


template<class T>//ready
BSTree<T>::BSTree()
{
	root = nullptr;
}


template<class T>//not used
void BSTree<T>::clear(Node<T>* a)
{
	//if (a == nullptr)
	//	return;
	if (a->leftChildTree != nullptr)
		clear(a->leftChildTree);
	if (a->rightChildTree !=nullptr)
		 clear(a->rightChildTree);
	if (a != nullptr)
		delete a;
	
}


template<class T>//ready
BSTree<T>::~BSTree()
{
	delete root;
}


template <class T>// ready
void BSTree<T>::insertNode(T data)
{
	if (root == nullptr)
	{
		cout << "root added" << data << endl;
		Node<T> * t = new Node<T>(data, root);
		this->root = t;
		return;
	}
	else 
		recursiveAddNode(data, root, root);	
}


template <class T>//ready
void BSTree<T>::recursiveAddNode(T data, typename BSTree<T>::Node<T>* node, typename BSTree<T>::Node<T>* parrentNode)
 {
	if (parrentNode == nullptr)
		return;
	if (node == nullptr)
	{
		node = new Node<T>(data, parrentNode);
		if (parrentNode->data > data)
			parrentNode->rightChildTree = node;
		else
			parrentNode->leftChildTree = node;
	}
	else
	{
		if (node->data > data)
			recursiveAddNode(data, node->rightChildTree, node);
		else
			recursiveAddNode(data, node->leftChildTree, node);
	}
}


template <class T>//ready
void BSTree<T>::recursivePrint(typename BSTree<T>::Node<T>* node)
{
	if (node == nullptr)
		return;
	cout << node->data<<endl;
	recursivePrint(node->leftChildTree);
	recursivePrint(node->rightChildTree);
}


template<class T>//ready
void BSTree<T>::printBSTree()
{
	recursivePrint(this->root);		
}

void vernoMojelo()
{
	class b{ int a; };//ot uchebnika na magda :D
}
int main1()
{
	BSTree<int> a;

	a.insertNode(1);
	a.insertNode(13);
	a.insertNode(132);
	a.insertNode(241);

	a.printBSTree();
	return 0;
}

void testDeck(Deck<int> & a)
{
	a.addNodeToBack(3);
	a.addNodeToBack(4);
	a.addNodeToFront(2);
	a.addNodeToFront(1);
	a.insertNodeIntoPos(11, -2);
	a.deleteNodePosition(4);
	a.printAll();
}
int main46()
{
	Deck<int> dek;
	testDeck(dek);
	return 0;
}
#include "BSTreeInt.h"
void BSTreeIntTest()
{
	BSTreeInt a;
	a.addNode(1);
	a.addNode(2);
	a.addNode(-10);
	a.addNode(-5);
	a.addNode(-2);
	a.addNode(10);
	a.addNode(20);
	a.printAllNodes();
<<<<<<< HEAD
	a.bst1();
	printLevels(a.q);

=======
	a.q.clear();//clean old elements
	a.bst1();
	printLevels(a.q);

	//cout<<a.findNode(-10)->data;
	a.rotateLeft(a.findNode(2));
	a.bst1();
	printLevels(a.q);
>>>>>>> stack + queue + bst added.
}
int main()
{
	BSTreeIntTest();
	return 0;
}