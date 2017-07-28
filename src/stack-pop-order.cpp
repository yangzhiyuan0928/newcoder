#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
	{
		if (pushV.size() == 0)
			return false;
		vector<int> stack;  //ʹ��vector��ģ��stack
		for (int i = 0, j = 0; i < pushV.size();)
		{
			stack.push_back(pushV[i++]);  //������ջ����Ԫ����ջ
			while (j < popV.size() && stack.back() == popV[j])  //�Ƚ�ջ����Ԫ�����ջ�����е�Ԫ��
			{
				stack.pop_back();
				j++;
			}
		}
		return stack.empty();
	}
};