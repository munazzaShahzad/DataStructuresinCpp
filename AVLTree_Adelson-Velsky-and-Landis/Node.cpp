#include "Node.h"

template <typename T>
Node<T>::Node()
{
	next = nullptr;
	info = 0;
}

template <typename T>
Node<T>::Node(T val)
{
	info = val;
	next = nullptr;
}