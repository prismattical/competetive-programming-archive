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
	ListNode *reverseList(ListNode *head)
	{
		ListNode *walker = head;
		ListNode *prev = nullptr;
		while (walker != nullptr)
		{
			ListNode *temp = walker->next;
			walker->next = prev;
			prev = walker;
			walker = temp;
		}
		return prev;
	}
};

int main()
{
}
