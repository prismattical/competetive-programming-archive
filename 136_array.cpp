#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int> &nums)
	{
		int res = 0;
		for (int num : nums)
		{
			res = res ^ num;
		}

		return res;
	}
};

int main()
{
	vector<int> nums{ 4, 4, 2, 2, 1 };

	Solution sol;

	cout << sol.singleNumber(nums) << '\n';

	return 0;
}
