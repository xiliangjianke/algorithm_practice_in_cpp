#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	int remove_duplicates(vector<int> & nums);
};

int main()
{
	vector<int> nums = {0,0,1,1,1,2,2,3,3,4};	
	Solution test;
	int index = test.remove_duplicates(nums);

	nums.assign(nums.begin(), nums.begin() + index);
	for (const auto &i: nums)
		cout << i << endl;

}

int Solution::remove_duplicates(vector<int> & nums)
/*双指针的本质就是讲讲两个指针把数组划分为三个区域，已处理的区域，正在处理的区域，以及未处理的区域
 *要采用原地算法就只能用双指针，把原数组头部或尾部变为符合要求的区域并返回区域的下标
*/
{
	int len = nums.size();
	if (!len) { return 0; }

	int i = 0;
	for (int j = 1; j < len; ++j)
	{
		if (nums[j] != nums[i])
		{
			++i;
			nums[i] = nums[j];
		}
	}
	return i + 1;

}
/*
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 

示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
