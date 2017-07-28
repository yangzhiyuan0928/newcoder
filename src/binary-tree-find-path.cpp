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
 * �������·��(root-->leaf)�ڵ��ΪexpectNumber������·��
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
	void dfs(TreeNode* root, int s, vector<vector<int>> &ret, vector<int> &trace)  //����ȱ��� 
	{
		if (root == NULL)
			return;
		trace.push_back(root->val);
		if (!root->left && !root->right) {
			if (s == root->val)  //�ݹ��������
				ret.push_back(trace);
		}
		if (root->left)
			dfs(root->left, s - root->val, ret, trace);
		if (root->right)
			dfs(root->right, s - root->val, ret, trace);
		trace.pop_back();
	}
};