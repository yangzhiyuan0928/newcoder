#include <iostream>
using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int res = 0;
		if (n == 0)
			return 0;
		unsigned int num = 0;
		if (n < 0)
		{
			num = -n; //È¡·´
			num ^= 0xFFFFFFFF;
			num += 1;
		}
		else
			num = n;
		if (num % 2) res = 1;
		while ((num /= 2) != 0)
		{
			res += num % 2;
		}
		return res;
	}
};
