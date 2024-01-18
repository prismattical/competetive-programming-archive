#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		map<int, int> occurences;
		vector<vector<int> > occurences_rev(nums.size() + 1);
		for (auto num : nums)
		{
			++occurences[num];
		}
		for (auto p : occurences)
		{
			occurences_rev[p.second].push_back(p.first);
		}
		vector<int> ret;
		for (int i = occurences_rev.size() - 1; i >= 0; --i)
		{
			for (auto i : occurences_rev[i])
			{
				ret.push_back(i);
				--k;
				if (k == 0)
				{
					goto end;
				}
			}
		}
end:
		return ret;
	}
};

int main()
{
}
