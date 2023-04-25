#include "Deck.h"

int main()
{
	Deck<int> q1;
	for (int i = 0; i < 5; i++)
	{
		q1.insertAtTail(i + 1);
	}
	for (int i = 0; i < 5; i++)
	{
		q1.insertAtHead(i + 6);
	}
	cout << "noe " << q1.getNoOfElements();
	cout << "\ncap " << q1.getCapacity();
	cout << "\n";
	int t;
	for (int i = 0; i < 3; i++)
	{
		t = q1.deleteAtHead();
		cout << t << " ";
		t = q1.deleteAtTail();
		cout << t << " ";
	}
	cout << "\n";
	cout << "noe " << q1.getNoOfElements();
	cout << "\ncap " << q1.getCapacity();
	cout << "\n";
	/*for (int i = 0; i < 20; i++)
	{
		q1.enQueue(i + 11);
	}
	cout << "noe " << q1.getNoOfElements();
	cout << "\ncap " << q1.getCapacity();
	cout << "\n";
	for (int i = 0; i < 16; i++)
	{
		t = q1.deQueue();
		cout << t << " ";
	}
	cout << "\n";
	cout << "noe " << q1.getNoOfElements();
	cout << "\ncap " << q1.getCapacity();
	cout << "\n";*/
	return 0;
}