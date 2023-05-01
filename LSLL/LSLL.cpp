#include "LSLL.h"

template <typename T>
LSLL::LSLL()
{
	head = nullptr;
}

template <typename T>
LSLL::LSLL(const LSLL<T> &ref) : LSLL()
{
	if (!ref.head)
		return;
	Node<T>* p = ref.head;
	while (p != nullptr)
	{
		insertAtTail(p->info);
		p = p->next;
	}
}

template <typename T>
LSLL<T>& LSLL<T>::operator=(const LSLL<T>& ref)
{
	if (this == &ref)
		return *this;
	this->~LSLL();
	if (!ref.head)
		return *this;
	Node<T>* p = ref.head;
	while (p != nullptr)
	{
		insertAtTail(p->info);
		p = p->next;
	}
	return *this;
}

template <typename T>
void LSLL<T>::insertAtHead(T val)
{
	Node<T>* p = new Node<T>(val);
	p->next = head;
	head = p;
}

template <typename T>
void LSLL<T>::insertAtTail(T val)
{
	if (!head)
	{
		insertAtHead(val);
		return;
	}
	Node<T>* p = head;
	while (p->next != nullptr)
		p = p->next;
	Node<T>* x = new Node<T>(val);
	p->next = x;
}

template <typename T>
void LSLL<T>::insertAfter(T key, T val)
{
	Node<T>* p = head;
	while (p != nullptr)
	{
		if (p->info == key)
		{
			Node<T>* x = new Node<T>(val);
			x->next = p->next;
			p->next = x;
			return;
		}
		p = p->next;
	}
}

template <typename T>
void LSLL<T>::insertBefore(T key, T val)
{
	if (!head)
		return;
	if (head->info == key)
	{
		insertAtHead(val);
		return;
	}
	Node<T>* p = head;
	while (p->next != nullptr)
	{
		if (p->next->info == key)
		{
			Node<T>* x = new Node<T>(val);
			x->next = p->next;
			p->next = x;
			return;
		}
		p = p->next;
	}
}

template <typename T>
void LSLL<T>::remove(T key)
{
	if (!head)
		return;
	Node<T>* p = head;
	if (p->info == key)
	{
		head = p->next;
		delete p;
		return;
	}
	while (p->next != nullptr)
	{
		if (p->next->info == key)
		{
			Node<T>* x = p->next;
			p->next = p->next->next;
			delete x;
			return;
		}
		p = p->next;
	}
}

template <typename T>
void LSLL<T>::removeAtHead()
{
	if (!head)
		return;
	Node<T>* p = head;
	head = p->next;
	delete p;
	return;
}

template <typename T>
void LSLL<T>::removeAtTail()
{
	if (!head)
		return;
	Node<T>* p = head;
	if (p->next == nullptr)
	{
		head = nullptr;
		delete p;
		return;
	}
	while (p->next->next != nullptr)
		p = p->next;
	delete p->next;
	p->next = nullptr;
}

template <typename T>
void LSLL<T>::removeAfter(T key)
{
	if (!head)
		return;
	Node<T>* p = head;
	while (p->next != nullptr)
	{
		if (p->info == key)
		{
			Node<T>* x = p->next;
			p->next = p->next->next;
			delete x;
			return;
		}
		p = p->next;
	}
}

template <typename T>
void LSLL<T>::removeBefore(T key)
{
	if (!head)
		return;
	Node<T>* p = head;
	if (p->info == key)
		return;
	if (p->next->info == key)
	{
		head = p->next;
		delete p;
		return;
	}
	while (p->next->next != nullptr)
	{
		if (p->next->next->info == key)
		{
			Node<T>* x = p->next;
			p->next = p->next->next;
			delete x;
			return;
		}
		p = p->next;
	}
}

template <typename T>
LSLL<T>::~LSLL()
{
	while (head)
	{
		removeAtHead();
	}
}

template <typename T>
void LSLL<T>::display()
{
	Node<T>* p = head;
	while (p != nullptr)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << "\n";
}