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
 * Ϊ����ֲ�(�������Ͻǿ�ʼ���ҵ�ԭ��)�������½ǿ�ʼ���ң����������ң�С��������.
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
		int i = rowlen - 1;  //�����½����αȽ�
		int j = 0;
		while (i >= 0 && j < collen)  //ȡ&&������||
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
