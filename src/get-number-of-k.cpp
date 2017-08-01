#include <vector>
#include <stdio.h>
using namespace std;

class Solution
{
public:
	int GetNumberOfK(vector<int> data, int k)
	{
		if (data.empty())
			return 0;
		int res = 0;
		for (int i = 0; i < data.size(); ++i)
		{
			if (data[i] == k)
				res++;
			if (data[i] > k)
				break;
		}
		return res;
	}
};

/***
 * 有序数组查找: 二分查找
 **/
class Solution
{
public:
	int GetNumberOfK(vector<int> data, int k)
	{
		if (data.empty())
			return 0;

		int ind = binaryFind(data, 0, data.size(), k);
		if (ind == -1) 
			return 0;
		int pos = ind;
		int cnt = 1;
		while (--pos >= 0 && k == data[pos]) ++cnt;
		while (++ind < data.size() && k == data[ind]) 
			++cnt;
		return cnt;
	}
private:
	int binaryFind(vector<int> &data, int begin, int end, int k)
	{
		int ndx = -1;
		if (begin >= end)
			return -1;
		int mid = (begin + end) / 2;
		if (k == data[mid])
			return mid;
		if ((ndx = binaryFind(data, begin, mid, k)) != -1)
			return ndx;
		if ((ndx = binaryFind(data, mid + 1, end, k)) != -1)
		{
			return ndx;
		}
		return -1;
	}
};