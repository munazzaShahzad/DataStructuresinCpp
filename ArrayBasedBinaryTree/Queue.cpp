#include "Queue.h"

template <typename T>
void Queue<T>::reSize(int newCap)
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
	this->~Queue();
	noOfElements = noe;
	capacity = newCap;
	front = 0;
	rear = noe;
	data = temp;
}

template <typename T>
Queue<T>::Queue()
{
	data = nullptr;
	capacity = 0;
	noOfElements = 0;
	front = 0;
	rear = 0;
}

template <typename T>
Queue<T>::~Queue()
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
Queue<T>::Queue(Queue<T>& obj)
{
	capacity = obj.capacity;
	data = new T[capacity];
	noOfElements = obj.noOfElements;
	int k = front;
	for (int i = 0; i < noOfElements; i++)
	{
		data[i] = obj.data[k];
		k++;
		k = k % capacity;
	}
	front = 0;
	rear = noOfElements;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>& rhs)
{
	if (this == &rhs)
		return *this;
	this->~Queue();
	if (!rhs.data)
		return *this;
	capacity = rhs.capacity;
	data = new T[capacity];
	noOfElements = rhs.noOfElements;
	int k = front;
	for (int i = 0; i < noOfElements; i++)
	{
		data[i] = rhs.data[k];
		k++;
		k = k % capacity;
	}
	front = 0;
	rear = noOfElements;
	return *this;
}

template <typename T>
bool Queue<T>::isEmpty()
{
	if (noOfElements == 0)
		return true;
	return false;
}

template <typename T>
bool Queue<T>::isFull()
{
	if (noOfElements == capacity)
		return true;
	return false;
}

template <typename T>
void Queue<T>::enQueue(T val)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	data[rear++] = val;
	rear = rear % capacity;
	noOfElements++;
}

template <typename T>
T Queue<T>::deQueue()
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
T Queue<T>::getElementAtFront()
{
	return data[front];
}

template <typename T>
int Queue<T>::getNoOfElements()
{
	return noOfElements;
}

template <typename T>
int Queue<T>::getCapacity()
{
	return capacity;
}
