#include <stdio.h>
#include <string>
using namespace std;

class Solution 
{
public:
	int FirstNotRepeatingChar(string str) 
	{
		if (str.length() == 0)
			return -1;
		unsigned int hashTime[256] = { 0 };  //做一个Hash表，用来统计ASCII码出现次数
		for (int i = 0; i < str.length(); ++i)
			hashTime[str[i]]++;
		for (int i = 0; i < str.length(); ++i)
		{
			if (hashTime[str[i]] == 1)
				return i;
		}
		return -1;
	}
};