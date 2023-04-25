#pragma once
#include "AVLNode.h"
#include "StackLSLL.h"
#include <iostream>

using namespace std;

template <typename T>
class AVL
{
	AVLNode<T>* root;

	//void updateHeight(AVLNode<T>* p);
	void LLrotation(AVLNode<T>* pp, AVLNode<T>* p);
	void LRrotation(AVLNode<T>* pp, AVLNode<T>* p);
	void RLrotation(AVLNode<T>* pp, AVLNode<T>* p);
	void RRrotation(AVLNode<T>* pp, AVLNode<T>* p);
	void display(AVLNode<T>* p);
	
public:

	AVL();
	void insert(T node);
	void remove(T node);
	bool search(T node);
	void display();
	~AVL();

};

