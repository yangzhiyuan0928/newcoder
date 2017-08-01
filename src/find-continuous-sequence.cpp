#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
用两个数字begin和end分别表示序列的最大值和最小值，
首先将begin初始化为1，end初始化为2.
如果从begin到end的和大于s，我们就从序列中去掉较小的值(即增大begin),
相反，只需要增大end。
终止条件为：一直增加begin到(1+sum)/2并且end小于sum为止
*/
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum)
	{
		vector<vector<int> > res;
		if (sum < 3) 
			return res;
		int mid = (sum + 1) >> 1;
		int begin = 1;
		int end = 2;
		int cur = begin + end;
		while (begin < mid && end < sum)
		{
			while (cur > sum)
			{
				cur -= begin;
				begin++;
			}
			if (cur == sum)
				InsertRes(begin, end, res);
			end++;
			cur += end;
		}
		return res;
	}
	void InsertRes(int begin, int end, vector<vector<int> > &res)
	{
		vector<int> temp;
		for (int i = begin; i <= end; i++)
			temp.push_back(i);
		res.push_back(temp);
	}
};