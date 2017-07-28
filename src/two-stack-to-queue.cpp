#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
	void push(int node) {
		int sz = stack2.size();
		for (int i = 0; i < sz; ++i)
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		stack1.push(node);
	}

	int pop() {
		int sz = stack1.size();
		for (int i = 0; i < sz; ++i)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int res = stack2.top();
		stack2.pop();
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
