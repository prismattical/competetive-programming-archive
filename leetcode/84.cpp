#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
	vector<pair<int, int> > monstack;
	heights.push_back(0);
	int ret = 0;
	for (int i = 0; i < heights.size(); ++i)
	{
		while (true)
		{
			if (monstack.empty())
			{
				monstack.push_back({ heights[i], 0 });
				if (i != 0)
				{
					monstack.push_back({ heights[i], i });
				}
				break;
			}
			auto b = monstack.back();
			if (b.first > heights[i])
			{
				int temp = b.first * (i - b.second);
				ret = max(ret, temp);
				monstack.pop_back();
				continue;
			}
			if (b.second + 1 != i)
			{
				monstack.push_back({ heights[i], b.second + 1 });
			}
			monstack.push_back({ heights[i], i });
			break;
		}
	}
	return ret;
}
