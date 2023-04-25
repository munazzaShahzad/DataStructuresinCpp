#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
	data = nullptr;
	top = 0;
	capacity = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& obj) : Stack()
{
	if (!obj.data)
		return;
	capacity = obj.capacity;
	top = obj.top;
	data = new T[capacity];
	for (int i = 0; i < top; i++)
	{
		data[i] = obj.data[i];
	}
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& ref)
{
	if (this == &ref)
		return *this;
	this->~Stack();
	if (!ref.data)
		return *this;
	capacity = ref.capacity;
	top = ref.top;
	data = new T[capacity];
	for (int i = 0; i < top; i++)
	{
		data[i] = ref.data[i];
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	if (!data)
		return;
	delete[] data;
	data = nullptr;
	capacity = 0;
	top = 0;
}

template <typename T>
void Stack<T>::reSize(int size)
{
	T* temp = new T[size];
	for (int i = 0; i < top; i++)
		temp[i] = data[i];
	int noe = top;
	this->~Stack();
	capacity = size;
	top = noe;
	data = temp;
}

template <typename T>
void Stack<T>::push(T val)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	data[top++] = val;
}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty())
		exit(0);
	T val = data[--top];
	if (top == capacity / 4)
		reSize(capacity / 2);
	return val;
}

template <typename T>
T Stack<T>::stackTop() const
{
	if (isEmpty())
		exit(0);
	return data[top - 1];
}

template <typename T>
bool Stack<T>::isFull() const
{
	return top == capacity;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return top == 0;
}

template <typename T>
int Stack<T>::getCapacity() const
{
	return capacity;
}

template <typename T>
int Stack<T>::getNumberOfElements() const
{
	return top;
}