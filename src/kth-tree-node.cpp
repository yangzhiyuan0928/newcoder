#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) { }
};

/***
 * 思路一:依次将二叉树所有节点放置到vector中，对vector中所有节点按照val值进行排序，输出kth
 **/
class Solution
{
private:
	bool compare(TreeNode *nd1, TreeNode *nd2)
	{
		return nd1->val < nd2->val;
	}
public:
	TreeNode* KthNode(TreeNode *pRoot, int k)
	{
		if (pRoot == NULL)
			return NULL;
		vector<TreeNode *> vec;
		queue<TreeNode *> que;
		if (pRoot != NULL)  //二叉树层次遍历
			que.push(pRoot);
		while (!que.empty())
		{
			TreeNode *node = que.front();
			que.pop();
			vec.push_back(node);
			que.push(node->left);
			que.push(node->right);
		}
		sort(vec.begin(), vec.end(), compare);
		return vec[k];
	}
};

/***
 * 二叉树中序遍历
 **/
class Solution
{
public:
	TreeNode* KthNode(TreeNode *pRoot, int k)
	{
		if (pRoot == NULL || k == 0)
			return NULL;
		stack<TreeNode *> st;
		int count = 0;
		TreeNode *node = pRoot;
		do
		{
			if (node != NULL)
			{
				st.push(node);
				node = node->left;
			}
			else
			{
				node = st.top();
				st.pop();
				count++;
				if (count == k)
					return node;
				node = node->right;
			}
		} while (node != NULL || !st.empty());
		return NULL;
	}
};

class Solution
{
public:
	TreeNode* KthNode(TreeNode *pRoot, int k)
	{
		if (pRoot == NULL || k == 0)
			return NULL;
		stack<TreeNode *> st;
		int count = 0;
		TreeNode *node = pRoot;
		while (node != NULL || !st.empty())
		{
			while (node != NULL)
			{
				st.push(node);
				node = node->left;
			}
			node = st.top();
			st.pop();
			count++;
			if (count == k)
				return node;
			node = node->right;
		}
		return NULL;
	}
};
