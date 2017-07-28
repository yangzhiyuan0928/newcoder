#include <cstdio>
#include <vector>
using namespace std;

/***
 * 判断某个序列是否是BST的后序遍历
 **/
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) 
			return false;
		int index = 0; //左右子树分解
		int root = sequence[sequence.size() - 1];
		int i = 0;
		for (; i < sequence.size() - 1; ++i)
		{
			if (sequence[i] > root) 
				break; 
		}
		for (int j = i; j < sequence.size() - 1; ++j)  //循环时去除root，因此为len-1
		{
			if (sequence[j] < root) 
				return false; //有一个小于root，则返回false
		}
		vector<int> leftTree, rightTree;
		if (i != 0)
		{
			//即有左子树
			for (int m = 0; m < i; ++m)
			{
				leftTree.push_back(sequence[m]);
			}
		}
		if (i != sequence.size() - 2)
		{
			for (int j = i; j < sequence.size() - 1; ++j)
			{
				rightTree.push_back(sequence[j]);
			}
		}

		bool left = true, right = true; // 看左右子树是否是二叉搜索树
		if (leftTree.size() > 1) 
			VerifySquenceOfBST(leftTree);
		if (rightTree.size() > 1) 
			VerifySquenceOfBST(rightTree);

		return (left && right);
	}
};