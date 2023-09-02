#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int> &nums)
	{
		const int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			if (nums[abs(nums[i]) - 1] > 0)
			{
				nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
			}
		}
		vector<int> ret;

		for (int i = 0; i < n; ++i)
		{
			if (nums[i] > 0)
			{
				ret.push_back(i + 1);
			}
		}

		return ret;
	}
};

int main()
{
	vector<int> nums{ 4, 3, 2, 7, 8, 2, 3, 1 };

	Solution sol;

	sol.findDisappearedNumbers(nums);

	return 0;
}
