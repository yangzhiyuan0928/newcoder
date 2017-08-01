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
 * 若L1与L2有公共节点，设L1的长度为a+n，L2的长度为b+n，假设a<b，其中n表示公共长度，两条链表呈Y型，
 * p1会先到L1的尾部，此时p2走到a+n位置；将p1换成L2的头部，p2再走b+n-(a+n)=b-a到达L2的尾部，此时p1正好到达L2的b-a处，
 * 将p2换成L1的头部，p2再走a+n即可到达L1的尾部，p1再走(b+n)-(b-a)=a+n即可到达L2的尾部；
 * 因此接下来走a步即可到达第一个公共点
 * 时间复杂度为:O(b+n+a)
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
 * 设表1长度n，表2长度m，暴力法嵌套遍历两个链表需要O(mn)的时间复杂度，可以采用hash的思想将其中一个转存为哈希表结构，这样建哈希表时间O(m)，
 * 而遍历链表时间O(n)，而遍历时查找哈希表的时间为O(1)，因此复杂度降为O(m+n)，但需要辅助空间。（这种哈希优化的策略是种一般性的思路，谨记！）
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
		while (pNode2 != NULL)  //把List2转换为hash表
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