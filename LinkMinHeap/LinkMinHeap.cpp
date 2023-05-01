#include "LinkMinHeap.h"

template <typename T>
void LinkMinHeap<T>::fillPath(int num, StackLSLL<BTNode<T>*>& path)
{
	if (num <= 1)
		return;
	fillPath(num / 2, path);
	if (num % 2 == 0)
		path.push(path.stackTop()->left);
	else
		path.push(path.stackTop()->right);
}

template <typename T>
void LinkMinHeap<T>::VLR(BTNode<T>* p)
{
	cout << p->info << " ";
	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR(p->right);
}

template <typename T>
LinkMinHeap<T>::LinkMinHeap()
{
	root = nullptr;
	nodesCount = 0;
}

template <typename T>
T LinkMinHeap<T>::getMin()
{
	return root->info;
}

template <typename T>
void LinkMinHeap<T>::insert(T info)
{
	if (!root)
	{
		root = new BTNode<T>(info);
		nodesCount = 1;
		return;
	}
	StackLSLL<BTNode<T>*> path;
	int num = (nodesCount + 1) / 2;
	path.push(root);
	fillPath(num, path);
	BTNode<T>* cur = path.pop();
	if (!cur->left)
		cur->left = new BTNode<T>(info);
	else
		cur->right = new BTNode<T>(info);
	nodesCount++;
	if (cur->right)
	{
		if (cur->info > cur->right->info)
		{
			T temp = cur->right->info;
			cur->right->info = cur->info;
			cur->info = temp;
		}
		else
			return;
	}
	else
	{
		if (cur->info > cur->left->info)
		{
			T temp = cur->left->info;
			cur->left->info = cur->info;
			cur->info = temp;
		}
		else
			return;
	}
	while(!path.isEmpty())
	{
		cur = path.pop();
		if (cur->right->info < cur->info && cur->left->info < cur->info)
		{
			if (cur->left->info < cur->right->info)
			{
				T temp = cur->info;
				cur->info = cur->left->info;
				cur->left->info = temp;
			}
			else
			{
				T temp = cur->info;
				cur->info = cur->right->info;
				cur->right->info = temp;
			}
		}
		else if (cur->left->info < cur->info)
		{
			T temp = cur->info;
			cur->info = cur->left->info;
			cur->left->info = temp;
		}
		else if (cur->right->info < cur->info)
		{
			T temp = cur->info;
			cur->info = cur->right->info;
			cur->right->info = temp;
		}
	}
}

template <typename T>
void LinkMinHeap<T>::removeMin()
{
	if (!root)
		return;
	int num = nodesCount / 2;
	StackLSLL<int> bin;
	while (num > 1)
	{
		bin.push(num % 2);
		num /= 2;
	}
	BTNode<T>* parent;
	parent = root;
	while (!bin.isEmpty())
	{
		if (bin.pop() == 1)
			parent = parent->right;
		else
			parent = parent->left;
	}
	if (num * 2 == nodesCount)
	{
		root->info = parent->left->info;
		delete parent->left;
		parent->left = nullptr;
	}
	else
	{
		root->info = parent->right->info;
		delete parent->right;
		parent->right = nullptr;
	}
	BTNode<T>* cur = root;
	while (cur->right && (cur->left->info < cur->info || cur->right->info < cur->info))
	{
		if (cur->left->info < cur->info && cur->right->info < cur->info)
		{
			if (cur->left->info < cur->right->info)
			{
				T temp = cur->left->info;
				cur->left->info = cur->info;
				cur->info = temp;
			}
			else
			{
				T temp = cur->right->info;
				cur->right->info = cur->info;
				cur->info = temp;
			}
		}
		else if (cur->left->info < cur->info)
		{
			T temp = cur->left->info;
			cur->left->info = cur->info;
			cur->info = temp;
		}
		else
		{
			T temp = cur->right->info;
			cur->right->info = cur->info;
			cur->info = temp;
		}
	}
	if (cur->left && cur->left->info < cur->info)
	{
		T temp = cur->left->info;
		cur->left->info = cur->info;
		cur->info = temp;
	}
	nodesCount--;
}

template <typename T>
void LinkMinHeap<T>::display()
{
	VLR(root);
	cout << "\n===============\n";
}

template <typename T>
LinkMinHeap<T>::~LinkMinHeap()
{
	while (root)
		removeMin();
	nodesCount = 0;
}