#include "ArrayBinaryTree.h"

template <typename T>
ArrayBinaryTree<T>::ArrayBinaryTree(int h)
{
	maxHeight = h;
	arraySize = pow(2, h) - 1;
	data = new T[arraySize];
	nodeStatus = new bool[arraySize];
	for (int i = 0; i < arraySize; i++)
		nodeStatus[i] = false;
}

template <typename T>
int ArrayBinaryTree<T>::search(int i, T key)
{
	int status = -1;
	if (data[i] == key)
		status = i;
	if (status == -1 && (2 * i) + 1 < arraySize && nodeStatus[2 * i + 1])
		status = search(2 * i + 1, key);
	if (status == -1 && (2 * i) + 2 < arraySize && nodeStatus[2 * i + 2])
		status = search(2 * i + 2, key);
	return status;
}

template <typename T>
void ArrayBinaryTree<T>::remove(int i)
{
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
		remove(2 * i + 1);
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
		remove(2 * i + 2);
	nodeStatus[i] = false;
}

template <typename T>
void ArrayBinaryTree<T>::displayAncestors(int i)
{
	if (i <= 0)
		return;
	if (nodeStatus[(i - 1) / 2])
	{
		cout << data[(i - 1) / 2];
		displayAncestors((i - 1) / 2);
	}
}

template <typename T>
void ArrayBinaryTree<T>::displayDescendants(int i)
{
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
		cout << data[2 * i + 1];

	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
		displayDescendants(2 * i + 1);

	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
		cout << data[2 * i + 2];

	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
		displayDescendants(2 * i + 2);
}

template <typename T>
int ArrayBinaryTree<T>::findLevel(int i)
{
	if (i == 0)
		return 0;
	return 1 + findLevel((i - 1) / 2);
}

template <typename T>
int ArrayBinaryTree<T>::getHeight(int i)
{
	int l = 0, r = 0;
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
		l = getHeight(2 * i + 1);
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
		r = getHeight(2 * i + 2);
	return 1 + max(l, r);
}

template <typename T>
void ArrayBinaryTree<T>::VLR(int i)
{
	cout << data[i];
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
		VLR(2 * i + 1);
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
		VLR(2 * i + 2);
}

template <typename T>
void ArrayBinaryTree<T>::LRV(int i)
{
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
		LRV(2 * i + 1);
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
		LRV(2 * i + 2);
	cout << data[i];
}

template <typename T>
void ArrayBinaryTree<T>::LVR(int i)
{
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
		LVR(2 * i + 1);
	cout << data[i];
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
		LVR(2 * i + 2);
}

template <typename T>
void ArrayBinaryTree<T>::parenthesizedView(int i)
{
	cout << data[i];
	if ((2 * i + 1 < arraySize && nodeStatus[2 * i + 1]) || (2 * i + 2 < arraySize && nodeStatus[2 * i + 2]))
		cout << "(";
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
		parenthesizedView(2 * i + 1);
	if ((2 * i + 1 < arraySize && nodeStatus[2 * i + 1]) || (2 * i + 2 < arraySize && nodeStatus[2 * i + 2]))
		cout << ",";
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
		parenthesizedView(2 * i + 2);
	if ((2 * i + 1 < arraySize && nodeStatus[2 * i + 1]) || (2 * i + 2 < arraySize && nodeStatus[2 * i + 2]))
		cout << ")";
}

template <typename T>
void ArrayBinaryTree<T>::explorerView(int i)
{
	if (i < 0)
		return;
	int l = findLevel(i);
	for (int x = 0; x < l; x++)
		cout << "\t";
	cout << data[i] << "\n";
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
		explorerView(2 * i + 1);
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
		explorerView(2 * i + 2);
}

template <typename T>
void ArrayBinaryTree<T>::setRoot(T r)
{
	data[0] = r;
	nodeStatus[0] = true;
}

template <typename T>
T ArrayBinaryTree<T>::getRoot()
{
	return data[0];
}

template <typename T>
void ArrayBinaryTree<T>::setLeftChild(T parent, T child)
{
	int i = search(0, parent);
	if (i == -1 || (2 * i) + 1 >= arraySize)
		return;
	data[(2 * i) + 1] = child;
	nodeStatus[(2 * i) + 1] = true;
}

template <typename T>
void ArrayBinaryTree<T>::setRightChild(T parent, T child)
{
	int i = search(0, parent);
	if (i == -1 || (2 * i) + 2 >= arraySize)
		return;
	data[(2 * i) + 2] = child;
	nodeStatus[(2 * i) + 2] = true;
}

template <typename T>
T ArrayBinaryTree<T>::getParent(T node)
{
	int i = search(0, node);
	if (i == -1 || i == 0)
		exit(0);
	return data[(i - 1) / 2];
}

template <typename T>
void ArrayBinaryTree<T>::remove(T node)
{
	int i = search(0, node);
	if (i == -1)
		return;
	remove(i);
}

template <typename T>
void ArrayBinaryTree<T>::displayAncestors(T node)
{
	int i = search(0, node);
	if (i == -1 || i == 0)
		return;
	displayAncestors(i);
	cout << "\n";
}

template <typename T>
void ArrayBinaryTree<T>::displayDescendants(T node)
{
	int i = search(0, node);
	if (i == -1)
		return;
	displayDescendants(i);
	cout << "\n";
}

template <typename T>
int ArrayBinaryTree<T>::heightOfTree()
{
	if (!nodeStatus[0])
		return 0;
	return getHeight(0);
}

template <typename T>
void ArrayBinaryTree<T>::preOrder()
{
	VLR(0);
	cout << "\n";
}

template <typename T>
void ArrayBinaryTree<T>::postOrder()
{
	LRV(0);
	cout << "\n";
}

template <typename T>
void ArrayBinaryTree<T>::inOrder()
{
	LVR(0);
	cout << "\n";
}

template <typename T>
void ArrayBinaryTree<T>::levelOrder()
{
	Queue<int> nodes;
	nodes.enQueue(0);
	do
	{
		int i = nodes.deQueue();
		if (2 * i + 1 < arraySize && nodeStatus[2*i+1])
			nodes.enQueue(2 * i + 1);
		if (2 * i + 2 < arraySize && nodeStatus[2*i+2])
			nodes.enQueue(2 * i + 2);
		cout << data[i];
	} while (!nodes.isEmpty());
	cout << "\n";
}

template <typename T>
void ArrayBinaryTree<T>::displayLevel(int levelNo)
{
	int startInd = pow(2, levelNo) - 1;
	int endInd = pow(2, levelNo + 1) - 1;
	for (int i = startInd; i < endInd; i++)
	{
		if (nodeStatus[i])
			cout << data[i] << " ";
	}
	cout << "\n";
}

template <typename T>
int ArrayBinaryTree<T>::findLevelOfNode(T node)
{
	int i = search(0, node);
	if (i == -1)
		return -1;
	return findLevel(i);
}

template <typename T>
void ArrayBinaryTree<T>::displayParenthesizedView()
{
	parenthesizedView(0);
	cout << "\n";
}

template <typename T>
void ArrayBinaryTree<T>::displayExplorerView()
{
	explorerView(0);
}

template <typename T>
ArrayBinaryTree<T>::~ArrayBinaryTree()
{
	if (data)
		delete[] data;
	data = nullptr;
	if (nodeStatus)
		delete[] nodeStatus;
	nodeStatus = nullptr;
	arraySize = 0;
	maxHeight = 0;
}
