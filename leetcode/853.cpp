#include <bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
	vector<pair<int, float> > v(speed.size());
	for (int i = 0; i < speed.size(); ++i)
	{
		v[i] = { position[i], static_cast<float>(target - position[i]) / speed[i] };
	}
	sort(v.begin(), v.end());
	vector<float> monstack;
	for (const auto p : v)
	{
		while (true)
		{
			if (monstack.empty())
			{
				monstack.push_back(p.second);
				break;
			}
			const auto b = monstack.back();
			if (p.second > b)
			{
				monstack.pop_back();
				continue;
			}
			monstack.push_back(p.second);
			break;
		}
	}
	return (int)monstack.size();
}
