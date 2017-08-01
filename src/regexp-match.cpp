#include <stdio.h>

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == NULL || pattern == NULL)
			return false;
		return matchCore(str, pattern);
	}
	bool matchCore(char* str, char* pattern)
	{
		if (*str == '\0'&&*pattern == '\0')
			return true;
		if (*str != '\0'&&*pattern == '\0')
			return false;
		if (*(pattern + 1) == '*')
		{
			if (*pattern == *str || (*pattern == '.'&&*str != '\0'))
				/*
				matchCore(str,pattern+2):模式串未匹配
				matchCore(str+1,pattern):模式串已经匹配成功，尝试匹配下一个字符串
				matchCore(str+1,pat+2)：模式串已经成功匹配，并且不匹配下一个字符串内容  注意这里 matchCore(str+1,pat+2)重复考虑了（代码中已经去除），谢谢@chlq的指出 
				*/
				return matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
			else
				return matchCore(str, pattern + 2);
		}
		if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
			return matchCore(str + 1, pattern + 1);
		return false;
	}
};
