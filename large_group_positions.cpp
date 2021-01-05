#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	vector<vector<int>> largeGroupPositions(string s);
};

int main()
{
	
	string s("aaaaabbbbbbcdeeee");

	Solution test;
	vector<vector<int>> res = test.largeGroupPositions(s);

	for (const auto &i : res)
		cout << i << endl;
}


vector<vector<int>> Solution::largeGroupPositions(string s)
/*做判断的时候考虑状态压缩结构就更清晰、简单
 *vector嵌套还能用列表初始化的方法赋值，学到了
*/ 
{
	vector<vector<int>> res;

	int cnt = 1, len = s.size();

	for (int i = 1; i < len; ++i)
	{
		if (i == len - 1 || s[i] != s[i+1])
		{
			if (cnt >= 3)
			{
				res.push_back({i - cnt + 1, i});	
			}
		}
		else
		{
			++cnt;	
		}

	}
	return res;


}
/*
在一个由小写字母构成的字符串 s 中，包含由一些连续的相同字符所构成的分组。

例如，在字符串 s = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。

分组可以用区间 [start, end] 表示，其中 start 和 end 分别表示该分组的起始和终止位置的下标。上例中的 "xxxx" 分组用区间表示为 [3,6] 。

我们称所有包含大于或等于三个连续字符的分组为 较大分组 。

找到每一个 较大分组 的区间，按起始位置下标递增顺序排序后，返回结果。

 

示例 1：

输入：s = "abbxxxxzzy"
输出：[[3,6]]
解释："xxxx" 是一个起始于 3 且终止于 6 的较大分组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/positions-of-large-groups
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
