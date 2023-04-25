#pragma once
#include "DNode.h"
#include <iostream>
using namespace std;

template <typename T>
class CDLL
{
	DNode<T>* head;
public: 
	CDLL();
	void printALL();
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertBefore(T key, T val);
	void insertAfter(T key, T val);
	void remove(T key);
	void removeAtHead();
	void removeAtTail();
	void removeBefore(T key);
	void removeAfter(T key);
	~CDLL();
};

