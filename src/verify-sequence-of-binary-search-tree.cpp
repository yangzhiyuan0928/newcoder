#include <cstdio>
#include <vector>
using namespace std;

/***
 * �ж�ĳ�������Ƿ���BST�ĺ������
 **/
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) 
			return false;
		int index = 0; //���������ֽ�
		int root = sequence[sequence.size() - 1];
		int i = 0;
		for (; i < sequence.size() - 1; ++i)
		{
			if (sequence[i] > root) 
				break; 
		}
		for (int j = i; j < sequence.size() - 1; ++j)  //ѭ��ʱȥ��root�����Ϊlen-1
		{
			if (sequence[j] < root) 
				return false; //��һ��С��root���򷵻�false
		}
		vector<int> leftTree, rightTree;
		if (i != 0)
		{
			//����������
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

		bool left = true, right = true; // �����������Ƿ��Ƕ���������
		if (leftTree.size() > 1) 
			VerifySquenceOfBST(leftTree);
		if (rightTree.size() > 1) 
			VerifySquenceOfBST(rightTree);

		return (left && right);
	}
};