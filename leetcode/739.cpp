#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
	vector<int> ret(temperatures.size(), 0);
	vector<pair<int, int> > monstack;
	for (int i = 0; i < temperatures.size(); ++i)
	{
		while (true)
		{
			if (monstack.empty())
			{
				monstack.push_back({ temperatures[i], i });
				break;
			}
			auto last = monstack.back();
			if (last.first < temperatures[i])
			{
				ret[last.second] = i - last.second;
				monstack.pop_back();
			} else
			{
				monstack.push_back({ temperatures[i], i });
				break;
			}
		}
	}
	return ret;
}
