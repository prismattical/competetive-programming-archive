#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &grid)
{
	if (grid[0][0] == 1) {
		return 0;
	}

	for (int i = 0, ways = 1; i < grid.size(); ++i) {
		if (grid[i][0] == 1) {
			ways = 0;
		}
		grid[i][0] = ways;
	}
	grid[0][0] = 0;
	for (int j = 0, ways = 1; j < grid[0].size(); ++j) {
		if (grid[0][j] == 1) {
			ways = 0;
		}
		grid[0][j] = ways;
	}

	for (int i = 1; i < grid.size(); ++i) {
		for (int j = 1; j < grid[i].size(); ++j) {
			if (grid[i][j] == 1) {
				grid[i][j] = 0;
			} else {
				grid[i][j] += grid[i - 1][j] + grid[i][j - 1];
			}
		}
	}
	return grid.back().back();
}

int main()
{
	// vector<vector<int> > matrix = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
	// vector<vector<int> > matrix = { { 0, 1 }, { 0, 0 } };
	vector<vector<int> > matrix = { { 1 } };

	cout << uniquePathsWithObstacles(matrix) << '\n';

	return 0;
}
