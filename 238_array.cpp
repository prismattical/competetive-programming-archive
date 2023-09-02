#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int> &nums)
	{
		vector<int> ret(nums.size(), 0);
		ret[0] = 1;
		for (int i = 1; i < ret.size(); ++i)
		{
			ret[i] = nums[i - 1] * ret[i - 1];
		}
		int walker = 1;
		for (int i = ret.size() - 1; i >= 0; --i)
		{
			ret[i] *= walker;
			walker *= nums[i];
		}

        return ret;
	}
};

int main()
{
	vector<int> nums{ 2, 3, 4, 5 };

	Solution sol;

	sol.singleNumber(nums);

	return 0;
}
