#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
	std::unordered_map<int, int> m;

	{
		std::stack<int> monstack;
		for (int i = nums2.size() - 1; i >= 0; --i)
		{
			const int n = nums2[i];
			while (!monstack.empty() && n > monstack.top())
			{
				monstack.pop();
			}

			if (monstack.empty())
			{
				m[n] = -1;
			} else
			{
				m[n] = monstack.top();
			}

			monstack.push(n);
		}
	}

	vector<int> ret(nums1.size());
	for (int i = 0; i < nums1.size(); ++i)
	{
		ret[i] = m[nums1[i]];
	}
	return ret;
}
