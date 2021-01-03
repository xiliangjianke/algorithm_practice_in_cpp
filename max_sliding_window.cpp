#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	//优先队列解法
	vector <int> maxSlidingWindow(vector<int>& nums, int k);
	//双端队列解法
	vector <int> maxSlidingWindow2(vector<int>& nums, int k);
};

int main()
{
	
	vector<int> nums{1,4,2,8,5,9};

	Solution test;

	auto res = test.maxSlidingWindow2(nums, 3);

	for (const auto &i : res)
	{
		cout << i << " ";	
	}
	cout << endl;
	
}

vector <int> Solution::maxSlidingWindow(vector<int>& nums, int k)
/*此题说白了就是寻找子数组最大值，priority_queue天赋异禀，本身有序头尾元素即为极值
 *双端队列可操作为单调队列，此单调队列记录数组下标，按数组值形成单调减队列，从而使头元素为极值
 *以上两种解法均需处理队列中极值不在窗口范围的情况，按上述操作后极值不在窗口内一定在窗口左侧
 *因此只需判断极值下标j即可，假设极值下标为j，当前遍历到的数组下标为i，窗口长度为k
 *当满足：j < i - k时，极值在窗口外需排除。
 *官网还有种解法是分块+预处理，看了半天看不懂。。。。
 *此函数为优先队列解法
*/
{	
	//优先队列自带排序功能，因此存储数组下标没卵用，但后面排除窗口外的极值又要用下标，因此采用二元组
	priority_queue<pair<int, int>> q;

	//用 len{nums.size()}初始化变量，循环时做下标加减法就会报错，还不知道为什么...
	int len = nums.size();

	//先整个完整窗口
	for (int i = 0; i < k; ++i)
	{
		q.emplace(nums[i], i);	
	}
	
	//存放极值的vector
	vector<int> ans = {q.top().first};
	//开始滑动
	for (int i = k; i < len; ++i)
	{
		q.emplace(nums[i], i);

		//去除窗口外极值
		while (q.top().second < i - k)
		{
			q.pop();	
		}

		//此时只剩窗口内的极值
		ans.push_back(q.top().first);
	}

	return ans;

}

vector <int> Solution::maxSlidingWindow2(vector<int>& nums, int k)
{
	deque<int> q;
	int len = nums.size();

	//先形成一个单调减队列
	for (int i = 0; i < k; ++i)
	{
		//当队列不为空，判断数组当前值与队列尾标对应数组值，若数组值大，则q.pop_back()
		while (!q.empty() && nums[i] >= nums[q.back()])
		{
			q.pop_back()	;
		}

		//将数组下标入队
		q.push_back(i);
	}

	vector<int> ans = {nums[q.front()]};

	//开始滑动
	for (int i = k; i < len; ++i)
	{
		
		//当队列不为空，判断数组当前值与队列尾标对应数组值，若数组值大，则q.pop_back()
		while (!q.empty() && nums[i] >= nums[q.back()])
		{
			q.pop_back()	;
		}

		//将数组下标入队
		q.push_back(i);

		// 去除窗口外极值
		while (q.front() < i - k)
		{
			q.pop_front();
		}

		// 经过数组值入队、去除极值后，当前队列首元素一定为窗口极值对应的下标
		ans.push_back(nums[q.front()]);
	}
	return ans;
}
