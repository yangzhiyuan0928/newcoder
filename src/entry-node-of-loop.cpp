#include <stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL) { }
};

/***
 * ͬLeetCode: 
 * (1)�ж��Ƿ�ɻ�������ָ��(fast, slow)ͬʱ����������fast��slow��������ǰ������û�л�����fast��slow�������������л�����fast��slow���ٴ�������
 * (2)Ѱ�һ�����ڣ��������ΪA��������ڵ�ΪB��������ΪC; A->B����Ϊx��B->C����Ϊa�����ĳ���Ϊl; 
 *    ��fast�߹��ľ����Ϊ��fast = x + m*l + a, slow�߹��ľ����Ϊ��slow = x + n*l + a;
 *    ����fast = 2*slow, ���ԣ� x = (n - 2m)l - a, �� x = (n - 2m - 1)l + l - a; ����l-a��Ϊ��C->B�ľ���;
 * ��ˣ���������ָ������A��ʼ��slow��C��ʼ��ͬʱ�ƶ������߱ض�������ڵ�B����
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
			if (slow == fast)  //�����سɻ�
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
 * ����STL�е�set��set��һ�����Ծ��ǲ��ܲ�����ͬԪ��
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