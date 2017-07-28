#include <string>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (length == 0)
			return;
		string s;
		for (int i = 0; i < length; ++i)
		{
			if (str[i] == ' ')
			{
				s.push_back('%');
				s.push_back('2');
				s.push_back('0');
			}
			else
				s.push_back(str[i]);
		}
		strcpy(str,s.c_str());		
	}
};