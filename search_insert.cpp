#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	int search_insert(vector<int> &s, int target);
};

int main()
{
	vector<int> s = {1,3,5,6};
	int target = 2;
	Solution test;
	
	int res = test.search_insert(s, target);
	cout << "Result is " << res << endl;

}

int Solution::search_insert(vector<int> &s, int target)
/*二分查找，关键要理解二分查找的终止条件，以及不同情况左右下标的变化
 *最简单的如果分不清的话，找个特殊的数组带入试下就能试出来
*/
{
	int len = s.size();
	if (!len) { return 0; }
	int left = 0, right = len - 1;

	while (left <= right)
	{
		int mid = (right + left)/2;
		if (s[mid] == target) { return mid; }
		else if (s[mid] < target) { left = mid + 1; }
		else { right = mid - 1; }
	}
	return left;
}
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
