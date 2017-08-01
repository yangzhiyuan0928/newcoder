#include <stdio.h>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution
{
public:
	TreeLinkNode* GetNext(TreeLinkNode *pNode)
	{
		if (pNode == NULL)
			return NULL;
		if (pNode->right != NULL)  //��ǰ�ڵ���������������������������ڵ�
		{
			pNode = pNode->right;
			while (pNode->left != NULL)
				pNode = pNode->left;
			return pNode;
		}
		while (pNode->next != NULL)  //��ǰ�ڵ�û������������Ѱ�Ҹýڵ�ĸ��ڵ�����ӽڵ�
		{
			if (pNode->next->left == pNode) //����ýڵ�ĸ��ڵ�����ӽڵ������Ǹýڵ㣬��ֱ�ӷ��ظýڵ�ĸ��ڵ�
				return pNode->next;
			pNode = pNode->next;
		}
		return NULL;
	}
};