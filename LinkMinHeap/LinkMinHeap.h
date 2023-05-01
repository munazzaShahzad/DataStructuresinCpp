#pragma once
#include "BTNode.h"
#include "StackLSLL.h"
#include <iostream>

using namespace std;

template <typename T>
class LinkMinHeap
{
	int nodesCount;
	BTNode<T>* root;

	void fillPath(int num, StackLSLL<BTNode<T>*>& path);
	void VLR(BTNode<T>* p);

public:

	LinkMinHeap();
	T getMin();
	void insert(T info);
	void removeMin();
	void display();
	~LinkMinHeap();

};

