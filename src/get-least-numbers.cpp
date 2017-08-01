#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int> res;
		int len = input.size();
		if (k > len)
			return res;
		sort(input.begin(), input.end());
		for (int i = 0; i < k; ++i)
		{
			res.push_back(input[i]);
		}
		return res;
	}
};