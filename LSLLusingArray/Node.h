#pragma once
template <typename T>
struct Node
{
	T info;
	int next;
public:
	Node()
	{
		info = 0;
		next = -1;
	}
	Node(T val)
	{
		info = val;
		next = -1;
	}
};