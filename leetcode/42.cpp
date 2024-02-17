#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
	int left = 0;
	int right = height.size() - 1;
	int left_max = height[left];
	int right_max = height[right];
	int count = 0;
	while (left < right)
	{
		if (height[left] <= right_max)
		{
			++left;
			left_max = left_max > height[left] ? left_max : height[left];
			count += left_max - height[left];
		} else if (height[right] < left_max)
		{
			--right;
			right_max = right_max > height[right] ? right_max : height[right];
			count += right_max - height[right];
		}
	}
	return count;
}
