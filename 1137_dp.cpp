#include <iostream>

#include <map>

using namespace std;

int tribonacci(int n)
{
	static map<int, int> memo{ []() {
		map<int, int> ret;
		ret[0] = 0;
		ret[1] = 1;
		ret[2] = 1;
		return ret;
	}() };

	if (memo.find(n) != memo.end()) {
		return memo[n];
	}

	memo[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
	return memo[n];
}

int main()
{
	int n;
	std::cin >> n;

	std::cout << tribonacci(n);

	return 0;
}
