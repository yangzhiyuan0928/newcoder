#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
	{
		if (pushV.size() == 0)
			return false;
		vector<int> stack;  //使用vector来模拟stack
		for (int i = 0, j = 0; i < pushV.size();)
		{
			stack.push_back(pushV[i++]);  //按照入栈序列元素入栈
			while (j < popV.size() && stack.back() == popV[j])  //比较栈顶中元素与出栈序列中的元素
			{
				stack.pop_back();
				j++;
			}
		}
		return stack.empty();
	}
};