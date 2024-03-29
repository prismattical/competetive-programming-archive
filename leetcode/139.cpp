#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
	vector<bool> tab(s.length() + 1, false);
	tab[0] = true;

	for (int index = 0; index < tab.size() - 1; ++index)
	{
		if (!tab[index])
		{
			continue;
		}
		for (const auto &word : wordDict)
		{
			string const chop(s.data() + index,
					  s.data() + min(index + word.length(), s.length()));
			if (word == chop)
			{
				tab[index + word.length()] = true;
			}
		}
	}

	for (auto i : tab)
	{
		cout << i << ' ';
	}
	cout << '\n';

	return tab.back();
}
