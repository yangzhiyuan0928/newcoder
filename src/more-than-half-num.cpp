#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/***
 * �Ƚ���������������������������һ���������������м���Ǹ���: O(NlogN)
 **/
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.size() == 0)
			return 0;
		sort(numbers.begin(), numbers.end());
		int mid = numbers[numbers.size() / 2];

		int cnt = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == mid)
				cnt++;
		}
		return (cnt > numbers.size() / 2) ? mid : 0;
	}
};

/***
 * O(n)
 **/
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		int len = numbers.size();
		if (len == 0)
			return 0;

		//��num���ִ�������len/2��������ѭ��ִ����ɺ�num��ΪҪ����Ľ��������numΪ������������
		int num = numbers[0], count = 1;
		for (int i = 1; i < len; ++i)
		{
			if (numbers[i] == num)
				count++;
			else
				count--;
			if (count == 0)
			{
				num = numbers[i];
				count = 1;
			}
		}

		//verfying
		count = 0;
		for (int i = 0; i < len; ++i)
		{
			if (numbers[i] == num)
				count++;
		}
		return (count * 2 > len) ? num : 0;
	}
};