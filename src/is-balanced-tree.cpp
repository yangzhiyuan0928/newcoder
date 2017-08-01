#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
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
 * µÝ¹éµ÷ÓÃ
 **/
class Solution {
public:
	int getDepth(TreeNode* t) {
		if (t == NULL)
			return 0;
		int leftDepth = getDepth(t->left);
		int rightDepth = getDepth(t->right);
		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL)
			return true;
		int leftDepth = getDepth(pRoot->left);
		int rightDepth = getDepth(pRoot->right);
		int diffDepth = leftDepth - rightDepth;
		if (diffDepth < -1 || diffDepth > 1) 
		{
			return false;
		}
		else 
		{
			return (IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right));
		}
	}
};