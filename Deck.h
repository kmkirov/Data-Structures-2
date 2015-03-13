#pragma once
template <class T>
struct Node
{
	Node<T> * nextNodePtr;
	Node<T> * prevNodePtr;
	T data;

public:
	Node(Node<T> * prevPtr, T data )
	{
		cout << "Node constructor and data" << data << endl;
		nextNodePtr = nullptr;
		prevNodePtr = prevPtr;
		this->data = data;
	}


	~Node()
	{
	}
};


/// deque implementation
template <class T>
class Deck
{
private:
	unsigned int _size;
	Node<T> * startNode;
	Node<T> * endNode;
	Deck(const Deck<T> & deck) = delete;
	Deck<T>& operator=(const Deck<T>& deck) = delete;
	void addDataToNode(T data);

public:
	Deck(); //ready
	virtual ~Deck(); //ready
	void addNodeToBack(T data); //ready
	void addNodeToFront(T data); //ready
	bool hasNode(T data); //ready
	bool insertNodeIntoPos(unsigned int index, T data);//ready
	void deleteNodePosition(unsigned int pos);//ready
	void popBack();
	void popFront();
	void printAll();
	unsigned int getSize();
	T getFront()
	{
		return startNode->data;
	}
	T getBack()
	{
		return endNode->data;
	}
};

template <class T>
void Deck<T>::popBack()
{
	deleteNodePosition(_size - 1);
}


template<class T>
unsigned int Deck<T>::getSize()
{
	return _size;
}


template<class T>
void Deck<T>::popFront()
{
	deleteNodePosition(0);
}

template <class T>
void Deck<T>::printAll()
{
	cout << " printing "<< endl;
	Node<T> * t = startNode;
	while (t)
	{
		cout << t->data << endl;
		t = t->nextNodePtr;
	}
}

template <class T>
Deck<T>::~Deck()
{
	//cout << "dek destr" << endl;
	//if (startNode)
	//	delete startNode;
	// da probvam samo s delete startNode :D
	while (startNode)
	{
		Node<T> * t = startNode;
		startNode = startNode->nextNodePtr;
		delete t;
		cout << " deck deleting..." << endl;
	}
}


template <class T>
Deck<T>::Deck()
{
	cout << "deck constructor" << endl;
	startNode = nullptr;
	endNode = nullptr;
	_size = 0;
}

template <class T>
bool Deck<T>::hasNode(T data)
{
	Node<T>* tmp = startNode;
	while (tmp)
	{
		if (data == tmp->data)
			return true;
		tmp = tmp->nextNodePtr;
	}
	return false;
}


template <class T>
void Deck<T>::addDataToNode(T data)
{
	startNode = new Node<T>(nullptr, data);
	endNode = startNode;
	++_size;
}


template <class T>
bool Deck<T>::insertNodeIntoPos(unsigned int index, T data)
{
	if (index < 0)
		return false;

	if (index > _size)
	{
		//add to back
		addNodeToBack(data);
		return true;
	}
	if (index == 0)
	{
		addNodeToFront(data);
		return true;
	}
	
	Node<T> * tmp = startNode;
	for (int i = 0; i < index - 1; ++i)
		tmp = tmp->nextNodePtr;
	Node<T> * newNode = new Node<T>(tmp, data);
	newNode->nextNodePtr = tmp->nextNodePtr;
	tmp->nextNodePtr->prevNodePtr = newNode;
	tmp->nextNodePtr = newNode;
	_size++;
}


template<class T>
void Deck<T>::addNodeToBack(T data)
{
	if (startNode == nullptr)
	{
		addDataToNode(data);
		return;
	}
	Node<T> * tmp = new Node<T>(nullptr,data);
	tmp->prevNodePtr = endNode;
	endNode->nextNodePtr = tmp;
	endNode = tmp;
	++_size;
}


template <class T>
void Deck<T>::addNodeToFront(T data)
{
	if (startNode == nullptr)
	{
		addDataToNode(data);
		return;
	}

	Node<T> * tmp = new Node<T>(nullptr, data);
	tmp->nextNodePtr = startNode;
	startNode->prevNodePtr = tmp;
	startNode = tmp;
	++_size;
}

template <class T>
void Deck<T>::deleteNodePosition(unsigned int pos)
{
	if (pos > _size || pos < 0)
		return;
	if (pos == 0)
	{
		Node<T> * tmp = startNode;
		startNode = startNode->nextNodePtr;
		startNode->prevNodePtr = nullptr;
		delete tmp;
		--_size;
		return;
	}
	if (pos == _size - 1)
	{
		Node<T> * tmp = endNode;
		endNode = endNode->prevNodePtr;
		delete tmp;
		endNode->nextNodePtr = nullptr;
		--_size;
		return;
	}
	Node<T> * tmp = startNode;
	for (int i = 0; i < pos - 1; ++i)
		tmp = tmp->nextNodePtr;
	Node<T> * del = tmp->nextNodePtr;
	tmp->nextNodePtr->nextNodePtr->prevNodePtr = tmp;
	tmp->nextNodePtr = tmp->nextNodePtr->nextNodePtr;
	delete del;
	--_size;
}
