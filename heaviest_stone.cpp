#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	int lastStoneWeight(vector<int> &s);
};

int main()
{
	
	vector<int> stones{1,4,2,8,5,9};
	
	Solution test;

	int res = test.lastStoneWeight(stones);

	cout << res << endl;
}

int Solution::lastStoneWeight(vector<int> &s)
/*采用优先队列作为主用数据结构，此队列特点为每次插入、移除元素后队列内数据仍是有序的。
 *1.记录出最大和第二大元素：q.top()
 *2.记录后将元素删除，逐步减少队列元素（删除后序列仍为有序的）：q.pop()
 *3.将最大元素和第二大元素比较，若不相等则将差值入队
 *4.循环直至队列长度为1，此时p.top()即为结果
*/
{
	priority_queue<int> q;

	for (const auto &i : s) q.push(i);

	while (q.size() > 1)
	{
		int top1 = q.top();
		q.pop();

		int top2 = q.top();
		q.pop();

		if (top1 > top2) 
			q.push(top1 - top2);
	}

	return q.top();
}

/*
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

 

示例：

输入：[2,7,4,1,8,1]
输出：1
解释：
先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
