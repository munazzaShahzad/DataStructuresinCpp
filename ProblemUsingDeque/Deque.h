#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Deque
{
	int capacity;
	int noOfElements;
	int front;
	int rear;
	T* data;
	void reSize(int);
public:
	Deque();
	~Deque();
	bool isEmpty();
	bool isFull();
	void insertAtTail(T);
	void insertAtHead(T);
	T deleteAtTail();
	T deleteAtHead();
	int getNoOfElements();
	int getCapacity();
};