#include "BST.h"

template <typename T>
BST<T>::BST()
{
	root = nullptr;
}

template <typename T>
void BST<T>::display(BTNode<T>* p)
{
	if (p == nullptr)
		return;
	cout << p->info << " ";
	if (p->left)
		display(p->left);
	if (p->right)
		display(p->right);
}

template <typename T>
void BST<T>::display()
{
	display(root);
	cout << "\n";
}

template <typename T>
void BST<T>::insert(T node)
{
	if (!root)
		root = new BTNode<T>(node);
	else
	{
		BTNode<T>* p = root;
		BTNode<T>* prev = root;
		while (p!=nullptr)
		{
			prev = p;
			if (node < p->info)
				p = p->left;
			else
				p = p->right;
		}
		if (node < prev->info)
			prev->left = new BTNode<T>(node);
		else
			prev->right = new BTNode<T>(node);
	}
}

template <typename T>
void BST<T>::remove(T node)
{
	if (!root)
		return;
	BTNode<T>* p = root;
	BTNode<T>* parent = root;
	while (p != nullptr && p->info != node)
	{
		parent = p;
		if (node < p->info)
			p = p->left;
		else
			p = p->right;
	}
	if (!p)
		return;
	if (p->left == nullptr && p->right == nullptr)
	{
		if (p == root)
		{
			root = nullptr;
			return;
		}
		if (parent->left == p)
			parent->left = nullptr;
		else
			parent->right = nullptr;
		delete p;
	}
	else if ((p->left && p->right == nullptr) || (p->right && p->left == nullptr))
	{
		if (p == root)
		{
			if (p->left)
				root = p->left;
			else
				root = p->right;
		}
		else if (parent->left == p)
		{
			if (p->left)
				parent->left = p->left;
			else
				parent->left = p->right;
		}
		else
		{
			if (p->left)
				parent->right = p->left;
			else
				parent->right = p->right;
		}
		delete p;
	}
	else
	{
		parent = p->right;
		BTNode<T>* x = p->right;
		while (x->left != nullptr)
		{
			parent = x;
			x = x->left;
		}
		p->info = x->info;
		if (parent == x)
			p->right = x->right;
		else
			parent->left = x->right;
		delete x;
	}
}

template <typename T>
bool BST<T>::search(T node)
{
	BTNode<T>* p = root;
	while (p != nullptr && p->info != node)
	{
		if (node < p->info)
			p = p->left;
		else
			p = p->right;
	}
	if (p)
		return true;
	return false;
}

template <typename T>
BST<T>::~BST()
{
	while (root)
		remove(root->info);
}