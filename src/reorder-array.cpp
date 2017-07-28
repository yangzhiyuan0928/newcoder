#include <vector>
using namespace std;

/***
 * brute force: 时间复杂度为O(n)，空间复杂度O(n)
 **/
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int len = array.size();
		if (len < 2)
			return;
		vector<int> odd;
		vector<int> event;
		for (int i = 0; i < len; ++i)
		{
			if (array[i] % 2)
				odd.push_back(array[i]);
			else
				event.push_back(array[i]);
		}
		array.clear();
		for (int i = 0; i < odd.size(); ++i)
			array.push_back(odd[i]);
		for (int i = 0; i < event.size(); ++i)
			array.push_back(event[i]);
	}
};

/***
 * 时间复杂度O(n^2)，空间复杂度constanst
 **/
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int len = array.size();
		if (len < 2)
			return;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len - i - 1; j++)
			{
				if (array[j] % 2 == 0 && array[j + 1] % 2 == 1)
				{
					int t = array[j];
					array[j] = array[j + 1];
					array[j + 1] = t;
				}
			}
		}
	}
};

