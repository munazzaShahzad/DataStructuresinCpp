#include "LSLLusingArray.h"

template <typename T>
int LSLLusingArray<T>::getNewNode()
{
	int x = SLhead;
	SLhead = arr[SLhead].next;
	return x;
}

template <typename T>
void LSLLusingArray<T>::returnNode(int i)
{
	arr[i].next = SLhead;
	SLhead = i;
}

template <typename T>
LSLLusingArray<T>::LSLLusingArray()
{
	for (int i = 0; i < 99; i++)
	{
		arr[i].next = i + 1;
	}
	arr[99] = -1;
	SLhead = 0;
	ULhead = -1;
}

template <typename T>
void LSLLusingArray<T>::insertAtHead(T val)
{
	int x = getNewNode();
	arr[x].info = val;
	arr[x].next = ULhead;
	ULhead = x;
}

template <typename T>
void LSLLusingArray<T>::insertAtTail(T val)
{
	int x = getNewNode();
	arr[x].info = val;
	arr[x].next = -1;
	if (ULhead == -1)
	{
		ULhead = x;
		return;
	}
	int p = ULhead;
	while (arr[p].next != -1)
	{
		p = arr[p].next;
	}
	arr[p].next = x;
}

template <typename T>
void LSLLusingArray<T>::remove(T val)
{
	int index = ULhead;
	while (index != -1 && arr[arr[index].next].info != val)
	{
		index = arr[index].next;
	}
	if (index == -1)
		return;
	//int toRemove = arr[index].next;
	arr[index].next = arr[arr[index].next].next;
	returnNode(arr[index].next);
}

template <typename T>
void LSLLusingArray<T>::insertAfter(T key, T val)
{
	int p = ULhead;
	while (p != -1)
	{
		if (arr[p].info == key)
		{
			int newN = getNewNode();
			arr[newN].info = val;
			arr[newN].next = arr[p].next;
			arr[p].next = newN;
			return;
		}
		p = arr[p].next;
	}
}

template <typename T>
void LSLLusingArray<T>::insertBefore(T key, T val)
{
	if (ULhead == -1)
		return;
	if (arr[ULhead].info == key)
	{
		int x = getNewNode();
		arr[x].info = val;
		arr[x].next = ULhead;
		ULhead = x;
		return;
	}
	int p = ULhead;
	while (arr[p].next != -1)
	{
		if (arr[arr[p].next].info == key)
		{
			int x = getNewNode();
			arr[x].info = val;
			arr[x].next = arr[p].next;
			arr[p].next = x;
			return;
		}
		p = arr[p].next;
	}
}

template <typename T>
void LSLLusingArray<T>::removeAtHead()
{
	if (ULhead == -1)
		return;
	int p = ULhead;
	ULhead = arr[ULhead].next;
	returnNode(p);
}

template <typename T>
void LSLLusingArray<T>::removeAtTail()
{
	if (ULhead == -1)
		return;
	int p = ULhead;
	if (arr[ULhead].next == -1)
	{
		ULhead = -1;
		returnNode(p);
		return;
	}
	while (arr[arr[p].next].next != -1)
		p = arr[p].next;
	returnNode(arr[p].next);
	arr[p].next = -1;
}

template <typename T>
void LSLLusingArray<T>::removeAfter(T key)
{
	if (ULhead == -1)
		return;
	int p = ULhead;
	while (arr[p].next != -1)
	{
		if (arr[p].info == key)
		{
			int x = arr[p].next;
			arr[p].next = arr[x].next;
			returnNode(x);
			return;
		}
		p = arr[p].next;
	}
}

template <typename T>
void LSLLusingArray<T>::removeBefore(T key)
{
	if (ULhead == -1)
		return;
	int p = ULhead;
	if (arr[ULhead].info == key)
		return;
	if (arr[arr[ULhead].next].info == key)		//remove head
	{
		ULhead = arr[ULhead].next;
		returnNode(p);
		return;
	}
	while (arr[arr[p].next].next != -1)
	{
		if (arr[arr[arr[p].next].next].info == key)
		{
			//p will be just before the element we remove (x)
			int x = arr[p].next;
			arr[p].next = arr[x].next;
			returnNode(x);
			return;
		}
		p = arr[p].next;
	}
}

template <typename T>
void LSLLusingArray<T>::printAll() const
{
	int head = ULhead;
	while (head != -1)
	{
		cout << arr[head].info << " ";
		head = arr[head].next;
	}
	cout << "\n";
}