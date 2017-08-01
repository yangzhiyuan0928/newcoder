#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
����������begin��end�ֱ��ʾ���е����ֵ����Сֵ��
���Ƚ�begin��ʼ��Ϊ1��end��ʼ��Ϊ2.
�����begin��end�ĺʹ���s�����Ǿʹ�������ȥ����С��ֵ(������begin),
�෴��ֻ��Ҫ����end��
��ֹ����Ϊ��һֱ����begin��(1+sum)/2����endС��sumΪֹ
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