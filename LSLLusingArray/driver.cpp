
#include "LSLLusingArray.h"
int main()
{
	LSLLusingArray<int> l1;
	int x;
	for (int i = 0; i < 15; i++)
	{
		cin >> x;
		l1.insertAtHead(x);
	}
	l1.printAll();
	do
	{
		cout << "Enter number to remove: ";
		cin >> x;
		l1.remove(x);
		l1.printAll();
		cout << "Enter 2 to insert at head: ";
		cin >> x;
		if (x == 2)
		{
			cout << "Enter number to insert: ";
			cin >> x;
			l1.insertAtHead(x);
		}
		cout << "Enter -1 to stop: ";
		cin >> x;
	} while (x != -1);
	return 0;
}