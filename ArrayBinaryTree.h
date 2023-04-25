#pragma once
#include "Queue.h"
#include <iostream>
using namespace std;

template <typename T>
class ArrayBinaryTree
{

	int maxHeight;
	int arraySize;
	T* data;
	bool* nodeStatus;

	int search(int i, T key);
	void remove(int i);
	void displayAncestors(int i);
	void displayDescendants(int i);
	int getHeight(int i);
	void VLR(int i);
	void LRV(int i);
	void LVR(int i);
	void parenthesizedView(int i);
	void explorerView(int i);
	int findLevel(int i);

public:

	ArrayBinaryTree(int h);
	void setRoot(T v);
	T getRoot();
	void setLeftChild(T parent, T child);
	void setRightChild(T parent, T child);
	T getParent(T node);
	void remove(T node);
	void displayAncestors(T node);
	void displayDescendants(T node);
	int heightOfTree();
	void preOrder();
	void postOrder();
	void inOrder();
	void levelOrder();
	void displayLevel(int levelNo);
	int findLevelOfNode(T node);
	void displayParenthesizedView();
	void displayExplorerView();
	~ArrayBinaryTree();

};

