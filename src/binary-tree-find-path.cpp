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

/***
 * 输出满足路径(root-->leaf)节点和为expectNumber的所有路径
 **/
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> ret;
		vector<int> trace;
		if (root)
			dfs(root, expectNumber, ret, trace);
		return ret;
	}
private:
	void dfs(TreeNode* root, int s, vector<vector<int>> &ret, vector<int> &trace)  //树深度遍历 
	{
		if (root == NULL)
			return;
		trace.push_back(root->val);
		if (!root->left && !root->right) {
			if (s == root->val)  //递归结束条件
				ret.push_back(trace);
		}
		if (root->left)
			dfs(root->left, s - root->val, ret, trace);
		if (root->right)
			dfs(root->right, s - root->val, ret, trace);
		trace.pop_back();
	}
};