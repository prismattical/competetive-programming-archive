#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * @brief 
 * 
 * @details Shamelessly copied from some tutorial video from YouTube
 * This problem is stupid. The "wrong" solution is average O(n^3) with worst O(n^3)
 * The "right" solution is average O(n^2) with worst O(n^3)
 * 
 * @param s 
 * @return string 
 */
string longestPalindrome(string s)
{
	int start = 0;
	int max_len = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		int l = i;
		int r = i;
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			if (r - l + 1 > max_len)
			{
				max_len = r - l + 1;
				start = l;
			}
			--l;
			++r;
		}

		l = i;
		r = i + 1;
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			if (r - l + 1 > max_len)
			{
				max_len = r - l + 1;
				start = l;
			}
			--l;
			++r;
		}
	}
	cout << start << ' ' << max_len << '\n';
	return s.substr(start, max_len);
}

int main()
{
	string inp;
	cin >> inp;
	cout << longestPalindrome(inp) << '\n';
	return 0;
}
