#include <stdio.h>
#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
	string LeftRotateString(string str, int n)
	{
		int len = str.length();
		if (len <= 1)
			return str;
		if (n > len)
			n = n%len;
		queue<char> que;
		for (int i = 0; i < n; ++i)
		{
			que.push(str[i]);
		}
		string res(str.begin() + n, str.end());
		while (!que.empty())
		{
			res.push_back(que.front());
			que.pop();
		}
		return res;
	}
};