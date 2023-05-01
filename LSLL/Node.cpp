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