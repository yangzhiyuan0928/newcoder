#include <iostream>
#include <stack>
#include <vector>
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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL || pRoot1 == NULL)
			return false;
		return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}

private:
	bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL)  //pRoot2所有节点都访问完成
			return true;  
		if (pRoot1 == NULL)
			return false;
		return pRoot1->val == pRoot2->val && isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
	}
};