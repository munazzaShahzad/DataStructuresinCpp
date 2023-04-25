#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	BST<int> t1;
	int x = 1;
	do
	{
		cout << "Enter 1 to insert, 2 to remove\n";
		int ch, num;
		cin >> ch;
		if (ch == 1)
		{
			cout << "Enter value to insert: ";
			cin >> num;
			t1.insert(num);
		}
		else if (ch == 2)
		{
			cout << "Enter value to remove: ";
			cin >> num;
			t1.remove(num);
		}
		t1.display();
		cout << "Enter 1 to continue.\n";
		cin >> x;
	} while (x == 1);
	cout << "Enter number to search: ";
	cin >> x;
	cout << t1.search(x);
	return 0;
}