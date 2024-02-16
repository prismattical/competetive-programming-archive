#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
	int left = 0;
	int right = height.size() - 1;
	int ret = -1;
	while (left < right)
	{
		const int temp = min(height[left], height[right]) * (right - left);
		ret = max(ret, temp);
		if (height[left] > height[right])
		{
			--right;
		} else
		{
			++left;
		}
	}
	return ret;
}
