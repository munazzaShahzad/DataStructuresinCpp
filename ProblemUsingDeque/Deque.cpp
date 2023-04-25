#include "Deque.h"

template <typename T>
void Deque<T>::reSize(int newCap)
{
	T* temp = new T[newCap];
	int noe = noOfElements;
	int k = front;
	for (int i = 0; i < noe; i++)
	{
		temp[i] = data[k];
		k++;
		k = k % capacity;
	}
	this->~Deque();
	noOfElements = noe;
	capacity = newCap;
	front = 0;
	rear = noe;
	data = temp;
}

template <typename T>
Deque<T>::Deque()
{
	data = nullptr;
	capacity = 0;
	noOfElements = 0;
	front = 0;
	rear = 0;
}

template <typename T>
Deque<T>::~Deque()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
		capacity = 0;
		noOfElements = 0;
		front = 0;
		rear = 0;
	}
}

template <typename T>
bool Deque<T>::isEmpty()
{
	if (noOfElements == 0)
		return true;
	return false;
}

template <typename T>
bool Deque<T>::isFull()
{
	if (noOfElements == capacity)
		return true;
	return false;
}

template <typename T>
void Deque<T>::insertAtTail(T val)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	data[rear++] = val;
	rear = rear % capacity;
	noOfElements++;
}

template <typename T>
void Deque<T>::insertAtHead(T val)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	front--;
	if (front == -1)
		front += capacity;
	else
		front = front % capacity;
	data[front] = val;
	noOfElements++;
}

template <typename T>
T Deque<T>::deleteAtTail()
{
	if (isEmpty())
		exit(0);
	--rear;
	if (rear == -1)
		rear += capacity;
	else
		rear = rear % capacity;
	T val = data[rear];
	noOfElements--;
	if (noOfElements == capacity / 4)
		reSize(capacity / 2);
	return val;
}

template <typename T>
T Deque<T>::deleteAtHead()
{
	if (isEmpty())
		exit(0);
	T val = data[front];
	front++;
	front = front % capacity;
	noOfElements--;
	if (noOfElements == capacity / 4)
		reSize(capacity / 2);
	return val;
}

template <typename T>
int Deque<T>::getNoOfElements()
{
	return noOfElements;
}

template <typename T>
int Deque<T>::getCapacity()
{
	return capacity;
}