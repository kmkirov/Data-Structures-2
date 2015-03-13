#pragma once
#include "Deck.h"

class q
{
private:
	Deck<int> info;

public:

	void push(int data)
	{
		info.addNodeToBack(data);
	}


	void pop()
	{
		info.popFront();
	}


	unsigned int size()
	{
		return info.getSize();
	}


	bool empty()
	{
		return this->size() == 0;
	}


	int front()
	{
		return info.getFront();
	}

};