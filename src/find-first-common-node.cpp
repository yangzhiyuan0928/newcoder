#include <stdio.h>
#include <unordered_set>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};

/***
 * ��L1��L2�й����ڵ㣬��L1�ĳ���Ϊa+n��L2�ĳ���Ϊb+n������a<b������n��ʾ�������ȣ����������Y�ͣ�
 * p1���ȵ�L1��β������ʱp2�ߵ�a+nλ�ã���p1����L2��ͷ����p2����b+n-(a+n)=b-a����L2��β������ʱp1���õ���L2��b-a����
 * ��p2����L1��ͷ����p2����a+n���ɵ���L1��β����p1����(b+n)-(b-a)=a+n���ɵ���L2��β����
 * ��˽�������a�����ɵ����һ��������
 * ʱ�临�Ӷ�Ϊ:O(b+n+a)
 **/
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
		ListNode *p1 = pHead1;
		ListNode *p2 = pHead2;
		while (p1 != p2) 
		{
			p1 = (p1 == NULL ? pHead2 : p1->next);
			p2 = (p2 == NULL ? pHead1 : p2->next);
		}
		return p1;
	}
};

/***
 * ���1����n����2����m��������Ƕ�ױ�������������ҪO(mn)��ʱ�临�Ӷȣ����Բ���hash��˼�뽫����һ��ת��Ϊ��ϣ��ṹ����������ϣ��ʱ��O(m)��
 * ����������ʱ��O(n)��������ʱ���ҹ�ϣ���ʱ��ΪO(1)����˸��ӶȽ�ΪO(m+n)������Ҫ�����ռ䡣�����ֹ�ϣ�Ż��Ĳ�������һ���Ե�˼·�����ǣ���
 **/
class Solution
{
public:
	ListNode* FindFirstCommondNode(ListNode *pHead1, ListNode *pHead2)
	{
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		unordered_multiset<ListNode*> hashset;
		ListNode *pNode1 = pHead1, *pNode2 = pHead2;
		while (pNode2 != NULL)  //��List2ת��Ϊhash��
		{
			hashset.insert(pNode2);
			pNode2 = pNode2->next;
		}
		while (pNode1 != NULL)
		{
			if (hashset.find(pNode1) != hashset.end())
			{
				return pNode1;
			}
			pNode1 = pNode1->next;
		}
		return NULL;
	}
};