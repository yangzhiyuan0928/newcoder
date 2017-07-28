/***
 * 要到达第n阶台阶，可以从n-1，也可从n-2到达，即f(n) = f(n-1) + f(n-2), 当n=1时，只有1种，当n=2时，f(n)=2
 **/
class Solution {
public:
	int jumpFloor(int number) {
		if (number <= 1)
			return number;
		int fn0 = 1, fn1 = 1;
		int res;
		for (int i = 1; i < number; i++) {
			res = fn0 + fn1;
			fn0 = fn1;
			fn1 = res;
		}
		return res;
	}
};