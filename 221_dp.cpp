#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char> > &matrix_old)
{
	vector<vector<int> > matrix;
	for (int i = 0; i < matrix_old.size(); ++i)
	{
		matrix.push_back({});
		for (int j = 0; j < matrix_old[i].size(); ++j)
		{
			matrix[i].push_back(matrix_old[i][j] - '0');
		}
	}
	int max_so_far = matrix[0][0];
	for (int i = 1; i < matrix[0].size(); ++i)
	{
		max_so_far = max(max_so_far, matrix[0][i]);
	}

	for (int i = 1; i < matrix.size(); ++i)
	{
		max_so_far = max(max_so_far, matrix[i][0]);
		for (int j = 1; j < matrix[i].size(); ++j)
		{
			if (matrix[i][j] == 1)
			{
				const int min_neigh =
					min(matrix[i][j - 1],
					    min(matrix[i - 1][j], matrix[i - 1][j - 1]));
				matrix[i][j] = min_neigh + 1;

				max_so_far = max(max_so_far, matrix[i][j]);
			}
		}
	}
	return max_so_far * max_so_far;
}

int main()
{
	vector<vector<vector<char> > > tcases;
	tcases.push_back({ { '0' } });
	tcases.push_back({ { '1', '1', '1' }, { '1', '1', '1' }, { '1', '1', '1' } });
	tcases.push_back({ { '1', '1', '1' }, { '1', '1', '1' }, { '0', '1', '1' } });
	tcases.push_back({ { '1', '1' }, { '1', '0' } });

	for (auto &t : tcases)
	{
		cout << maximalSquare(t) << '\n';
	}

	return 0;
}
