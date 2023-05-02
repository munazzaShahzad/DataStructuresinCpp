#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LSLLusingArray
{
	Node<T> arr[100];
	int ULhead;
	int SLhead;
	int getNewNode();
	void returnNode(int i);
public:
	LSLLusingArray();
	void insertAtHead(T val);
	void insertAtTail(T val);
	void remove(T val);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T key);
	void removeBefore(T key);
	void printAll() const;
};

