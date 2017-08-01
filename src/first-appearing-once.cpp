#include <stdio.h>
#include <queue>
using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		++cnt[ch - '\0'];
		if (cnt[ch - '\0'] == 1)
			data.push(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!data.empty() && cnt[data.front()] >= 2) data.pop();
		if (data.empty()) return '#';
		return data.front();
	}
	Solution()
	{
		memset(cnt, 0, sizeof(cnt));
	}
private:
	queue<char> data;
	unsigned cnt[128];
};