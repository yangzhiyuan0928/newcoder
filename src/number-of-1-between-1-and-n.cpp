#include <stdio.h>
#include <math.h>
/***
 * brute force
 **/
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		for (int i = 0; i <= n; i++) {
			int temp = i;
			//如果temp的任意位为1则count++
			while (temp) {
				if (temp % 10 == 1) {
					count++;
				}
				temp /= 10;
			}
		}
		return count;
	}
};

/***
 * number of X between 1 and N, X [1, 9]
 **/
int NumberOfXBetween1AndN_Solution(int n, int x)
{
	if (n < 0 || x < 1 || x>9)
		return 0;
	int high, low, curr, tmp, i = 1;
	high = n;
	int total = 0;
	while (high != 0)
	{
		high = n / (int)pow(10, i);
		tmp = n % (int)pow(10, i);
		curr = tmp / (int)pow(10, i - 1);
		low = tmp % (int)pow(10, i - 1);
		if (curr == x) 
		{
			total += high*(int)pow(10, i - 1) + low + 1;
		}
		else if (curr < x)
		{
			total += high*(int)pow(10, i - 1);
		}
		else 
		{
			total += (high + 1)*(int)pow(10, i - 1);
		}
		i++;
	}
	return total;
}
