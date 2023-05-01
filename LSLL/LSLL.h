#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class LSLL
{
	Node* head;
public:
	LSLL();
	LSLL(const LSLL<T> &ref);
	LSLL<T>& operator=(const LSLL<T>& ref);
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void remove(T key);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T key);
	void removeBefore(T key);
	void display();
	~LSLL();
};

