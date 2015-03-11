#include<iostream>
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
		Node(NodeData d, Node<NodeData> parrent)
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
			delete leftChildTree;
			delete rightChildTree;
			delete parrentNode;
		}
	};

	Node<T> * root;

	void clear(Node<T>* a);
	Node<T> * findNode(T data);
	//forbid ugly stuff
	BSTree(const BSTree& a) = delete;
	BSTree & operator = (const BSTree & a) = delete;
	Node<T> * findNodeRecursive(T data, Node<T>*node);
	void recursiveAddNode(T data, Node<T> node, Node<T> parrent);
public:
	BSTree();
	~BSTree();
	void printBSTree();
	void printBSTreeGraphics();
	void insertNode(T data);
	T removeNode();
	bool rotateLeft(T data);
	bool rotateRight(T data);
	bool hasNodeWithData(T data);
};


template <class T>
bool BSTree<T>::hasNodeWithData(T data)
{
	return nullptr != findNode(data);
}
// ..... zashto ?????? typename po tozi nachin :)
template <class T>
typename BSTree<T>::Node<T>* BSTree<T>::findNode(T data)
{
	if (root->data == data)
		return root;
	else
		return findNodeRecursive(data, root);

	return nullptr;
}
template <class T>
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

template<class T>
BSTree<T>::BSTree()
{
	root = nullptr;
}


template<class T>
void BSTree<T>::clear(Node<T>* a)
{
	if (a != nullptr)
	{
		if (a->leftChildTree != nullptr)
			clear(a->leftChildTree);
		if (a->rightChildTree != nullptr)
			clear(a->rightChildTree);
		delete a;
	}
}


template<class T>
BSTree<T>::~BSTree()
{
	clear(root);
}


template <class T>
void BSTree<T>::insertNode(T data)
{
	if (root == nullptr)
	{
		cout << "root added" << data << endl;
		this->root = new Node<T>(data);
		return;
	}
	if (root->data > data && root->leftChildTree == nullptr)
	{
		cout << "add left child" << data << endl;
		root->leftChildTree = new Node<T>(data);
		return;
	}
	if (root->data < data && root->rightChildTree == nullptr)
	{
		cout << "add right child" << data << endl;
		root->rightChildTree = new Node<T>(data);
		return;
	}
	////	if not in the tree add a node :)
	//Node<T> * tmp = findNode(data);
	//if (tmp == nullptr)
	//	tmp = new Node<T>(data);
	
}
template <class T>
void BSTree<T>::recursiveAddNode(T data, Node<T> node, Node<T> parrent)
{
	if (node == nullptr)
		node == new Node<T>(data, parrent);
}



template<class T>
void BSTree<T>::printBSTree()
{

}


int main()
{
	BSTree<int> a;

	a.insertNode(1);
	a.insertNode(13);
	a.insertNode(132);
	a.insertNode(241);

	return 0;
}