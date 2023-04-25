#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;

int precedenceOpr(char ch)
{
	if (ch == '-' || ch == '+')
		return 1;
	if (ch == '/')
		return 3;
	return 2;
}

string usingTwoStacks(string infix)
{
	//string postfix;
	Stack<string> operands;
	Stack<char> operators;
	string temp;

	for (int i = 0; i < infix.length(); i++)
	{
		char cur = infix[i];
		if (cur == ' ')
			continue;
		if (cur >= '0' && cur <= '9' || cur=='.')
		{
			char next = infix[i + 1];
			temp += cur;
			if (next == '+' || next == '-' || next == '*' || next == '/' || next == '(' || next == ')' || next == '{' || next == '}' || next == '[' || next == ']' || next == '/0')
			{
				temp += ",";
				operands.push(temp);
				temp = "";
			}
		}
		else  if (cur == '(' || cur == '{' || cur == '[')
			operators.push(cur);
		else if (cur == ')')
		{
			char prev = operators.stackTop();
			while (prev != '(')
			{
				prev = operators.pop();
				string op2 = operands.pop();
				string op1 = operands.pop();
				string str = prev + op1 + op2;
				operands.push(str);
				prev = operators.stackTop();
			}
			operators.pop();
		}
		else if (cur == '}')
		{
			char prev = operators.stackTop();
			while (prev != '{')
			{
				prev = operators.pop();
				string op2 = operands.pop();
				string op1 = operands.pop();
				string str = prev + op1 + op2;
				operands.push(str);
				prev = operators.stackTop();
			}
			operators.pop();
		}
		else if (cur == ']')
		{
			char prev = operators.stackTop();
			while (prev != '[')
			{
				prev = operators.pop();
				string op2 = operands.pop();
				string op1 = operands.pop();
				//char oprtr = operators.pop();
				string str = prev + op1 + op2;
				operands.push(str);
				prev = operators.stackTop();
			}
			operators.pop();
		}
		else
		{
			if (operators.isEmpty())
				operators.push(cur);
			else
			{
				char prev = operators.stackTop();
				while (prev != '(' && prev != '{' && prev != '[' && precedenceOpr(cur) <= precedenceOpr(prev))
				{
					prev = operators.pop();
					string op2 = operands.pop();
					string op1 = operands.pop();
					string str = prev + op1 + op2;
					operands.push(str);
					if (operators.isEmpty())
						break;
					prev = operators.stackTop();
				}
				operators.push(cur);
			}
		}
	}
	while (!operators.isEmpty())
	{
		string op2 = operands.pop();
		string op1 = operands.pop();
		char oprtr = operators.pop();
		string str = oprtr + op1 + op2;
		operands.push(str);
	}
	return operands.pop();
}

string usingOneStack(string infix)
{
	int N = infix.length();
	string prefix;
	Stack<char> operators;
	int indP = 0;
	string str;
	for (int i = N-1; i >=0 ; i--)
	{
		char temp = infix[i];
		if (temp == ' ')
			continue;
		if (temp >= '0' && temp <= '9' || temp == '.')
		{
			if (i == 0)
			{
				str = temp + str;
				str += ',';
				prefix = str + prefix;
				str = "";
			}
			else
			{
				char next = infix[i - 1];
				str = temp + str;
				if (!(next >= '0' && next <= '9' || next == '.'))
				{
					str += ',';
					prefix = str + prefix;
					str = "";
				}
			}
		}
		else if (temp == ')' || temp == '}' || temp == ']')
			operators.push(temp);
		else if (temp == '(')
		{
			char prev = operators.stackTop();
			while (prev != ')')
			{
				prev = operators.pop();
				prefix = prev + prefix;
				prev = operators.stackTop();
			}
			operators.pop();
		}
		else if (temp == '{')
		{
			char prev = operators.stackTop();
			while (prev != '}')
			{
				prev = operators.pop();
				prefix = prev + prefix;
				prev = operators.stackTop();
			}
			operators.pop();
		}
		else if (temp == '[')
		{
			char prev = operators.stackTop();
			while (prev != ']')
			{
				prev = operators.pop();
				prefix = prev + prefix;
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
				while (prev != ')' && prev != '}' && prev != ']' && precedenceOpr(temp) <= precedenceOpr(prev))
				{
					prev = operators.pop();
					prefix = prev + prefix;
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
		prefix = operators.pop() + prefix;
	}
	return prefix;
}

double prefixEvaluate(string prefix)
{
	Stack<double> result;
	int N = prefix.length();
	double num = 0, mul = 10;
	string str;
	for (int i = N-1; i >= 0 ; i--)
	{
		char temp = prefix[i];
		if (temp == ',')
		{
			str = "";
			num = 0;
			mul = 10;
		}
		else if (temp >= '0' && temp <= '9' || temp == '.')
		{
			str = temp + str;
			char next = prefix[i - 1];
			if (!(next >= '0' && next <= '9' || next == '.'))
			{
				int l = str.length();
				for (int j = 0; j < l; j++)
				{
					if (str[j] == '.')
					{
						mul = 0.1;
					}
					else
					{
						if (mul == 10)
						{
							num *= 10;
							num += (str[j] - (double)'0');
						}
						else
						{
							num += ((str[j] - (double)'0') * mul);
							mul *= 0.1;
						}
					}
				}
				result.push(num);
			}
		}
		else
		{
			double o1 = result.pop();
			double o2 = result.pop();
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
	string str("11/2*6-7.5+3/4/(0+0.07)");
	cout << usingTwoStacks(str) << "\n";
	string str2 = usingOneStack(str);
	cout << str2 << "\n";
	cout << prefixEvaluate(str2) << "\n";
	return 0;
}