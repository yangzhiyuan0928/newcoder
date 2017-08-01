#include <vector>
using namespace std;

class Solution 
{
public:
	int FindGreatestSumOfSubArray(vector<int> array) 
	{
		if (array.size() <= 0)
			return 0;
		int cur, res;
		cur = array[0];  //当前子向量的和
		res = cur;
		for (int i = 1; i < array.size(); i++)
		{
			if (cur < 0)
				cur = 0;
			cur = cur + array[i];
			if (cur > res)
				res = cur;
		}
		return res;
	}
};