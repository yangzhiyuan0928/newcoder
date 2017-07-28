#include <cstdio>
#include <vector>
using namespace std;

/***
 * ����˼·��˳ʱ���ӡ���ǰ�Ȧ��ѭ����ӡ��һȦ�������л������У��ڴ�ӡ��ʱ������ĳһȦ��ֻ����һ�л�ֻ��һ�У�
 * ��ĳȦֻ����һ��ʱ��Ҫ�жϴ������Ҵ�ӡ�ʹ��������ӡ��ʱ���Ƿ������ظ���ӡ��
 * ͬ��ֻ����һ��ʱ��Ҫ�жϴ������´�ӡ�ʹ������ϴ�ӡ��ʱ���Ƿ������ظ���ӡ�����
 */
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>res;
		res.clear();
		int row = matrix.size();  //����
		int collor = matrix[0].size();//����
									  //�����ӡ��Ȧ��
		int circle = ((row < collor ? row : collor) - 1) / 2 + 1;//Ȧ��
		for (int i = 0; i<circle; i++) {			
			for (int j = i; j<collor - i; j++)  //�������Ҵ�ӡ
				res.push_back(matrix[i][j]);
			for (int k = i + 1; k<row - i; k++)  //�������µ�ÿһ������ 
				res.push_back(matrix[k][collor - 1 - i]);
			for (int m = collor - i - 2; (m >= i) && (row - i - 1 != i); m--)  //�ж��Ƿ���ظ���ӡ(���������ÿ������) 
				res.push_back(matrix[row - i - 1][m]);
			for (int n = row - i - 2; (n>i) && (collor - i - 1 != i); n--)  //�ж��Ƿ���ظ���ӡ(�������ϵ�ÿһ������)
				res.push_back(matrix[n][i]);
		}
		return res;
	}
};