#include <stdio.h>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		RandomListNode *currNode = pHead;
		while (currNode)
		{
			RandomListNode *node = new RandomListNode(currNode->label);
			node->next = currNode->next;
			currNode->next = node;
			currNode = node->next;
		}
		currNode = pHead;
		while (currNode)
		{
			RandomListNode *node = currNode->next;
			if (currNode->random)
			{
				node->random = currNode->random->next;
			}
			currNode = node->next;
		}
		//²ð·Ö
		RandomListNode *pCloneHead = pHead->next;
		RandomListNode *temp;
		currNode = pHead;
		while (currNode->next)
		{
			temp = currNode->next;
			currNode->next = temp->next;
			currNode = temp;
		}
		return pCloneHead;
	}
};