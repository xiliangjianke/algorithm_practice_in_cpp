#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	int max_sub_array(vector<int> &s);
};

int main()
{
	vector<int> s = {-2,1,-3,4,-1,2,1,-5,4};	
	Solution test;

	int res = test.max_sub_array(s);

	cout << res << endl;


}

int Solution::max_sub_array(vector<int> &s)
/*数组最大子序关键在于如何记录和更新当前最大子序和
 *原来是想着比较子序和加上当前遍历项是否大于原先子序和，但这样无法应对2,-1,3,-5这样的序列
 *后面转换思路，子序和只要大于0就一直加，这样就避免只根据后一项来更新子序和的问题
 *子序小于0的话就更新子序和的值为当前遍历项
 *每次变化子序和都取ans和sum的最大值，这样就能一直记录最大子序和，结束后返回ans即可
*/
{
	int sum = 0, ans = s[0];
	int len = s.size();

	for (int i = 0; i < len; ++i)
	{
		if (sum > 0) { sum += s[i]; }
		else { sum = s[i]; }
		ans = max(ans, sum);
	}
	return ans;
}
/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

