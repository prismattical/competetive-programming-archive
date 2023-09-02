#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle)
{
	for (int i = 1; i < triangle.size(); ++i)
	{
		triangle[i][0] += triangle[i - 1][0];
		triangle[i].back() += triangle[i - 1].back();
	}

	for (int i = 1; i < triangle.size(); ++i)
	{
		for (int j = 1; j < triangle[i].size() - 1; ++j)
		{
			triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
	}
	return min_element(triangle.back().begin(), triangle.back().end()).operator*();
}

int main()
{
	vector<vector<vector<int> > > tcases;
	tcases.push_back({ { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } });
	tcases.push_back({ { -10 } });

	for (int t = 0; t < tcases.size(); ++t)
	{
		cout << minimumTotal(tcases[t]) << '\n';
	}

	return 0;
}
