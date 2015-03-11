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
	Node<T> * findNodeRecursive(T data, Node<T>* node);
	void recursiveAddNode(T data, Node<T> *node, Node<T>* parrentNode);
	void recursivePrint(Node<T>* node);
public:
	BSTree();
	virtual ~BSTree();//ready
	void printBSTree();
	//void printBSTreeGraphics();
	void insertNode(T data);//ready
	T removeNode();
	bool rotateLeft(T data);
	bool rotateRight(T data);
	bool hasNodeWithData(T data);//ready
};


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


template<class T>//ready
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


template<class T>//ready
BSTree<T>::~BSTree()
{
	clear(root);
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
void BSTree<T>::recursiveAddNode(T data,typename BSTree<T>:: Node<T>* node, typename BSTree<T>::Node<T>* parrentNode)
{
	if (parrentNode == nullptr)
		return;
	if (node == nullptr)
	{
		node = new Node<T>(data, parrentNode);
		return;
	}

	if (parrentNode->data > data)
		recursiveAddNode(data, parrentNode->rightChildTree, parrentNode);
	else
		recursiveAddNode(data, parrentNode->leftChildTree, parrentNode);
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


int main()
{
	BSTree<int> a;

	a.insertNode(1);
	a.insertNode(13);
	a.insertNode(132);
	a.insertNode(241);

	a.printBSTree();

	return 0;
}