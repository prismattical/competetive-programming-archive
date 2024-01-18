#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
	vector<char> stack;
	for (char ch : s)
	{
		if (ch == '{' || ch == '(' || ch == '[')
		{
			stack.push_back(ch);
		}
		if (ch == '}' || ch == ')' || ch == ']')
		{
			if (stack.empty())
			{
				return false;
			}
			char ch2 = stack.back();
			stack.pop_back();

			if ((ch2 == '{' && ch == '}') || (ch2 == '(' && ch == ')') ||
			    (ch2 == '[' && ch == ']'))
			{
				continue;
			}
			return false;
		}
	}
	return true;
}
