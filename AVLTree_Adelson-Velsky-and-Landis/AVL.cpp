#include "AVL.h"

template <typename T>
void AVL<T>::display(AVLNode<T>* p)
{
	if (p == nullptr)
		return;
	cout << p->info << " ";
	if (p->left)
		display(p->left);
	if (p->right)
		display(p->right);
}

//template <typename T>
//void AVL<T>::updateHeight(AVLNode<T>* p)
//{
//	if (!(p->right && p->left))
//	{
//		p->height = 1;
//		return;
//	}
//
//	if (p->left)
//		updateHeight(p->left);
//	if (p->right)
//		updateHeight(p->right);
//
//	if (p->right && p->left)
//		p->height = ((p->left->height) > (p->right->height) ? p->left->height : p->right->height) + 1;
//	else if (p->right)
//		p->height = p->right->height + 1;
//	else
//		p->height = p->left->height + 1;
//}

template <typename T>
void AVL<T>::LLrotation(AVLNode<T>* pp, AVLNode<T>* p)		//right rotation or right shift
{
	AVLNode<T>* lp = p->left;
	AVLNode<T>* rlp = lp->right;
	lp->right = p;
	p->left = rlp;
	if (p == root)
		root = lp;
	else if (pp->left == p)
		pp->left = lp;
	else
		pp->right = lp;
	p->height = max(p->left->height, p->right->height) + 1;
	lp->height = max(lp->left->height, lp->right->height) + 1;
}

template <typename T>
void AVL<T>::LRrotation(AVLNode<T>* pp, AVLNode<T>* p)
{
	AVLNode<T>* lp = p->left;
	AVLNode<T>* rlp = lp->right;
	AVLNode<T>* lrlp = rlp->left;
	AVLNode<T>* rrlp = rlp->right;
	rlp->left = lp;
	rlp->right = p;
	lp->right = lrlp;
	p->left = rrlp;
	if (p == root)
		root = rlp;
	else if (pp->left == p)
		pp->left = rlp;
	else
		pp->right = rlp;
	lp->height = max(lp->left->height, lp->right->height) + 1;
	p->height = max(p->left->height, p->right->height) + 1;
	rlp->height = max(rlp->left->height, rlp->right->height) + 1;
}

template <typename T>
void AVL<T>::RLrotation(AVLNode<T>* pp, AVLNode<T>* p)
{
	AVLNode<T>* rp = p->right;
	AVLNode<T>* lrp = rp->left;
	AVLNode<T>* llrp = lrp->left;
	AVLNode<T>* rlrp = lrp->right;
	lrp->left = p;
	lrp->right = rp;
	p->right = llrp;
	rp->left = rlrp;
	if (p == root)
		root = lrp;
	else if (pp->left == p)
		pp->left = lrp;
	else
		pp->right = lrp;
	p->height = max(p->left->height, p->right->height) + 1;
	rp->height = max(rp->left->height, rp->right->height) + 1;
	lrp->height = max(lrp->left->height, lrp->right->height) + 1;
}

template <typename T>
void AVL<T>::RRrotation(AVLNode<T>* pp, AVLNode<T>* p)	//left shift
{
	AVLNode<T>* rp = p->right;
	AVLNode<T>* lrp = rp->left;
	rp->left = p;
	p->right = lrp;
	if (p == root)
		root = rp;
	else if (pp->left == p)
		pp->left = rp;
	else
		pp->right = rp;
	p->height = max(p->left->height, p->right->height) + 1;
	rp->height = max(rp->left->height, rp->right->height) + 1;
}

template <typename T>
AVL<T>::AVL()
{
	root = nullptr;
}

template <typename T>
void AVL<T>::insert(T node)
{
	StackLSLL<AVLNode<T>*> ancestorPath;
	if (!root)
	{
		root = new AVLNode<T>(node);
		return;
	}
	AVLNode<T>* p = root;
	AVLNode<T>* prev = root;
	while (p != nullptr)
	{
		prev = p;
		ancestorPath.push(p);
		if (node < p->info)
			p = p->left;
		else
			p = p->right;
	}
	if (node < prev->info)
		prev->left = new AVLNode<T>(node);
	else
		prev->right = new AVLNode<T>(node);
	while (!ancestorPath.isEmpty())
	{
		AVLNode<T>* cur = ancestorPath.pop();

		if (cur->right && cur->left)
			cur->height = ((cur->left->height) > (cur->right->height) ? cur->left->height : cur->right->height) + 1;
		else if (cur->right)
			cur->height = cur->right->height + 1;
		else if(cur->left)
			cur->height = cur->left->height + 1;
		else
			cur->height = 0;
		
		int balanceFactor = 0;

		if (cur->left && cur->right)
			balanceFactor = cur->left->height - cur->right->height;
		else if (cur->left)
			balanceFactor = cur->left->height;
		else if (cur->right)
			balanceFactor = 0 - cur->right->height;

		if (balanceFactor == 2)
		{
			int leftBF = 0;
			if (cur->left->left && cur->left->right)
				leftBF = cur->left->left->height - cur->left->right->height;
			else if (cur->left->left)
				leftBF = cur->left->left->height;
			else if (cur->left->right)
				leftBF = 0 - cur->left->right->height;

			if (leftBF == 1 || leftBF == 0)
			{
				if (!ancestorPath.isEmpty())
					LLrotation(ancestorPath.stackTop(), cur);
				else
					LLrotation(cur, cur);
			}
			else
			{
				if (!ancestorPath.isEmpty())
					LRrotation(ancestorPath.stackTop(), cur);
				else
					LRrotation(cur, cur);
			}
		}
		else if (balanceFactor == -2)
		{
			int rightBF = 0;
			if (cur->right->left && cur->right->right)
				rightBF = cur->right->left->height - cur->right->right->height;
			else if (cur->right->left)
				rightBF = cur->right->left->height;
			else if (cur->right->right)
				rightBF = 0 - cur->right->right->height;

			if (rightBF == -1 || rightBF == 0)
			{
				if (!ancestorPath.isEmpty())
					RRrotation(ancestorPath.stackTop(), cur);
				else
					RRrotation(cur, cur);
			}
			else
			{
				if (!ancestorPath.isEmpty())
					RLrotation(ancestorPath.stackTop(), cur);
				else
					RLrotation(cur, cur);
			}
		}
	}
}

template <typename T>
void AVL<T>::remove(T node)
{
	if (!root)
		return;
	AVLNode<T>* p = root;
	AVLNode<T>* parent = root;
	StackLSLL<AVLNode<T>*> ancestorPath;
	while (p != nullptr && p->info != node)
	{
		ancestorPath.push(p);
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
		if (parent->left == p)
			parent->left = nullptr;
		else
			parent->right = nullptr;
		if (p == root)
			root = nullptr;
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
		AVLNode<T>* x = p->right;
		ancestorPath.push(p);
		while (x->left != nullptr)
		{
			ancestorPath.push(x);
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
	while (!ancestorPath.isEmpty())
	{
		AVLNode<T>* cur = ancestorPath.pop();

		if (cur->right && cur->left)
			cur->height = ((cur->left->height) > (cur->right->height) ? cur->left->height : cur->right->height) + 1;
		else if (cur->right)
			cur->height = cur->right->height + 1;
		else if (cur->left)
			cur->height = cur->left->height + 1;
		else
			cur->height = 0;

		int balanceFactor = 0;

		if (cur->left && cur->right)
			balanceFactor = cur->left->height - cur->right->height;
		else if (cur->left)
			balanceFactor = cur->left->height;
		else if (cur->right)
			balanceFactor = 0 - cur->right->height;

		if (balanceFactor == 2)
		{
			int leftBF = 0;
			if (cur->left->left && cur->left->right)
				leftBF = cur->left->left->height - cur->left->right->height;
			else if (cur->left->left)
				leftBF = cur->left->left->height;
			else if (cur->left->right)
				leftBF = 0 - cur->left->right->height;

			if (leftBF == 1 || leftBF == 0)
			{
				if (!ancestorPath.isEmpty())
					LLrotation(ancestorPath.stackTop(), cur);
				else
					LLrotation(cur, cur);
			}
			else
			{
				if (!ancestorPath.isEmpty())
					LRrotation(ancestorPath.stackTop(), cur);
				else
					LRrotation(cur, cur);
			}
		}
		else if (balanceFactor == -2)
		{
			int rightBF = 0;
			if (cur->right->left && cur->right->right)
				rightBF = cur->right->left->height - cur->right->right->height;
			else if (cur->right->left)
				rightBF = cur->right->left->height;
			else if (cur->right->right)
				rightBF = 0 - cur->right->right->height;
			if (rightBF == -1 || rightBF == 0)
			{
				if (!ancestorPath.isEmpty())
					RRrotation(ancestorPath.stackTop(), cur);
				else
					RRrotation(cur, cur);
			}
			else
			{
				if (!ancestorPath.isEmpty())
					RLrotation(ancestorPath.stackTop(), cur);
				else
					RLrotation(cur, cur);
			}
		}
	}
}

template <typename T>
bool AVL<T>::search(T node)
{
	AVLNode<T>* p = root;
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
void AVL<T>::display()
{
	display(root);
	cout << "\n\n";
}

template <typename T>
AVL<T>::~AVL()
{
	while (root)
		remove(root->info);
}