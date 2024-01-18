#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
	if (nums.size() == 1)
	{
		return nums[0];
	}
	if (nums.size() == 2)
	{
		return max(nums[0], nums[1]);
	}
	if (nums.size() == 3)
	{
		return max(nums[0] + nums[2], nums[1]);
	}
	map<int, int> memo;
	memo[0] = nums[0];
	memo[1] = nums[1];
	memo[2] = nums[2] + nums[0];
	for (int i = 3; i < nums.size(); ++i)
	{
		memo[i] = nums[i] + max(memo[i - 2], memo[i - 3]);
	}
	return max(memo[nums.size() - 1], memo[nums.size() - 2]);
}
