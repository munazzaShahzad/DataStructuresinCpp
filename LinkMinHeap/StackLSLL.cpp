#include "StackLSLL.h"

template <typename T>
StackLSLL<T>::StackLSLL()
{
	head = nullptr;
}

template <typename T>
StackLSLL<T>::~StackLSLL()
{
	while (head)
	{
		pop();
	}
}

template <typename T>
void StackLSLL<T>::push(T val)
{
	Node<T>* p = new Node<T>(val);
	p->next = head;
	head = p;
	noe++;
}

template <typename T>
T StackLSLL<T>::pop()
{
	if (!head)
		exit(0);
	Node<T>* p = head;
	T val = p->info;
	head = p->next;
	delete p;
	noe--;
	return val;
}

template <typename T>
T StackLSLL<T>::stackTop() const
{
	return head->info;
}

template <typename T>
bool StackLSLL<T>::isEmpty() const
{
	return head == nullptr;
}

template <typename T>
int StackLSLL<T>::getNumberOfElements() const
{
	return noe;
}

template <typename T>
void StackLSLL<T>::display() const
{
	Node<T>* p = head;
	while (p != nullptr)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << "\n";
}