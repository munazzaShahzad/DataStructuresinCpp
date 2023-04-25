#pragma once
template <typename T>
struct DNode
{
	T info;
	DNode<T>* next;
	DNode<T>* prev;
public:
	DNode()
	{
		next = nullptr;
		prev = nullptr;
	}
	DNode(T val)
	{
		info = val;
		next = nullptr;
		prev = nullptr;
	}
};

