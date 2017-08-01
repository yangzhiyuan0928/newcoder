#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/***
 * 先将数组排序，若存在这样的数，则一定是排序数组中中间的那个数: O(NlogN)
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

		//若num出现次数大于len/2，则下面循环执行完成后，num即为要输出的结果，否则num为数组中任意数
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