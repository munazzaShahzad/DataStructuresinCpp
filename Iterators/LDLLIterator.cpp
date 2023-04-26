#include <iostream>
using namespace std;

template <typename T>
struct DNode
{
	T info;
	DNode<T>* next;
	DNode<T>* prev;

	DNode()
	{
		next = nullptr;
		prev = nullptr;
		info = 0;
	}

	template <typename T>
	DNode(T val)
	{
		info = val;
		next = nullptr;
		prev = nullptr;
	}
};

namespace LDLL_ITERATOR
{
	template <typename T>
	class LDLL
	{
		DNode<T>* head;

	public:

		LDLL()
		{
			head = nullptr;
		}

		~LDLL()
		{
			while (head)
				removeAtHead();
		}

		void insertAtHead(T val)
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

		void insertAtTail(T val)
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

		void insertAfter(T key, T val)
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

		void insertBefore(T key, T val)
		{
			DNode<T>* p = head;
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

		void remove(T key)
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

		void removeAtHead()
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

		void removeAtTail()
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

		void removeAfter(T key)
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

		void removeBefore(T key)
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

		void display()
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


		class Iterator
		{
			DNode<T>* cur = nullptr;

			friend class LDLL<T>;
			//constructor
			Iterator(DNode<T>* ptr) : cur(ptr)
			{}

		public:

			T& operator * ()
			{
				if (cur)
					return cur->info;
				else
					exit(0);
			}

			//for constant object
			const T& operator * () const
			{
				if (cur)
					return cur->info;
				else
					exit(0);
			}

			void operator ++ ()
			{
				if (cur)
					cur = cur->next;
				else
					exit(0);
			}

			void operator -- ()
			{
				if (cur)
					cur = cur->prev;
				else
					exit(0);
			}

			bool operator !=(const Iterator& ref)
			{
				if (cur != ref.cur)
					return true;
				return false;
			}

		};

		Iterator begin()
		{
			return Iterator(head);
		}

		Iterator end()
		{
			return Iterator(nullptr);
		}

		Iterator rbegin()
		{
			DNode<T>* tail = head;
			while (tail->next != nullptr)
				tail = tail->next;
			return Iterator(tail);
		}
	};

}

using namespace LDLL_ITERATOR;

int main()
{
	LDLL<int> l1;
	l1.insertAtHead(4);
	l1.insertAtHead(3);
	l1.insertAtHead(7);
	l1.insertAtHead(1);
	l1.insertAtHead(8);
	l1.insertAtHead(2);
	l1.insertAtHead(9);
	l1.insertAtHead(11);
	cout << "l1:\n";
	l1.display();

	cout << "\n";

	cout << "Using range loop: ";
	for (auto x : l1)
	{
		cout << x << " ";
	}
	cout << "\n";

	LDLL<int>::Iterator i = l1.begin();

	cout << "Froward iteration: ";

	while (i != l1.end())
	{
		cout << *i << " ";
		++i;
	}
	cout << "\n";
	
	/*i = l1.begin();
	for (int j = 0; j < 7; j++)
		++i;*/

	cout << "Backward iteration: ";

	i = l1.rbegin();

	while (i != l1.begin())
	{
		cout << *i << " ";
		--i;
	}
	cout << *i;

	cout << "\n";
	return 0;
}