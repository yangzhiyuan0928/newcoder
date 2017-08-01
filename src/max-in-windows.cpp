#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		deque<int> s;
		for (unsigned int i = 0; i < num.size(); ++i) {
			while (s.size() && num[s.back()] <= num[i])//�Ӻ������ε��������бȵ�ǰnumֵС��Ԫ�أ�ͬʱҲ�ܱ�֤������Ԫ��Ϊ��ǰ�������ֵ�±�
				s.pop_back();
			while (s.size() && i - s.front() + 1 > size)//����ǰ�����Ƴ�����Ԫ�����ڵ�λ�ã�������Ԫ�������Ӧ��num���ڴ����У���Ҫ����
				s.pop_front();
			s.push_back(i);//��ÿ�λ�����num�±�������
			if (size&&i + 1 >= size)//�����������׵�ַi���ڵ���sizeʱ�ſ�ʼд�봰�����ֵ
				res.push_back(num[s.front()]);
		}
		return res;
	}
};