#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

/*** 
 * ������stack: ʱ�临�Ӷ�ΪO(2n), �ռ临�Ӷ�ΪO(n)
 **/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		stack<ListNode *> st;
		ListNode* node = pHead;
		while (node != NULL) {
			st.push(node);
			node = node->next;
		}

		ListNode *res;
		for (int i = 0; i < st.size(); ++i) {
			node = st.top();
			st.pop();
			if (i == st.size() - 1)
				node->next = NULL;
			else
				node->next = st.top();
			if (i == 0)
				res = node;
		}
		return res;
	}
};

/***
 * ֱ�ӵ���˳��
 **/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		ListNode* head = pHead;
		ListNode* pre = NULL;
		ListNode* next = NULL;
		while (head != NULL) {
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};
