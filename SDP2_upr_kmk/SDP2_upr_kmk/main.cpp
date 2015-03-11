#include<iostream>
using namespace std;


template<class TT>
class BST
{
private:
	template<class T>
	struct Node
	{
		T data;
		Node<T> * left;
		Node<T> * right;
		template <class T>
		Node(T d)
		{
			left = nullptr;
			right = nullptr;
			data = d;
		}
		~Node()
		{
			cout << "destruction of node";
			delete left;
			delete right;
		}
	};

	Node<TT> * root;
	void clear(Node<TT>* a);
	Node<TT> * findNode(TT data);
public:
	BST();
	~BST();
	void insertNode(TT data);
	TT removeNode();
	bool rotateLeft(TT data);
	bool rotateRight(TT data);
};
// ..... zashto ?????? typename po tozi nachin :)
template <class T>
typename BST<T> ::Node<T>* BST<T>::findNode(T data)
{
	return nullptr;
}

template<class TT>
BST<TT>::BST()
{
	root = nullptr;
}


template<class TT>
void BST<TT>::clear(Node<TT>* a)
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


template<class TT>
BST<TT>::~BST()
{
	delete root;
}


template <class TT>
void BST<TT>::insertNode(TT data)
{
	if (root == nullptr)
	{
		cout << "root added" << data << endl;
		this->root = new Node<TT>(data);
		return;
	}
	if (root->data > data && root->left == nullptr)
	{
		cout << "add left child" << data << endl;
		root->left = new Node<TT>(data);
		return;
	}
	if (root->data < data && root->right == nullptr)
	{
		cout << "add right child" << data << endl;
		root->right = new Node<TT>(data);
		return;
	}
	//	if not in the tree add a node :)
	Node<TT> * tmp = findNode(data);
	if (tmp == nullptr)
	{
		tmp = new Node<TT>(data);
	}
}




int main()
{
	BST<int> a;
	a.insertNode(1);
	return 0;
}