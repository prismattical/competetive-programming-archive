#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
	static map<int, int> memo{ []() {
		map<int, int> ret;
		ret[1] = 1;
		ret[2] = 2;
		return ret;
	}() };

	if (memo.find(n) != memo.end())
	{
		return memo[n];
	}

	memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
	return memo[n];
}
