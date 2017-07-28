#include <iostream>
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
			return 1;
		double res = base;
		int flag = 1;
		if (exponent < 0) {
			exponent = -exponent;
			flag = -1;
		}
		for (int i = 1; i < exponent; ++i) {
			res *= base;
		}
		if (flag < 0) {
			res = 1.0 / res;
		}
		return res;
	}
};