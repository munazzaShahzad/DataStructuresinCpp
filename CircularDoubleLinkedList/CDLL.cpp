#include "CDLL.h"

template <typename T>
CDLL<T>::CDLL()
{
	head = nullptr;
}

template <typename T>
void CDLL<T>::printALL()
{
	if (!head)
	{
		cout << "Empty list\n";
		return;
	}
	DNode<T>* p = head;
	cout << "Forward: ";
	do
	{
		cout << p->info << " ";
		p = p->next;
	} while (p != head);
	cout << "\n";
	cout << "Backward: ";
	p = p->prev;
	do
	{
		cout << p->info << " ";
		p = p->prev;
	} while (p != head->prev);
	cout << "\n";
}

template <typename T>
void CDLL<T>::insertAtHead(T val)
{
	DNode<T>* x = new DNode<T>(val);
	if (!head)
	{
		head = x;
		head->next = x;
		head->prev = x;
		return;
	}
	x->next = head;
	x->prev = head->prev;
	head->prev = x;
	x->prev->next = x;
	head = x;
}

template <typename T>
void CDLL<T>::insertAtTail(T val)
{
	DNode<T>* x = new DNode<T>(val);
	if (!head)
	{
		head = x;
		head->next = x;
		head->prev = x;
		return;
	}
	head->prev->next = x;
	x->next = head;
	x->prev = head->prev;
	head->prev = x;
}

template <typename T>
void CDLL<T>::insertBefore(T key, T val)
{
	if (!head)
		return;
	DNode<T>* p = head;
	do
	{
		if (p->info == key)
		{
			DNode<T>* x = new DNode<T>(val);
			x->next = p;
			x->prev = p->prev;
			x->prev->next = x;
			p->prev = x;
			if (p == head)
				head = x;
			return;
		}
		p = p->next;
	} while (p != head);
}

template <typename T>
void CDLL<T>::insertAfter(T key, T val)
{
	if (!head)
		return;
	DNode<T>* p = head;
	do
	{
		if (p->info == key)
		{
			DNode<T>* x = new DNode<T>(val);
			x->next = p->next;
			x->prev = p;
			x->next->prev = x;
			p->next = x;
			return;
		}
		p = p->next;
	} while (p != head);
}

template <typename T>
void CDLL<T>::removeAtHead()
{
	if (!head)
		return;
	DNode<T>* p = head;
	if (head->next == head)
	{
		head = nullptr;
		delete p;
		return;
	}
	head->prev->next = head->next;
	head->next->prev = head->prev;
	head = head->next;
	delete p;
}

template <typename T>
void CDLL<T>::removeAtTail()
{
	if (!head)
		return;
	if (head == head->next)
	{
		delete head;
		head = nullptr;
		return;
	}
	DNode<T>* p = head->prev;	//tail
	p->prev->next = head;
	head->prev = p->prev;
	delete p;
}

template <typename T>
void CDLL<T>::removeBefore(T key)
{
	if (!head)
		return;
	DNode<T>* p = head;
	do
	{
		if (p->info == key)
		{
			DNode<T>* x = p->prev;
			x->prev->next = p;
			p->prev = x->prev;
			delete x;
			if (x == head)
				head = p;
			return;
		}
		p = p->next;
	} while (p != head);
}

template <typename T>
void CDLL<T>::remove(T key)
{
	if (!head)
		return;
	DNode<T>* p = head;
	if (head->next == head)
	{
		if (head->info == key)
		{
			head = nullptr;
			delete p;
		}
		return;
	}
	if (head->info == key)
	{
		removeAtHead();
		return;
	}
	else
		p = p->next;
	while (p->info != key)
	{
		p = p->next;
		if (p == head)
			return;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
}

template <typename T>
void CDLL<T>::removeAfter(T key)
{
	if (!head)
		return;
	if (head == head->next)
		return;
	DNode<T>* p = head;
	do
	{
		if (p->info == key)
		{
			DNode<T>* temp = p->next;
			p->next = p->next->next;
			delete p->next->prev;
			p->next->prev = p;
			if (temp == head)
				head = p->next;
			return;
		}
		p = p->next;
	} while (p != head);
}



template <typename T>
CDLL<T>::~CDLL()
{
	while (head)
		removeAtHead();
}