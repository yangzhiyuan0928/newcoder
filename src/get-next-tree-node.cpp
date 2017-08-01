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
		if (pNode->right != NULL)  //当前节点有右子树，则找右子树的最左节点
		{
			pNode = pNode->right;
			while (pNode->left != NULL)
				pNode = pNode->left;
			return pNode;
		}
		while (pNode->next != NULL)  //当前节点没有右子树，则寻找该节点的父节点的左孩子节点
		{
			if (pNode->next->left == pNode) //如果该节点的父节点的左孩子节点正好是该节点，则直接返回该节点的父节点
				return pNode->next;
			pNode = pNode->next;
		}
		return NULL;
	}
};