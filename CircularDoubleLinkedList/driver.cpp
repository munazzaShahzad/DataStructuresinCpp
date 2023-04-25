#include "CDLL.h"

int main()
{
	int x, num;
	CDLL<int> l1;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		l1.insertAtTail(x);
	}
	l1.printALL();
	/*l1.removeAtHead();
	cout << "After removing at head:\n";
	l1.printALL();
	do
	{
		cout << "Enter value to remove: ";
		cin >> x;
		l1.remove(x);
		l1.printALL();
		cout << "Enter -1 to stop: ";
		cin >> x;
	} while (x != -1);*/

	cout << "Enter number to insert before: ";
	cin >> x;
	cout << "Enter number to insert: ";
	cin >> num;
	l1.insertBefore(x, num);
	l1.printALL();

	cout << "Enter number to insert after: ";
	cin >> x;
	cout << "Enter number to insert: ";
	cin >> num;
	l1.insertAfter(x, num);
	l1.printALL();

	cout << "Enter number to remove before: ";
	cin >> x;
	l1.removeBefore(x);
	l1.printALL();

	cout << "Enter number to remove after: ";
	cin >> x;
	l1.removeAfter(x);
	l1.printALL();

	cout << "Removing at Tail: ";
	l1.removeAtTail();
	l1.printALL();
	
	return 0;
}