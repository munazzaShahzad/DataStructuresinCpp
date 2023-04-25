#include "AVL.h"

int main()
{
	AVL<int> avl1;
	avl1.insert(10);
	avl1.insert(5);
	avl1.insert(20);
	avl1.insert(3);
	avl1.insert(7);
	avl1.insert(15);
	avl1.insert(30);
	avl1.insert(2);
	avl1.insert(4);
	avl1.insert(6);
	avl1.insert(9);
	avl1.insert(17);
	avl1.insert(25);
	avl1.insert(40);
	avl1.insert(1);
	avl1.insert(5);
	avl1.insert(8);
	avl1.insert(9);
	avl1.insert(35);
	avl1.insert(45);
	avl1.insert(7);
	avl1.display();

	avl1.remove(7);
	avl1.display();

	avl1.remove(20);
	avl1.display();

	return 0;
}