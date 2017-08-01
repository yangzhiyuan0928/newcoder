/***
 * ตÝน้
 **/
class Solution
{
public:
	int Sum_Solution(int n)
	{
		if (n <= 1)
			return n;
		int ans = n;
		ans += Sum_Solution(n - 1);
		return ans;
	}
};