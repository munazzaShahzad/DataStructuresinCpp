#include "LinkBinaryTree.h"

template <typename T>
BTNode<T>* LinkBinaryTree<T>::search(BTNode<T>* p, T key)
{
	BTNode<T>* temp = nullptr;
	if (p->info == key)
		temp = p;
	if (temp == nullptr && p->left)
		temp = search(p->left, key);
	if (temp == nullptr && p->right)
		temp = search(p->right, key);
	return temp;
}

template <typename T>
BTNode<T>* LinkBinaryTree<T>::searchParent(BTNode<T>* p, T key)
{
	BTNode<T>* temp = nullptr;
	if (p->left && p->left->info == key)
		temp = p;
	if (temp==nullptr && p->right && p->right->info == key)
		temp = p;
	if (temp == nullptr && p->left)
		temp = searchParent(p->left, key);
	if (temp == nullptr && p->right)
		temp = searchParent(p->right, key);
	return temp;
}

template <typename T>
void LinkBinaryTree<T>::remove(BTNode<T>* p)
{
	if (p->left)
		remove(p->left);
	if (p->right)
		remove(p->right);
	delete p;
}

template <typename T>
void LinkBinaryTree<T>::displayAncestors(BTNode<T>* p)
{
	BTNode<T>* x = searchParent(root, p->info);
	if (x)
	{
		cout << x->info;
		displayAncestors(x);
	}
}

template <typename T>
void LinkBinaryTree<T>::displayDescendants(BTNode<T>* p)
{
	if (p->left)
	{
		cout << p->left->info;
		displayDescendants(p->left);
	}
	if (p->right)
	{
		cout << p->right->info;
		displayDescendants(p->right);
	}
}

template <typename T>
int LinkBinaryTree<T>::getHeight(BTNode<T>* p)
{
	int l = 0, r = 0;
	if (p->left)
		l = getHeight(p->left);
	if (p->right)
		r = getHeight(p->right);
	return 1 + max(l, r);
}

template <typename T>
void LinkBinaryTree<T>::VLR(BTNode<T>* p)
{
	cout << p->info;
	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR(p->right);
}

template <typename T>
void LinkBinaryTree<T>::LRV(BTNode<T>* p)
{
	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR(p->right);
	cout << p->info;
}

template <typename T>
void LinkBinaryTree<T>::LVR(BTNode<T>* p)
{
	if (p->left)
		VLR(p->left);
	cout << p->info;
	if (p->right)
		VLR(p->right);
}

template <typename T>
void LinkBinaryTree<T>::parenthesizedView(BTNode<T>* p)
{
	cout << p->info;
	if (p->left || p->right)
		cout << "(";
	if (p->left)
		parenthesizedView(p->left);
	if (p->left || p->right)
		cout << ",";
	if (p->right)
		parenthesizedView(p->right);
	if (p->left || p->right)
		cout << ")";
}

template <typename T>
void LinkBinaryTree<T>::explorerView(BTNode<T>* p)
{
	int l = findLevel(p);
	for (int i = 0; i < l; i++)
		cout << "\t";
	cout << p->info << "\n";
	if (p->left)
		explorerView(p->left);
	if (p->right)
		explorerView(p->right);
}

template <typename T>
int LinkBinaryTree<T>::findLevel(BTNode<T>* p)
{
	BTNode<T>* x = searchParent(root, p->info);
	if (x)
		return 1 + findLevel(x);
	else
		return 0;
}

template <typename T>
void LinkBinaryTree<T>::displayLevel(BTNode<T>* p, int levelNo)
{
	if (findLevel(p) == levelNo)
		cout << p->info;
	if (p->left)
		displayLevel(p->left, levelNo);
	if (p->right)
		displayLevel(p->right, levelNo);
}




template <typename T>
LinkBinaryTree<T>::LinkBinaryTree()
{
	root = nullptr;
}

template <typename T>
void LinkBinaryTree<T>::setRoot(T v)
{
	if (!root)
		root = new BTNode<T>(v);
	else
		root->info = v;
}

template <typename T>
T LinkBinaryTree<T>::getRoot()
{
	if (!root)
		exit(0);
	return root->info;
}

template <typename T>
void LinkBinaryTree<T>::setLeftChild(T parent, T child)
{
	BTNode<T>* p = search(root, parent);
	if (p == nullptr)
		return;
	if (p->left == nullptr)
	{
		p->left = new BTNode<T>(child);
	}
	else
		p->left->info = child;
}

template <typename T>
void LinkBinaryTree<T>::setRightChild(T parent, T child)
{
	BTNode<T>* p = search(root, parent);
	if (p == nullptr)
		return;
	if (p->right == nullptr)
	{
		p->right = new BTNode<T>(child);
	}
	else
		p->right->info = child;
}

template <typename T>
T LinkBinaryTree<T>::getParent(T node)
{
	BTNode<T>* p = searchParent(root, node);
	return p->info;
}

template <typename T>
void LinkBinaryTree<T>::remove(T node)
{
	BTNode<T>* p = searchParent(root, node);
	if (p == nullptr)
		return;
	if (p->left->info == node)
	{
		remove(p->left);
		p->left = nullptr;
	}
	else if (p->right->info == node)
	{
		remove(p->right);
		p->right = nullptr;
	}
}

template <typename T>
void LinkBinaryTree<T>::displayAncestors(T node)
{
	BTNode<T>* p = search(root, node);
	displayAncestors(p);
	cout << "\n";
}

template <typename T>
void LinkBinaryTree<T>::displayDescendants(T node)
{
	BTNode<T>* p = search(root, node);
	displayDescendants(p);
	cout << "\n";
}

template <typename T>
int LinkBinaryTree<T>::heightOfTree()
{
	if (!root)
		return 0;
	return getHeight(root);
}

template <typename T>
void LinkBinaryTree<T>::preOrder()
{
	VLR(root);
	cout << "\n";
}

template <typename T>
void LinkBinaryTree<T>::postOrder()
{
	LRV(root);
	cout << "\n";
}

template <typename T>
void LinkBinaryTree<T>::inOrder()
{
	LVR(root);
	cout << "\n";
}

template <typename T>
void LinkBinaryTree<T>::levelOrder()
{
	Queue<BTNode<T>*> nodes;
	nodes.enQueue(root);
	do
	{
		BTNode<T>* p = nodes.deQueue();
		if (p->left)
			nodes.enQueue(p->left);
		if (p->right)
			nodes.enQueue(p->right);
		cout << p->info;
	} while (!nodes.isEmpty());
	cout << "\n";
}

template <typename T>
void LinkBinaryTree<T>::displayLevel(int levelNo)
{
	displayLevel(root, levelNo);
	cout << "\n";
}

template <typename T>
int LinkBinaryTree<T>::findLevelOfNode(T node)
{
	BTNode<T>* p = search(root, node);
	return findLevel(p);
}

template <typename T>
void LinkBinaryTree<T>::displayParenthesizedView()
{
	parenthesizedView(root);
	cout << "\n";
}

template <typename T>
void LinkBinaryTree<T>::displayExplorerView()
{
	explorerView(root);
}

template <typename T>
LinkBinaryTree<T>::~LinkBinaryTree()
{
	remove(root);
	root = nullptr;
}