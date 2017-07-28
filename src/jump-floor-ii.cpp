/***
 * f(1) = 1, f(2) = 2, f(3) = 4, f(4) = 8;
 * µü´ú¹«Ê½£ºf(n) = 1 + f(1) + ... + f(n-1) n>1
 **/
class Solution {
public:
	int jumpFloor(int number) {
		if (number <= 1)
			return number;
		int res = 0;
		for (int i = 1; i < number; ++i)
		{
			res += jumpFloor(i);  //µÝ¹é
		}
		return res + 1;
	}
};