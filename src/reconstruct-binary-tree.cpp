#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int inLen = vin.size();
		if (inLen == 0)
			return NULL;
		vector<int> pre_left, pre_right, vin_left, vin_right;
		TreeNode* root = new TreeNode(pre[0]);

		int gen = 0;
		for (int i = 0; i < vin.size(); ++i)
		{
			if (vin[i] == pre[0])
			{
				gen = i;
				break;
			}
		}

		for (int i = 0; i < gen; ++i)
		{
			vin_left.push_back(vin[i]);
			pre_left.push_back(pre[i + 1]);
		}

		for (int j = gen + 1; j < vin.size(); ++j)
		{
			vin_right.push_back(vin[j]);
			pre_right.push_back(pre[j]);
		}
		root->left = reConstructBinaryTree(pre_left, vin_left);
		root->right = reConstructBinaryTree(pre_right, vin_right);
		return root;
	}
};