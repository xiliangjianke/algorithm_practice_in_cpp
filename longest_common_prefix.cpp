#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
//可分为横向遍历和纵向遍历，感觉纵向遍历比较的值会数组越界
{
/* 横向遍历
public:
	string longest_common_prefix(vector<string> &s)
	{
		if (!s.size()) { return ""; }
		int len = s.size();

		string pre_str = s[0];

		for (int i = 1; i < len; ++i)
		{
			// 精髓，不断的比较当前遍历元素和上一个元素的公共前缀，并赋值给pre_str为下次比较做准备
			pre_str = longest_common_prefix(pre_str, s[i]);
			if (!pre_str.size()) { break; }
		}

		return pre_str;
	}


	string longest_common_prefix(const string &s1, const string &s2)
	{
		int index = 0, len = min(s1.size(), s2.size());
		
		while (index < len && s1[index] == s2[index])
		{
			++index;	
		}
		return s1.substr(0, index);
	}
*/

public:
	string longest_common_prefix(vector<string> &s)
	{
		if (!s.size()) { return ""; }

		int col = s[0].size();
		int row = s.size();

		for (int i = 0; i < col; ++i)
		{
			char c = s[0][i];
		
			for (int j = 1; j < row; ++j)
			{
				// i==s[j].size()是指当前元素s[j]的长度可能长于s[0]，s[0]比完了就没必要比了，但如果s[0]比s[j]长，s[j][i]就会越界啊，因为 i > s[j].size(),越界的元素为空值，判断还是能成功的
				if (s[j][i] != c || i == s[j].size())
				{
					return s[0].substr(0, i);
				}
			}
		}

	}

};

int main()
{
	vector<string> s = {"flower","flow","flight"};	
	Solution test;

	string res = test.longest_common_prefix(s);

	cout << res << endl;


}
/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
