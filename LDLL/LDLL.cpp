#include "LDLL.h"

template <typename T>
LDLL<T>::LDLL()
{
	head = nullptr;
}

template <typename T>
LDLL<T>::~LDLL()
{
	while (head)
		removeAtHead();
}

template <typename T>
void LDLL<T>::insertAtHead(T val)
{
	DNode<T>* p = new DNode<T>(val);
	if (!head)
	{
		head = p;
		return;
	}
	p->next = head;
	head->prev = p;
	head = p;
}

template <typename T>
void LDLL<T>::insertAtTail(T val)
{
	DNode<T>* x = new DNode<T>(val);
	if (!head)
	{
		head = x;
		return;
	}
	DNode<T>* p = head;
	while (p->next != nullptr)
		p = p->next;
	p->next = x;
	x->prev = p;
}

template <typename T>
void LDLL<T>::insertAfter(T key, T val)
{
	DNode<T>* p = head;
	if (!head)
		return;
	while (p->next != nullptr)
	{
		if (p->info == key)
		{
			DNode<T>* x = new DNode<T>(val);
			x->next = p->next;
			x->prev = p;
			p->next->prev = x;
			p->next = x;
			return;
		}
		p = p->next;
	}
	if (p->info == key)
	{
		DNode<T>* x = new DNode<T>(val);
		x->prev = p;
		p->next = x;
	}
}

template <typename T>
void LDLL<T>::insertBefore(T key, T val)
{
	if (!head)
		return;
	DNode<T>* p = head;
	if (head->info == key)
	{
		DNode<T>* x = new DNode<T>(val);
		x->next = head;
		head->prev = x;
		head = x;
		return;
	}
	while (p != nullptr)
	{
		if (p->info == key)
		{
			DNode<T>* x = new DNode<T>(val);
			x->next = p;
			x->prev = p->prev;
			p->prev = x;
			x->prev->next = x;
			return;
		}
		p = p->next;
	}
}

template <typename T>
void LDLL<T>::remove(T key)
{
	if (!head)
		return;
	DNode<T>* p = head;
	if (p->info == key)
	{
		removeAtHead();
		return;
	}
	while (p->next != nullptr)
	{
		if (p->info == key)
		{
			p->next->prev = p->prev;
			p->prev->next = p->next;
			delete p;
			return;
		}
		p = p->next;
	}
	if (p->info == key)
	{
		p->prev->next = nullptr;
		delete p;
	}
}

template <typename T>
void LDLL<T>::removeAtHead()
{
	if (!head)
		return;
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}
	DNode<T>* p = head;
	head = head->next;
	head->prev = nullptr;
	delete p;
}

template <typename T>
void LDLL<T>::removeAtTail()
{
	if (!head)
		return;
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}
	DNode<T>* p = head->next;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->prev->next = nullptr;
	delete p;
}

template <typename T>
void LDLL<T>::removeAfter(T key)
{
	if (!head)
		return;
	DNode<T>* p = head;
	if (p->info == key)
	{
		if (p->next != nullptr)
		{
			DNode<T>* x = p->next;
			p->next = x->next;
			x->next->prev = x->prev;
			delete x;
		}
		return;
	}
	while (p->next->next != nullptr)
	{
		if (p->info == key)
		{
			p->next->prev = p->prev;
			p->prev->next = p->next;
			delete p;
			return;
		}
		p = p->next;
	}
	if (p->info == key)
	{
		delete p->next;
		p->next = nullptr;
	}
}

template <typename T>
void LDLL<T>::removeBefore(T key)
{
	if (!head)
		return;
	if (head->info == key)
	{
		removeAtHead();
		return;
	}
	if (head->next == nullptr)
		return;
	DNode<T>* p = head;
	if (head->next->info == key)
	{
		head = p->next;
		head->prev = nullptr;
		delete p;
		return;
	}
	while (p->next != nullptr)
	{
		if (p->next->info == key)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			return;
		}
		p = p->next;
	}
}

template <typename T>
void LDLL<T>::display()
{
	DNode<T>* p = head;
	while (p->next != nullptr)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << p->info;
	cout << "\n";
	while (p->prev != nullptr)
	{
		cout << p->info << " ";
		p = p->prev;
	}
	cout << p->info;
	cout << "\n";
}