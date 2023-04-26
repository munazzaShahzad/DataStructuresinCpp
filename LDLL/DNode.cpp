#include "DNode.h"

template <typename T>
DNode<T>::DNode()
{
	next = prev = nullptr;
}

template <typename T>
DNode<T>::DNode(T val)
{
	info = val;
	next = prev = nullptr;
}