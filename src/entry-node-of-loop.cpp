#include <stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL) { }
};

/***
 * 同LeetCode: 
 * (1)判定是否成环：两个指针(fast, slow)同时从起点出发，fast以slow的两倍速前进，若没有环，则fast和slow不会相遇；若有环，则fast与slow必再次相遇；
 * (2)寻找环的入口：假设起点为A，环的入口点为B，相遇点为C; A->B距离为x，B->C距离为a，环的长度为l; 
 *    则fast走过的距离记为，fast = x + m*l + a, slow走过的距离记为，slow = x + n*l + a;
 *    再由fast = 2*slow, 所以， x = (n - 2m)l - a, 即 x = (n - 2m - 1)l + l - a; 其中l-a即为从C->B的距离;
 * 因此：当第三个指针从起点A开始，slow从C开始，同时移动，二者必定会在入口点B相遇
 **/
class Solution
{
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return NULL;
		ListNode *fast = pHead;
		ListNode *slow = pHead;
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)  //相遇必成环
			{
				ListNode *third = pHead;
				while (third != slow)
				{
					third = third->next;
					slow = slow->next;
				}
				if (third == slow)
					return third;
			}
		}
		return NULL;
	}
};

/***
 * 利用STL中的set，set有一个特性就是不能插入相同元素
 **/
#include <set>

class Solution
{
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		set<ListNode*> s;
		ListNode *node = pHead;
		while (node != NULL)
		{
			if (s.insert(node).second)  //pair
				node = node->next;
			else
				return node;
		}
		return node;
	}
};