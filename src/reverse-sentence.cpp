#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
	string ReverseSentence(string str)
	{
		int len = str.length();
		if (len <= 1)
			return str;
		int curblankpos = 0, preblankpos = 0;
		string res;
		stack<string> st;
		while (curblankpos >= 0)
		{
			curblankpos = str.find_first_of(' ', preblankpos);
			res = str.substr(preblankpos, curblankpos < 0 ? (str.length() - preblankpos) : curblankpos - preblankpos);
			preblankpos = curblankpos + 1;
			st.push(res);
		}
		res.clear();
		while (!st.empty())
		{
			res += st.top();
			st.pop();
			if (!st.empty())
				res += " ";
		}
		return res;
	}
};