#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
	int ret = 0;
	vector<pair<int, int> > monstack;
	for (int i = 0; i < heights.size(); ++i)
	{
		while (true)
		{
			if (monstack.empty())
			{
				monstack.push_back({ heights[i], i });
				break;
			}

			auto b = monstack.back();
			if (heights[i] < b.first)
			{
				int temp;
				if (monstack.size() == 1)
				{
					temp = b.first * (i);
				} else
				{
					int x = b.second - monstack[monstack.size() - 2].second - 1;
					temp = b.first * (i - b.second + x);
				}
				monstack.pop_back();
				if (temp > ret)
				{
					ret = temp;
				}
				continue;
			}

			monstack.push_back({ heights[i], i });
			break;
		}
	}
	{
		int temp = (monstack.back().second + 1) * monstack[0].first;
		if (temp > ret)
		{
			ret = temp;
		}
		cout << monstack[0].first << ' ' << monstack[0].second << '\t';
	}

	for (int i = 1; i < monstack.size(); ++i)
	{
		int x = monstack[i].second - monstack[i - 1].second - 1;
		int temp =
			(monstack.back().second - monstack[i].second + 1 + x) * monstack[i].first;
		if (temp > ret)
		{
			ret = temp;
		}
		cout << monstack[i].first << ' ' << monstack[i].second << '\t';
	}
	cout << '\n';
	return ret;
}
