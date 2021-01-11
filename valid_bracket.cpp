#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool valid_bracket(string s);

};

int main()
{
	string s = ("[]");	
	Solution test;

	bool res = test.valid_bracket(s);

	//if (test.valid_bracket(s))
	if (res)
	{
		cout << "true!" << endl;
	}
	else
	{
		cout << "false" << endl;	
	}


}

bool Solution::valid_bracket(string s)
/*栈匹配，不过还是没想到，用的下标做法...看了正规解法才发现栈确实好用啊
*/
{
	int len = s.size();
	if (len%2 ==1 ) { return false; }

	unordered_map<char,char> pair = {
		{')','('},	
		{'}','{'},	
		{'[',']'}	
	};

	stack<char> stk;

	//for (const char& ch: s)
	for (char ch: s)
	{
		if (pair.count(ch))
		{
			if (stk.empty() || stk.top() != pair.at(ch)) { return false;}
			stk.pop();
		}
		else
		{
			stk.push(ch);	
		}
	}
	return stk.empty();
}
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
