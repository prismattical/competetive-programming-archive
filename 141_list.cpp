#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x)
		: val(x)
		, next(NULL)
	{
	}
};

class Solution {
public:
	bool hasCycle(ListNode *head)
	{
		ListNode *fast = head;
		ListNode *slow = head;
		if (fast == NULL || fast->next == NULL)
		{
			return false;
		}
		while (true)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast == NULL)
			{
				return false;
			}
			fast = fast->next;
			if (fast == NULL)
			{
				return false;
			}
			if (fast == slow)
			{
				return true;
			}
		}
	}
};

int main()
{
}
