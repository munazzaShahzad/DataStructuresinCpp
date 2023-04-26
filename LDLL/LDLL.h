#pragma once
#include "DNode.h"
#include <iostream>

using namespace std;

template <typename T>
class LDLL
{
	DNode<T>* head;
public:
	LDLL();
	~LDLL();
	void insertAtHead(T);
	void insertAtTail(T);
	void insertAfter(T, T);
	void insertBefore(T, T);
	void remove(T);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T);
	void removeBefore(T);
	void display();
};

