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
 * �������Ƿ�Գƣ�ֻҪ����ǰ�����򡢺��򡢲�α������κ�һ�ֱ�����������Ϊ������Һ���
 * �Һ������ַ�����ֻҪ���ν����Ⱦ�˵���������һ�ŶԳƶ�����
 * �����汾
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
