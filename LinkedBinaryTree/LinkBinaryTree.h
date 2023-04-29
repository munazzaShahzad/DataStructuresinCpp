#pragma once
#include "BTNode.h"
#include "Queue.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkBinaryTree
{
	BTNode<T>* root;

	BTNode<T>* search(BTNode<T>*, T key);
	BTNode<T>* searchParent(BTNode<T>*, T key);
	void remove(BTNode<T>*);
	void displayAncestors(BTNode<T>*);
	void displayDescendants(BTNode<T>*);
	int getHeight(BTNode<T>*);
	void VLR(BTNode<T>*);
	void LRV(BTNode<T>*);
	void LVR(BTNode<T>*);
	void parenthesizedView(BTNode<T>*);
	void explorerView(BTNode<T>*);
	int findLevel(BTNode<T>*);
	void displayLevel(BTNode<T>*, int levelNo);

public:

	LinkBinaryTree();
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
	~LinkBinaryTree();

};

