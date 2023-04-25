#include "Stack.h"
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

int precedenceOp(char ch)
{
	if (ch == '-' || ch == '+')
		return 1;
	return 2;
}

double evaluateExpression(string in)
{
	Stack<double> result;
	Stack<char> operators;
	int length = in.length();
	double num = 0, mul = 10;
	for (int i = 0; i < length; i++)
	{
		char temp = in[i];
		if (temp == ' ')
			continue;
		if (temp >= '0' && temp <= '9' || temp == '.')
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
				char next = in[i + 1];
				if (next == '+' || next == '-' || next == '*' || next == '/' || next == '(' || next == ')' || next == '{' || next == '}' || next == '[' || next == ']' || next == '/0')
				{
					result.push(num);
					num = 0;
					mul = 10;
				}
			}
		}
		else if (temp == '(' || temp == '{' || temp == '[')
			operators.push(temp);
		else if (temp == ')')
		{
			char prev = operators.stackTop();
			while (prev != '(')
			{
				prev = operators.pop();
				double o2 = result.pop();
				double o1 = result.pop();
				if (prev == '+')
					result.push(o1 + o2);
				else if (prev == '-')
					result.push(o1 - o2);
				else if (prev == '*')
					result.push(o1 * o2);
				else
					result.push(o1 / o2);
				prev = operators.stackTop();
			}
			operators.pop();
		}
		else if (temp == '}')
		{
			char prev = operators.stackTop();
			while (prev != '{')
			{
				prev = operators.pop();
				double o2 = result.pop();
				double o1 = result.pop();
				if (prev == '+')
					result.push(o1 + o2);
				else if (prev == '-')
					result.push(o1 - o2);
				else if (prev == '*')
					result.push(o1 * o2);
				else
					result.push(o1 / o2);
				prev = operators.stackTop();
			}
			operators.pop();
		}
		else if (temp == ']')
		{
			char prev = operators.stackTop();
			while (prev != '[')
			{
				prev = operators.pop();
				double o2 = result.pop();
				double o1 = result.pop();
				if (prev == '+')
					result.push(o1 + o2);
				else if (prev == '-')
					result.push(o1 - o2);
				else if (prev == '*')
					result.push(o1 * o2);
				else
					result.push(o1 / o2);
				prev = operators.stackTop();
			}
			operators.pop();
		}
		else
		{
			if (operators.isEmpty())
				operators.push(temp);
			else
			{
				char prev = operators.stackTop();
				while (prev != '(' && prev != '{' && prev != '[' && precedenceOp(temp) <= precedenceOp(prev))
				{
					prev = operators.pop();
					double o2 = result.pop();
					double o1 = result.pop();
					if (prev == '+')
						result.push(o1 + o2);
					else if (prev == '-')
						result.push(o1 - o2);
					else if (prev == '*')
						result.push(o1 * o2);
					else
						result.push(o1 / o2);
					if (operators.isEmpty())
						break;
					prev = operators.stackTop();
				}
				operators.push(temp);
			}
		}
	}
	if (num != 0)
	{
		result.push(num);
	}
	while (!operators.isEmpty())
	{
		char prev = operators.pop();
		double o2 = result.pop();
		double o1 = result.pop();
		if (prev == '+')
			result.push(o1 + o2);
		else if (prev == '-')
			result.push(o1 - o2);
		else if (prev == '*')
			result.push(o1 * o2);
		else
			result.push(o1 / o2);
	}
	return result.pop();
}

//10+3.5-[20/{(6+3.5)*0.07}+5.7]
//3-3*(4+30-(56+9))/2

int main()
{
	string str;
	char ch;
	do
	{
		cout << "Enter Infix expression: \n";
		getline(cin, str);

		double result = evaluateExpression(str);

		cout << "The answer is: " << fixed << setprecision(5) << result << "\n";
		cout << "\nDo you want to evaluate another expression?\n Enter 'Y' for yes && 'N' for no.\n";
		cin >> ch;
		cout << "====================================\n";
		cin.ignore();
	} while (ch == 'Y' || ch == 'y');
	return 0;
}