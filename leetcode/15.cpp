#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > threeSum(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	set<vector<int> > ret;
	set<int> targets;
	for (int i = 0; i < nums.size(); ++i)
	{
		int target = nums[i];
		if (targets.find(target) != targets.end())
		{
			continue;
		}
		targets.emplace(target);
		int left = 0;
		int right = nums.size() - 1;
		while (left < nums.size() && right > 0 && left < right)
		{
			int remainder = (nums[right] + nums[left]) + target;
			if (right == i)
			{
				--right;
				continue;
			}
			if (left == i)
			{
				++left;
				continue;
			}
			if (remainder == 0)
			{
				vector<int> temp = { nums[left], nums[right], target };
				sort(temp.begin(), temp.end());
				ret.emplace(temp);
				--right;
				++left;
			}
			if (remainder > 0)
			{
				--right;
			}
			if (remainder < 0)
			{
				++left;
			}
		}
	}
	vector<vector<int> > real_ret;
	for (auto &v : ret)
	{
		real_ret.push_back({ v[0], v[1], v[2] });
	}
	return real_ret;
}
