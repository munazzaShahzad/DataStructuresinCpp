#pragma once

template <typename T>
struct Node
{
	T info;
	Node<T>* next;
	Node();
	Node(T val);
};

