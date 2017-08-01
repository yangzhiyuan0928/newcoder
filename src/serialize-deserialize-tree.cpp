#include <stdio.h>
#include <string>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):
		val(x), left(NULL), right(NULL) { }
};

class Solution
{
private:
	void treeToStr(TreeNode *root, string & str)
	{
		if (root == NULL)
		{
			str += '#';
			return ;
		}
		string r = to_string(root->val);  //val to string
		str += r;
		str += ',';
		//ÏÈÐò±éÀú
		treeToStr(root->left, str);
		treeToStr(root->right, str);
	}

	TreeNode *strToTree(char **str)
	{
		if (**str == '#')
		{
			++(*str);
			return NULL;
		}
		int num = 0;
		while (**str != '\0' && **str != ',')
		{
			num = num * 10 + ((**str) - '0');
			++(*str);
		}

		TreeNode *root = new TreeNode(num);
		if (**str == '\0')
			return root;
		else
			(*str)++;

		root->left = strToTree(str);
		root->right = strToTree(str);
		return root;
	}
public:
	char *Serialize(TreeNode *root)
	{
		if (root == NULL)
			return NULL;
		string str;
		treeToStr(root, str);
		char *res = new char[str.length() + 1];
		int i;
		for (i = 0; i < str.length(); i++)
			res[i] = str[i];
		res[i] = '\0';
		return res;
	}

	TreeNode *Deserialize(char *str)
	{
		if (str == NULL)
			return NULL;
		TreeNode *res = strToTree(&str);
		return res;
	}
};
