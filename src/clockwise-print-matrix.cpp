#include <cstdio>
#include <vector>
using namespace std;

/***
 * 解题思路：顺时针打印就是按圈数循环打印，一圈包含两行或者两列，在打印的时候会出现某一圈中只包含一行或只含一列，
 * 当某圈只含有一行时，要判断从左向右打印和从右向左打印的时候是否会出现重复打印，
 * 同样只包含一列时，要判断从上向下打印和从下向上打印的时候是否会出现重复打印的情况
 */
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>res;
		res.clear();
		int row = matrix.size();  //行数
		int collor = matrix[0].size();//列数
									  //计算打印的圈数
		int circle = ((row < collor ? row : collor) - 1) / 2 + 1;//圈数
		for (int i = 0; i<circle; i++) {			
			for (int j = i; j<collor - i; j++)  //从左向右打印
				res.push_back(matrix[i][j]);
			for (int k = i + 1; k<row - i; k++)  //从上往下的每一列数据 
				res.push_back(matrix[k][collor - 1 - i]);
			for (int m = collor - i - 2; (m >= i) && (row - i - 1 != i); m--)  //判断是否会重复打印(从右向左的每行数据) 
				res.push_back(matrix[row - i - 1][m]);
			for (int n = row - i - 2; (n>i) && (collor - i - 1 != i); n--)  //判断是否会重复打印(从下往上的每一列数据)
				res.push_back(matrix[n][i]);
		}
		return res;
	}
};