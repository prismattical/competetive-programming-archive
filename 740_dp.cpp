#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

int deleteAndEarn(vector<int> &nums)
{
	map<int, int> precalc;
	for (auto i : nums) {
		precalc[i] += i;
	}

	map<int, int> memo;

	memo[precalc.begin()->first] = precalc.begin()->second;
	if (precalc.size() == 1) {
		return memo.begin()->second;
	}

	if ((++precalc.begin())->first - precalc.begin()->first == 1) {
		memo[(++precalc.begin())->first] = (++precalc.begin())->second;
	} else {
		memo[(++precalc.begin())->first] =
			(++precalc.begin())->second + memo.begin()->second;
	}

	if (precalc.size() == 2) {
		return max(memo.begin()->second, (++memo.begin())->second);
	}

	if ((++(++precalc.begin()))->first - (++precalc.begin())->first == 1) {
		memo[(++(++precalc.begin()))->first] =
			(++(++precalc.begin()))->second + memo.begin()->second;
	} else {
		memo[(++(++precalc.begin()))->first] =
			(++(++precalc.begin()))->second +
			max((++memo.begin())->second, memo.begin()->second);
	}

	for (auto it_1 = (++(++(++precalc.begin()))), it_2 = (++(++precalc.begin())),
		  it_3 = (++precalc.begin()), it_4 = precalc.begin();
	     it_1 != precalc.end(); ++it_1, ++it_2, ++it_3, ++it_4) {
		if (it_1->first - it_2->first == 1) {
			memo[it_1->first] =
				it_1->second + max(memo[it_3->first], memo[it_4->first]);
		} else {
			memo[it_1->first] =
				it_1->second + max(memo[it_2->first], memo[it_3->first]);
		}
	}

	return max((--memo.end())->second, (--(--memo.end()))->second);
}

int main()
{
	// vector<int> n = { 2, 7, 9, 3, 1 };
	vector<int> n = { 1, 2, 3, 1 };

	std::cout << deleteAndEarn(n);

	return 0;
}
