#include <iostream>
#include <string>
#include <iomanip>
#include "Stack.h"

using namespace std;

double evaluatePostFixExpression(string postfix)
{
	Stack<double> result;
	int length = postfix.length();
	double num = 0, mul = 10;
	for (int i = 0; i < length; i++)
	{
		char temp = postfix[i];
		if (temp == ',')
		{
			num = 0;
			mul = 10;
		}
		else if (temp >= '0' && temp <= '9' || temp == '.')
		{
			if (temp == '.')
			{
				mul = 0.1;
			}
			else
			{
				if (mul == 10)
				{
					num *= 10;
					num += (temp - (double)'0');
				}
				else
				{
					num += ((temp - (double)'0') * mul);
					mul *= 0.1;
				}
				char next = postfix[i + 1];
				if (next == ',')
					result.push(num);
			}
		}
		else
		{
			double o2 = result.pop();
			double o1 = result.pop();
			if (temp == '+')
				result.push(o1 + o2);
			else if (temp == '-')
				result.push(o1 - o2);
			else if (temp == '*')
				result.push(o1 * o2);
			else
				result.push(o1 / o2);
		}
	}
	return result.pop();
}

int main()
{
	string str;
	char ch;
	do
	{
		cout << "Enter Infix expression: \n";
		getline(cin, str);

		double result = evaluatePostFixExpression(str);

		cout << "The answer is: " << fixed << setprecision(5) << result << "\n";
		cout << "\nDo you want to evaluate another expression?\n Enter 'Y' for yes && 'N' for no.\n";
		cin >> ch;
		cout << "====================================\n";
		cin.ignore();
	} while (ch == 'Y' || ch == 'y');
	return 0;
}