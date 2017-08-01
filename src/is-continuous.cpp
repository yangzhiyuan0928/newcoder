﻿#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers)
	{
		int len = numbers.size();
		if (len < 5)
			return false;
		sort(numbers.begin(), numbers.end());
		int jokers = 0;//计算王的数目 
		for (int i = 0; i < 5 && numbers[i] == 0; i++)
		{
			jokers++;
		}
		if (jokers > 4)
			return false;

		for (int i = jokers + 1; i < 5; i++)
		{
			if (numbers[i] == numbers[i - 1])//判断对子的存在 
				return false;
		}
		int dis = numbers[4] - numbers[jokers];  //numbers[jokers]为第一张不为jokers的牌
		if (dis <= 4)
			return true;
		return false;
	}
};