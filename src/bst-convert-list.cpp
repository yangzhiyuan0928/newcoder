#include <stdio.h>
#include <stack>
#include <vector>
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
 * BST TravIn
 **/
//迭代版本
class Solution
{
public:
	TreeNode *Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		stack<TreeNode *> st;
		TreeNode *p = pRootOfTree;
		TreeNode *pre = NULL;  //用于保存中序遍历中的上一个节点
		bool isFirst = true; 
		while (p != NULL || !st.empty())
		{
			while (p != NULL)
			{
				st.push(p);
				p = p->left;
			}
			p = st.top();
			st.pop();
			if (isFirst)
			{
				pRootOfTree = p;  //将中序遍历中第一个节点记为root
				pre = pRootOfTree;
				isFirst = false;
			}
			else
			{
				pre->right = p;
				p->left = pre;
				pre = p;
			}
			p = p->right;
		}
		return pRootOfTree;
	}
};

//递归版本
class Solution
{
public:
	TreeNode *Convert(TreeNode* pRootOfTree)
	{
		ConvertSub(pRootOfTree);
		return realhead;
	}
private:
	TreeNode *head = NULL;
	TreeNode *realhead = NULL;
	void ConvertSub(TreeNode *root)
	{
		if (root == NULL)
			return;
		ConvertSub(root->left);
		if (head == NULL)
		{
			head = root;
			realhead = root;
		}
		else
		{
			head->right = root;
			root->left = head;
			head = root;
		}
		ConvertSub(root->right);
	}
};
