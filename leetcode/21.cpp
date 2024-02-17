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
	ListNode *ret = list1;

	ListNode *prev;
	if (list1->val > list2->val)
	{
		ret = list2;
		while (list2 != nullptr && list1->val > list2->val)
		{
			prev = list2;
			list2 = list2->next;
		}
		prev->next = list1;
	}

	while (list1->next != nullptr && list2 != nullptr)
	{
		if (list2->val < list1->next->val)
		{
			auto temp = list2->next;
			list2->next = list1->next;
			list1->next = list2;
			list2 = temp;
		} else
		{
			list1 = list1->next;
		}
	}

	if (list2 != nullptr)
	{
		list1->next = list2;
	}

	return ret;
}
