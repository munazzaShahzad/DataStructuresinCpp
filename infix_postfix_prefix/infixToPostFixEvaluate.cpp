#include <iostream>
#include <string>
#include <iomanip>
#include "Stack.h"

using namespace std;

int precedence(char ch)
{
	if (ch == '-' || ch == '+')
		return 1;
	return 2;
}

char* singleDigitInfixToPostfix(string infix)
{
	int N = infix.length();
	char* postfix = new char[N];
	Stack<char> operators;
	int indP = 0;
	for (int i = 0; i < N; i++)
	{
		char temp = infix[i];
		if (temp == ' ')
			continue;
		if (temp >= '0' && temp <= '9')
		{
			postfix[indP++] = temp;
		}
		else if (temp == '(' || temp == '{' || temp == '[')
			operators.push(temp);
		else if (temp == ')')
		{
			char prev = operators.stackTop();
			while (prev != '(')
			{
				prev = operators.pop();
				postfix[indP++] = prev;
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
				postfix[indP++] = prev;
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
				postfix[indP++] = prev;
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
				while (prev != '(' && prev != '{' && prev != '[' && precedence(temp) <= precedence(prev))
				{
					prev = operators.pop();
					postfix[indP++] = prev;
					if (operators.isEmpty())
						break;
					prev = operators.stackTop();
				}
				operators.push(temp);
			}
		}
	}
	while (!operators.isEmpty())
	{
		postfix[indP++] = operators.pop();
	}
	postfix[indP] = '\0';
	return postfix;
}

double singleDigitExpression(string infix)
{
	string postfix = singleDigitInfixToPostfix(infix);
	cout << "Postfix expression will be: " << postfix << "\n";
	Stack<double> result;
	int length = postfix.length();
	for (int i = 0; i < length; i++)
	{
		char temp = postfix[i];
		if (temp >= '0' && temp <= '9')
		{
			result.push(temp - (double)'0');
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

char* multiDigitFloatInfixToPostfix(string infix)
{
	int N = infix.length();
	char* postfix = new char[N];
	Stack<char> operators;
	int indP = 0;
	for (int i = 0; i < N; i++)
	{
		char temp = infix[i];
		if (temp == ' ')
			continue;
		if (temp >= '0' && temp <= '9' || temp == '.')
		{
			postfix[indP++] = temp;
			char next = infix[i + 1];
			if (!(next >= '0' && next <= '9' || next == '.'))
				postfix[indP++] = ' ';
		}
		else if (temp == '(' || temp == '{' || temp == '[')
			operators.push(temp);
		else if (temp == ')')
		{
			char prev = operators.stackTop();
			while (prev != '(')
			{
				prev = operators.pop();
				postfix[indP++] = prev;
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
				postfix[indP++] = prev;
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
				postfix[indP++] = prev;
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
				while (prev != '(' && prev != '{' && prev != '[' && precedence(temp) <= precedence(prev))
				{
					prev = operators.pop();
					postfix[indP++] = prev;
					if (operators.isEmpty())
						break;
					prev = operators.stackTop();
				}
				operators.push(temp);
			}
		}
	}
	while (!operators.isEmpty())
	{
		postfix[indP++] = operators.pop();
	}
	postfix[indP] = '\0';
	return postfix;
}

double multiDigitFloatExpression(string infix)
{
	string postfix = multiDigitFloatInfixToPostfix(infix);
	cout << "Postfix expression will be: " << postfix << "\n";
	Stack<double> result;
	int length = postfix.length();
	double num = 0, mul = 10;
	for (int i = 0; i < length; i++)
	{
		char temp = postfix[i];
		if (temp == ' ')
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
				if (next == ' ')
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
	char choice, ch;
	do
	{
		do
		{
			cout << "To evaluate an expression with single digit operands, enter '1'.\n";
			cout << "To evaluate an expression with multiple digit or float operands, enter '2'.\n";
			cin >> choice;
			if (!(choice == '1' || choice == '2'))
				cout << "Invalid choice! Enter choice again!.\n=======================\n";
		} while (!(choice == '1' || choice == '2'));

		cout << "Enter Infix expression: \n";
		cin.ignore();
		getline(cin, str);

		double result;

		if (choice == '1')
			result = singleDigitExpression(str);
		else
			result = multiDigitFloatExpression(str);

		cout << "The answer is: " << fixed << setprecision(5) << result << "\n";
		cout << "\nDo you want to evaluate another expression?\n Enter 'Y' for yes && 'N' for no.\n";
		cin >> ch;
		cout << "====================================\n";
	} while (ch == 'Y' || ch == 'y');
	return 0;
}