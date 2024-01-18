#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	set<int> memo;
	for (auto i : nums)
	{
		memo.insert(i);
	}
	int k = 1;
	int max_so_far = k;
	auto it = memo.begin();
	int prev = *it;
	++it;
	for (; it != memo.end(); ++it)
	{
		if (*it == prev + 1)
		{
			++k;
			max_so_far = max(k, max_so_far);
		} else if (*it != prev + 1 && *it != prev)
		{
			k = 1;
		}
		prev = *it;
	}
    return max_so_far;
}
