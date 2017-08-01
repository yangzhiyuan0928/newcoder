#include <stdio.h>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		 val(x), left(NULL), right(NULL) {}
};

/***
 * 二叉树是否对称，只要采用前序、中序、后序、层次遍历等任何一种遍历方法，分为先左后右和先
 * 右后左两种方法，只要两次结果相等就说明这棵树是一颗对称二叉树
 * 迭代版本
 **/
class Solution
{
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		queue<TreeNode *> q1, q2;
		TreeNode *left, *right;
		q1.push(pRoot->left);
		q2.push(pRoot->right);
		while (!q1.empty() && !q2.empty())
		{
			left = q1.front();
			q1.pop();
			right = q2.front();
			q2.pop();
			if (NULL == left && NULL == right)
				continue;
			if (NULL == left || NULL == right)
				return false;
			if (left->val != right->val)
				return false;
			q1.push(left->left);
			q1.push(left->right);
			q2.push(right->right);
			q2.push(right->left);
		}
		return true;
	}
};
