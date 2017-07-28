/***
 * Ҫ�����n��̨�ף����Դ�n-1��Ҳ�ɴ�n-2�����f(n) = f(n-1) + f(n-2), ��n=1ʱ��ֻ��1�֣���n=2ʱ��f(n)=2
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