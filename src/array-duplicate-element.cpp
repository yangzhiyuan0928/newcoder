/***
 * brute force
 **/
class Solution 
{
public:
	bool duplicate(int numbers[], int length, int *duplication)
	{
		if (length <= 1)
			return false;
		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length; j++)
			{
				if (numbers[i] == numbers[j])
				{
					*duplication = numbers[i];
					return true;
				}
			}
		}
		return false;
	}
};

/***
 * 构造辅助数组
 **/
class Solution
{
public:
	bool duplicate(int numbers[], int length, int *duplication)
	{
		if (length <= 1 || numbers[length - 1] > length - 1)
			return false;
		bool *flag = new bool[length];
		for (int i = 0; i < length; ++i)
		{
			if (flag[numbers[i]] == true)
			{
				duplication[0] = numbers[i];
				return true;
			}
			flag[numbers[i]] = true;
		}
		return false;
	}
};