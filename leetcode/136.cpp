#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
	int res = 0;
	for (const int num : nums)
	{
		res = res ^ num;
	}

	return res;
}
