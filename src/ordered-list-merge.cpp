#include <cstdio>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		ListNode dummy = ListNode(0);
		ListNode *node = &dummy;
		ListNode *ln1 = pHead1;
		ListNode *ln2 = pHead2;

		while (ln1 != NULL && ln2 != NULL)
		{
			if (ln1->val < ln2->val)
			{
				node->next = ln1;
				node = node->next;
				ln1 = ln1->next;
			}
			else
			{
				node->next = ln2;
				node = node->next;
				ln2 = ln2->next;
			}
		}
		if (ln1 == NULL)
		{
			node->next = ln2;
		}
		if (ln2 == NULL)
		{
			node->next = ln1;
		}

		return dummy.next;
	}
};