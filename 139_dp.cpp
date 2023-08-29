#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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
			for (auto word : wordDict)
			{
				string chop(s.data() + index,
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
};

int main()
{
	string s = "catsandog";
	vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };

	Solution sol;

	sol.wordBreak(s, wordDict);

	return 0;
}
