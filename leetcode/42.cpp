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
			const int curr = height[left];
			left_max = left_max > curr ? left_max : curr;
			count += left_max - curr;
		} else if (height[right] < left_max)
		{
			--right;
			const int curr = height[right];
			right_max = right_max > curr ? right_max : curr;
			count += right_max - curr;
		}
	}
	return count;
}
