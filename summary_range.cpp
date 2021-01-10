#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
	vector<string> summary_range(vector<int> &s);
};

int main()
{
	vector<int> ivec = {0,1,2,4,5,7};	
	Solution test;
	vector<string> ret = test.summary_range(ivec);

	for (const auto &i : ret)
		cout << i << endl;


}

vector<string> Solution::summary_range(vector<int> &s)
/*滑动窗口或双指针，来标记需要添加数字区间的首尾下标
 *用while循环可以连续滑动多个元素，从而避免处理边界条件
 *用for循环的话窗口下标需要不断更新，当遍历结束后需要额外处理：low=high时只有一个元素，low<high时为多元素，需要构造指定字符串
*/
{
	vector<string> ret;
	int len = s.size();

	if (!s.size()) { return ret; }

	int i = 0;
	// while循环可以跳跃遍历vector元素
	while (i < len)
	{
		int low = i;
		++i;
		// 遇到满足条件的一直滑动
		while (i < len && s[i] == s[i-1] +1)
		{
			++i;	
		}
		// 滑动窗口尾标为i-1
		int high = i - 1;
		string temp = to_string(s[low]);
		// 判断是单元素还是范围元素
		if (low < high)
		{
			temp.append("->");
			temp.append(to_string(s[high]));
		}
		// move用的很厉害啊，当初没想到...
		ret.push_back(move(temp));
	}

	return ret;
}
