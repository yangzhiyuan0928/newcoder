/***
 * 分析：n*2可拆成(n-1)*2 + 1*2， (n-2)*2 + 2*2， ....
 * f(1) = 1, f(2) = 2, f(3) = 3, f(4) = 5
 * 类似于Fibnocci
 **/
class Solution {
public:
	int rectCover(int number) {
		if (number <= 1)
			return number;
		int res = 0;
		int fn0 = 1, fn1 = 1;
		for (int i = 1; i < number; i++)
		{
			res = fn1 + fn0;
			fn0 = fn1;
			fn1 = res;
		}
		return res;
	}
};