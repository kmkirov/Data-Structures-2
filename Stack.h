#pragma once
#include "Deck.h"
class stack
{
private:
	Deck<int> info;
public:
	unsigned int size()
	{
		return info.getSize;
	}


	bool empty()
	{
		this->size() == 0;
	}


	void push( int data)
	{
		info.addNodeToFront(data);
	}


	void pop()
	{
		info.popFront();
	}


	void front()
	{
		info.getFront();
	}
};