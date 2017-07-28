#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		queue<TreeNode *> que;
		que.push(root);
		while (!que.empty())
		{
			TreeNode *x = que.front();
			res.push_back(x->val);
			que.pop();
			if (x->left)
				que.push(x->left);
			if (x->right)
				que.push(x->right);
		}
		return res;
	}
};