#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
	vector<int> stack;
	for (string tok : tokens)
	{
		if (tok == "+")
		{
			int right = stack.back();
			stack.pop_back();
			int left = stack.back();
			stack.pop_back();
			stack.push_back(left + right);
		} else if (tok == "-")
		{
			int right = stack.back();
			stack.pop_back();
			int left = stack.back();
			stack.pop_back();
			stack.push_back(left - right);
		} else if (tok == "*")
		{
			int right = stack.back();
			stack.pop_back();
			int left = stack.back();
			stack.pop_back();
			stack.push_back(left * right);
		} else if (tok == "/")
		{
			int right = stack.back();
			stack.pop_back();
			int left = stack.back();
			stack.pop_back();
			stack.push_back(left / right);
		} else
		{
			stack.push_back(stoi(tok));
		}
	}
	return stack.back();
}
