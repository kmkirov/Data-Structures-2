//#include "BSTreeTemplate.h"

//
//int main1()
//{
//	BSTree<int> a;
//
//	a.insertNode(1);
//	a.insertNode(13);
//	a.insertNode(132);
//	a.insertNode(241);
//
//	a.printBSTree();
//	return 0;
//}

//void testDeck(Deck<int> & a)
//{
//	a.addNodeToBack(3);
//	a.addNodeToBack(4);
//	a.addNodeToFront(2);
//	a.addNodeToFront(1);
//	a.insertNodeIntoPos(11, -2);
//	a.deleteNodePosition(4);
//	a.printAll();
//}

//#include "BSTreeInt.h"
//void BSTreeIntTest()
//{
//	BSTreeInt a;
//	a.addNode(1);
//	a.addNode(2);
//	a.addNode(-10);
//	a.addNode(-5);
//	a.addNode(-2);
//	a.addNode(10);
//	a.addNode(20);
////	a.printAllNodes();
//	a.bst1();
//	printLevels(a.q);
//	a.q.clear();//clean old elements
//	//cout<<a.findNode(-10)->data;
//	a.rotateLeft(a.findNode(2));
//	a.q.clear();
//	a.bst1();
//	printLevels(a.q);
//
//}

#include "Treap.h"

void testTreap_right_right()
{
	Treap	 a;
	a.insert(3);
	a.insert(43);
	a.insert(53);

}


void testTreap_left_left()
{
	Treap	 a;
	a.insert(-3);
	a.insert(-43);
	a.insert(-53);
}


void testTreap_mnoogo()
{
	Treap	 a;
	for (int i = 0; i < 100000000; ++i)
		a.insert(rand());
}

void testDeleteFromTreap()
{
	Treap	 a;
	a.insert(-3);
	a.insert(-43);
	a.insert(53);
	a.insert(-4);
	a.insert(1);
	a.insert(4);
	a.insert(-1);
	a.remove(-3);
	a.remove(-1);
	a.remove(-1);
	a.remove(-43);
}


int main()
{
	testDeleteFromTreap();
	return 0;
}