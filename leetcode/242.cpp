#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
	{
		return false;
	}
	map<char, int> m;
	for (const char i : s)
	{
		m[i]++;
	}

	for (const char i : t)
	{
		if (m.find(i) != m.end() && m[i] > 0)
		{
			m[i]--;
		} else
		{
			return false;
		}
	}
	return true;
}
