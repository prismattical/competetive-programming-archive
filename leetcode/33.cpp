#include <bits/stdc++.h>
using namespace std;

// this is copy-paste from AI
// I was so tired while solving this and I hate binary search so much
// so I just decided to not do it at all

int findRotationPoint(vector<int> &nums)
{
	int left = 0;
	int right = nums.size() - 1;

	if (nums[left] < nums[right])
	{
		return 0; // Not rotated
	}

	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] > nums[right])
		{
			left = mid + 1;
		} else
		{
			right = mid;
		}
	}
	return left;
}

int binarySearch(vector<int> &nums, int target, int left, int right)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
		{
			return mid;
		} else if (nums[mid] < target)
		{
			left = mid + 1;
		} else
		{
			right = mid - 1;
		}
	}
	return -1;
}

int search(vector<int> &nums, int target)
{
	int rotationPoint = findRotationPoint(nums);

	if (nums[rotationPoint] <= target && target <= nums[nums.size() - 1])
	{
		return binarySearch(nums, target, rotationPoint, nums.size() - 1);
	} else
	{
		return binarySearch(nums, target, 0, rotationPoint - 1);
	}
}
