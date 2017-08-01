#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
	{
		if (data.size() <= 0)
			return ;
		sort(data.begin(), data.end());
		vector<int> res;
		if (data[0] != data[1])
			res.push_back(0);
		for (int i = 1; i < data.size()-1; ++i)
		{
			if (data[i] > data[i - 1] && data[i] < data[i + 1])
			{
				res.push_back(i);
				if (res.size() > 1)
					break;
			}
		}
		if (data[data.size() - 2] != data[data.size() - 1])
			res.push_back(data.size() - 1);
		*num1 = data[res[0]];
		*num2 = data[res[1]];
	}
};
