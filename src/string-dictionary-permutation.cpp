#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/***
 * �ַ���ȫ�����㷨
 **/

class Solution
{
public:
	vector<string> Permutation(string str)
	{
		vector<string> res;
		if (str.empty())
			return res;
		sort(str.begin(), str.end());
		do {
			res.push_back(str);
		} while (next_permutation(str.begin(), str.end()));
		return res;
	}
};

