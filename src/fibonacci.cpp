#include <iostream>
using namespace std;

/***
 * ֱ�ӵݹ飺Ч���ܲ�
 **/
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};

/***
 * ֱ�ӵ���
 **/
class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 1)
			return n;
		int fn1 = 0, fn2 = 1;
		int res = fn1 + fn2;
		for (int i = 2; i < n; i++) {
			res = fn1 + fn2;
			fn1 = fn2;
			fn2 = res;
		}
		return res;
	}
};

