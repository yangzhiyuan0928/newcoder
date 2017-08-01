#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

/***
 * brute force
 **/
class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		int rowlen = array.size();
		if (rowlen == 0)
			return false;
		for (int i = 0; i < rowlen; i++)
		{
			for (int j = 0; j < array[i].size(); j++)
				if (array[i][j] == target)
					return true;
		}
		return false;
	}
};

/***
 * 为避免分叉(不从左上角开始查找的原因)，从左下角开始查找，大于则往右，小于则往上.
 **/
class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		int rowlen = array.size();
		if (rowlen == 0)
			return false;
		int collen = array[0].size();
		if (collen == 0)
			return false;
		int i = rowlen - 1;  //从左下角依次比较
		int j = 0;
		while (i >= 0 && j < collen)  //取&&，而非||
		{
			if (target < array[i][j])
				i--;
			else if (target > array[i][j])
				j++;
			else
				return true;
		}
		return false;
	}
};
