#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
	int capacity;
	int noOfElements;
	int front;
	int rear;
	T* data;
	void reSize(int);
public:
	Queue();
	~Queue();
	Queue(Queue<T>& obj);
	Queue<T>& operator=(Queue<T>& rhs);
	bool isEmpty();
	bool isFull();
	void enQueue(T);
	T deQueue();
	T getElementAtFront();
	int getNoOfElements();
	int getCapacity();
};

