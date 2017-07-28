#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		ListNode *node;
		for (node = head; node != NULL; node = node->next)
		{
			res.push_back(node->val);
		}
		vector<int> ret;
		for (int i = res.size() - 1; i >= 0; i--) {
			ret.push_back(res[i]);
		}
		return ret;
	}
};