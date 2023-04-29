#pragma once

template <typename T>
struct BTNode
{
	T info;
	BTNode<T>* left, * right;

	BTNode()
	{
		info = 0;
		left = right = nullptr;
	}

	BTNode(T val)
	{
		info = val;
		left = right = nullptr;
	}

};

