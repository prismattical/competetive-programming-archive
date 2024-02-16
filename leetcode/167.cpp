#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
	int left = 0;
	int right = numbers.size() - 1;
	while (true)
	{
		int remainder = (numbers[right] + numbers[left]) - target;
		if (remainder == 0)
		{
			return { left + 1, right + 1 };
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
	return { 0, 0 };
}
