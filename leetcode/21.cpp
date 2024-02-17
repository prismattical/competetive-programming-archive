#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode()
		: val(0)
		, next(nullptr)
	{
	}
	ListNode(int x)
		: val(x)
		, next(nullptr)
	{
	}
	ListNode(int x, ListNode *next)
		: val(x)
		, next(next)
	{
	}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
	if (list1 == nullptr)
	{
		return list2;
	}
	if (list2 == nullptr)
	{
		return list1;
	}
	ListNode dummy = ListNode();

	ListNode *walker = &dummy;
	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			walker->next = list1;
			list1 = list1->next;
		} else
		{
			walker->next = list2;
			list2 = list2->next;
		}
		walker = walker->next;
	}
	walker->next = list1 ? list1 : list2;
	return dummy.next;
}
