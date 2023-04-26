#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T info;
	Node<T>* next;

	Node()
	{
		next = nullptr;
		info = 0;
	}

	template <typename T>
	Node(T val)
	{
		info = val;
		next = nullptr;
	}
};

namespace LSLL_ITERATOR
{
	template <typename T>
	class LSLL
	{
		Node<T>* head;
	public:

		LSLL()
		{
			head = nullptr;
		}

		LSLL(const LSLL<T>& ref) : LSLL()
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

		LSLL<T>& operator=(const LSLL<T>& ref)
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

		void insertAtHead(T val)
		{
			Node<T>* p = new Node<T>(val);
			p->next = head;
			head = p;
		}

		void insertAtTail(T val)
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

		void insertAfter(T key, T val)
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

		void insertBefore(T key, T val)
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

		void remove(T key)
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

		void removeAtHead()
		{
			if (!head)
				return;
			Node<T>* p = head;
			head = p->next;
			delete p;
			return;
		}

		void removeAtTail()
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

		void removeAfter(T key)
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

		void removeBefore(T key)
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

		~LSLL()
		{
			while (head)
			{
				removeAtHead();
			}
		}

		void display()
		{
			Node<T>* p = head;
			while (p != nullptr)
			{
				cout << p->info << " ";
				p = p->next;
			}
			cout << "\n";
		}

		class Iterator
		{
			Node<T>* cur = nullptr;

			friend class LSLL<T>;
			//constructor
			Iterator(Node<T>* ptr) : cur(ptr)
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

	};
}

using namespace LSLL_ITERATOR;

int main()
{
	LSLL<int> l1;
	l1.insertAtHead(4);
	l1.insertAtHead(3);
	l1.insertAtHead(7);
	l1.insertAtHead(1);
	l1.insertAtHead(8);
	l1.insertAtHead(2);
	l1.insertAtHead(9);
	l1.insertAtHead(11);
	cout << "l1: ";
	l1.display();

	//LSLL<int>::Iterator i = l1.begin();
	for (auto x : l1)
	{
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}