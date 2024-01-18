#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
	static map<int, int> memo{ []() {
		map<int, int> ret;
		ret[0] = 0;
		ret[1] = 1;
		return ret;
	}() };

	if (memo.find(n) != memo.end())
	{
		return memo[n];
	}

	memo[n] = fib(n - 1) + fib(n - 2);
	return memo[n];
}
