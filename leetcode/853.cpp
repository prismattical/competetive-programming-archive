#include <bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
	map<int, double> m;
    
	for (int i = 0; i < speed.size(); ++i)
	{
		double t = static_cast<double>(target - position[i]) / speed[i];
		m[position[i]] = t;
	}

	int k = 0;
	double max = -1;

	for (auto it = m.rbegin(); it != m.rend(); ++it)
	{
		if (it->second > max)
		{
			max = it->second;
			++k;
		}
	}

	return k;
}
