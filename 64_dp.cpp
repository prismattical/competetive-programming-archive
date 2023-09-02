#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int> > &grid)
{
	for (int i = 1; i < grid.size(); ++i)
	{
		grid[i][0] += grid[i - 1][0];
	}
	for (int j = 1; j < grid[0].size(); ++j)
	{
		grid[0][j] += grid[0][j - 1];
	}

	for (int i = 1; i < grid.size(); ++i)
	{
		for (int j = 1; j < grid[i].size(); ++j)
		{
			grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		}
	}
	return grid.back().back();
}

int main()
{
	//vector<vector<int> > matrix = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
	vector<vector<int> > matrix = { { 1, 2, 3 }, { 4, 5, 6 } };

	cout << minPathSum(matrix) << '\n';

	return 0;
}
