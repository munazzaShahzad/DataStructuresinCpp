#include "LDLL.h"

int main()
{
	LDLL<int> l;
	l.insertAtHead(1);
	l.insertAtTail(5);
	l.insertAfter(1, 2);
	l.insertBefore(5, 4);
	l.insertAfter(2, 3);
	l.display();
	l.removeBefore(3);
	l.display();
	l.removeAtTail();
	l.display();
	l.removeAtHead();
	l.display();
	return 0;
}