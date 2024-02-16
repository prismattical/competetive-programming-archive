#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
	int left = 0;
	int right = s.size() - 1;
	while (left < right)
	{
		while (!isalnum(s[left]))
		{
			++left;
			if (left > s.size() - 1)
			{
				return true;
			}
		}
		while (!isalnum(s[right]))
		{
			--right;
			if (right < 0)
			{
				return true;
			}
		}
		if (tolower(s[left]) != tolower(s[right]))
		{
			return false;
		}

		++left;
		--right;
	}
	return true;
}
