#include "Deque.h"
#include "Transaction.h"

/*
5
b 1000 3
b 1500 2.5
s 750 3.25
b 1000 3.2
s 750 3.5

7
b 1000 3
b 1500 2.5
s 750 3.25
b 1000 3.2
s 750 3.5
s 750 3
s 500 3.75
*/

int main()
{
	Deque<Transaction> bought, sale;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char ch;
		int c;
		double p;
		cin >> ch >> c >> p;
		if (ch == 'b')
			bought.insertAtTail(Transaction(c, p));
		else
			sale.insertAtTail(Transaction(c, p));
	}
	double capitalGain = 0;
	while (!sale.isEmpty())
	{
		//Transaction* tempB = &bought.getElementAtFront(), *tempS = &sale.getElementAtFront();
		Transaction tempB = bought.deleteAtHead(), tempS = sale.deleteAtHead();
		int diff = tempB.count - tempS.count;
		if (diff > 0)
		{
			tempB.count = diff;
			capitalGain += (tempS.count) * (tempS.price - tempB.price);
			bought.insertAtHead(tempB);
		}
		else
		{
			capitalGain += ((tempS.count + diff) * tempS.price) - (tempB.count * tempB.price);
			tempS.count = -diff;
			sale.insertAtHead(tempS);
		}
	}
	cout << capitalGain << "\n";
	return 0;
}