#include "LinkBinaryTree.h"

int main()
{
	LinkBinaryTree<char> bt;
	bt.setRoot('A');
	bt.setLeftChild('A', 'B');
	bt.setRightChild('A', 'C');
	bt.setLeftChild('B', 'D');
	bt.setRightChild('B', 'E');
	bt.setRightChild('D', 'H');
	bt.setLeftChild('E', 'I');
	bt.setRightChild('E', 'J');
	bt.setLeftChild('I', 'K');
	bt.setRightChild('C', 'F');

	cout << "Parent of E is: ";
	cout << bt.getParent('E') << "\n";

	cout << "Ancestors of I: ";
	bt.displayAncestors('I');
	cout << "\n";

	cout << "Descendants of B: ";
	bt.displayDescendants('B');

	cout << "Height of tree: " << bt.heightOfTree() << "\n";

	cout << "Pre Order: ";
	bt.preOrder();

	cout << "Post Order: ";
	bt.postOrder();

	cout << "In Order: ";
	bt.inOrder();

	cout << "Level Order: ";
	bt.levelOrder();

	cout << "Level 3 ";
	bt.displayLevel(3);

	cout << "Level of F: " << bt.findLevelOfNode('F') << "\n";

	cout << "Parenthesized View: ";
	bt.displayParenthesizedView();

	cout << "Explorer View:\n";
	bt.displayExplorerView();

	cout << "Removing E\n";
	bt.remove('E');

	cout << "New tree: ";
	bt.displayParenthesizedView();

	bt.setRightChild('B', 'X');
	bt.displayParenthesizedView();
	return 0;
}