#include <vector>
using namespace std;

/***
 * ¶ş·Ö²éÕÒ
 **/

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
		int mid = -1;
		while (rotateArray[left] >= rotateArray[right])
		{
			if (right - left == 1)
			{
				mid = right;
				break;
			}
			mid = left + (right - left) / 2;
			if (rotateArray[mid] >= rotateArray[left])
				left = mid;
			if (rotateArray[mid] <= rotateArray[right])
				right = mid;
		}
		return rotateArray[mid];
	}
};