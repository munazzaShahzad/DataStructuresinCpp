#pragma once

#include "BTNode.h"
#include <iostream>

using namespace std;

template <typename T>
class BST
{

	BTNode<T>* root;
	void display(BTNode<T>* p);
public:

	BST();
	void insert(T node);
	void remove(T node);
	bool search(T node);
	void display();
	~BST();

};

