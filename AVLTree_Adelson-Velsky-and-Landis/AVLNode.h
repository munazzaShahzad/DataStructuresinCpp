#pragma once

template <typename T>
struct AVLNode
{

	T info;
	AVLNode<T>* left, * right;
	int height;

	AVLNode()
	{
		info = 0;
		left = right = nullptr;
		height = 1;
	}

	AVLNode(T val)
	{
		info = val;
		left = right = nullptr;
		height = 1;
	}

};

