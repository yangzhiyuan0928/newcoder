#include <vector>
using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		if (len <= 1)
			return A;
		vector<int> res;
		for (int i = 0; i < len; ++i)
		{
			int val = 1;
			for (int j = 0; j < len; j++)
			{
				if (j != i)
					val *= A[j];
			}
			res.push_back(val);
		}
		return res;
	}
};