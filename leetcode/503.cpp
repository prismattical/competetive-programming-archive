#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
	vector<int> ret(nums.size());
	stack<int> monstack;

	for (int i = 0; i < 2; ++i)
	{
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			const int n = nums[i];
			while (!monstack.empty() && n >= monstack.top())
			{
				monstack.pop();
			}
			if (monstack.empty())
			{
				ret[i] = -1;
			} else
			{
				ret[i] = monstack.top();
			}
			monstack.push(nums[i]);
		}
	}
	return ret;
}
