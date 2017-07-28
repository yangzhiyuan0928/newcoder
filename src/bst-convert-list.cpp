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
//�����汾
class Solution
{
public:
	TreeNode *Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		stack<TreeNode *> st;
		TreeNode *p = pRootOfTree;
		TreeNode *pre = NULL;  //���ڱ�����������е���һ���ڵ�
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
				pRootOfTree = p;  //����������е�һ���ڵ��Ϊroot
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

//�ݹ�汾
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
