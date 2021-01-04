#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	int fib(int n);
};

int main()
{
	
	int n = {8};
	Solution test;
	int res = test.fib(n);

	cout << res << endl;
}

int Solution::fib(int n)
/*这解法说是动态规划，就是求解最优解的一种解法。
 *动态数组确实学到了，这东西只要找到状态关系式都能使用
 *可看了个详解动态规划的文章没有悟道啥，还是要多做题才能看懂他人总结的精华。
*/
{
	if (n < 2) { return n;}
	
	// 滚动数组，这可太秀了....
	int p = 0, q = 0, r = 1;

	for (int i = 2; i <= n; ++i)
	{
		p = q;
		q = r;
		r = p + q;
	}

	return r;

}
/*
斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给你 n ，请计算 F(n) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fibonacci-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
