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
				matchCore(str,pattern+2):ģʽ��δƥ��
				matchCore(str+1,pattern):ģʽ���Ѿ�ƥ��ɹ�������ƥ����һ���ַ���
				matchCore(str+1,pat+2)��ģʽ���Ѿ��ɹ�ƥ�䣬���Ҳ�ƥ����һ���ַ�������  ע������ matchCore(str+1,pat+2)�ظ������ˣ��������Ѿ�ȥ������лл@chlq��ָ�� 
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
