#include "LinkMinHeap.h"

int main()
{
	LinkMinHeap<int> mh1;
	for (int i = 0; i < 12; i++)
	{
		int x;
		cout << "Next: ";
		cin >> x;
		mh1.insert(x);
		mh1.display();
	}
	for (int i = 0; i < 12; i++)
	{
		cout << mh1.getMin() << "\n";
		mh1.removeMin();
		mh1.display();
	}
	return 0;
}