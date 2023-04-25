#include "Deck.h"

template <typename T>
void Deck<T>::reSize(int newCap)
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
	this->~Deck();
	noOfElements = noe;
	capacity = newCap;
	front = 0;
	rear = noe;
	data = temp;
}

template <typename T>
Deck<T>::Deck()
{
	data = nullptr;
	capacity = 0;
	noOfElements = 0;
	front = 0;
	rear = 0;
}

template <typename T>
Deck<T>::~Deck()
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
bool Deck<T>::isEmpty()
{
	return noOfElements == 0;
}

template <typename T>
bool Deck<T>::isFull()
{
	return noOfElements == capacity;
}

template <typename T>
void Deck<T>::insertAtTail(T val)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	data[rear++] = val;
	rear = rear % capacity;
	noOfElements++;
}

template <typename T>
void Deck<T>::insertAtHead(T val)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	front = (front + capacity - 1) % capacity;
	data[front] = val;
	noOfElements++;
}

template <typename T>
T Deck<T>::deleteAtTail()
{
	if (isEmpty())
		exit(0);
	rear = (rear + capacity - 1) % capacity;
	T val = data[rear];
	noOfElements--;
	if (noOfElements == capacity / 4)
		reSize(capacity / 2);
	return val;
}

template <typename T>
T Deck<T>::deleteAtHead()
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
int Deck<T>::getNoOfElements()
{
	return noOfElements;
}

template <typename T>
int Deck<T>::getCapacity()
{
	return capacity;
}