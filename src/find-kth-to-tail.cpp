#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL)
			return NULL;
		int len = 0;
		ListNode *tmp;
		for (tmp = pListHead; tmp != NULL; tmp = tmp->next) {
			len++;
		}
		if (k > len)
			return NULL;
		tmp = pListHead;
		for (int i = 0; i < len - k; ++i) {
			tmp = tmp->next;
		}
		return tmp;
	}
};