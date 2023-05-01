#include <iostream>
#include "LSLL.h"

using namespace std;

int main()
{
	LSLL<int> l;
	l.insertAtHead(5);
	l.insertAtHead(4);
	l.insertAtTail(6);
	l.insertAtHead(3);
	l.display();
	l.insertAfter(5, 7);
	l.insertAfter(6, 9);
	l.display();
	l.insertBefore(3, 2);
	l.insertBefore(9, 8);
	l.display();
	l.remove(6);
	l.display();
	l.removeAfter(3);
	l.display();
	l.removeAtHead();
	l.removeAtTail();
	l.display();
	l.removeBefore(8);
	l.removeBefore(3);
	l.removeAfter(8);
	l.display();
	return 0;
}