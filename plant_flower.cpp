#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n);
	bool canPlaceFlowers2(vector<int>& flowerbed, int n);
};

int main()
{
	
	vector<int> flowerbed{1,0,0,0,0,1};

	int num{2};


	Solution test;

	if (test.canPlaceFlowers2(flowerbed, num))
		cout << "Error!" << endl;
	else
		cout << "Success!" << endl;
	
}


bool Solution::canPlaceFlowers(vector<int>& flowerbed, int n)
/*这是力扣官方给的贪心解题思路，感觉在做数学推导题.....
 *种花可以考虑两种情况：1.两朵花之间种花；2.两朵花之外种花
 *对于两朵花之间种花，假设左边花下标为i,右边为j，采用特殊情况可推导出种花数量为：(j - i -2)/2
 *对于两朵花之外种花，假设最左边已存在花朵的下标为l，最右边已存在花朵的下标为r，容器长度为len
 *对于最左边种花情况可推出种花数量为：l/2
 *对于最右边种花情况可推出种花数量为：(len - r - 1)/2
 *若给的容器没花，则种花数量为：(len + 1)/2
 *采用变量prev记录上一次话的位置，与当前遍历的下标形成种花区间，从而遍历计算最左边种花以及两朵花之间的种花情况
 *遍历完后考虑特殊情况，没花以及右边种花的情况
 *
 *这贪心有点硬核，直接循环判断当前下标更简单：
 *if ( f[i] == 1) continue;当前坑位有花，跳过
 *if ( f[i-1] == 1) continue;上一坑位有花，跳过
 *if ( f[i+1] == 1) continue;下一坑位有花，跳过
 *f[i] = 1;++cnt;能跳的都跳了，剩下的肯定可以种
 *
*/
{
	int cnt{0},prev{-1};
	auto len = flowerbed.size();

	for (auto i = 0; i < len; ++i)
	{
		if (flowerbed[i] == 1)
		{
			if (prev < 0) 
			{
				cnt += i/2;
			}
			else 
			{
				cnt += (i - prev - 2)/2;
			}

			prev = i;
		}
	}
	if (prev < 0) { cnt += (len + 1)/2; }
	else { cnt += (len - prev -1)/2; }

	return cnt >= n;
}

bool Solution::canPlaceFlowers2(vector<int>& flowerbed, int n)

{
	auto len = flowerbed.size();
//	for (auto i = flowerbed.begin(), i != flowerbed.end(); ++i)
	for (auto i = 0; i < len; ++i)
	{
		if (n <= 0) { return true; }

		if (flowerbed[i] == 1) { continue; }

		if ((i > 0) && (flowerbed[i-1] == 1)) {continue;}

		if ((i < len - 1) && (flowerbed[i+1] == 1)) {continue;}

		flowerbed[i] = 1;
		--n;
	}

	return n <= 0;
}
/*
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:

输入: flowerbed = [1,0,0,0,1], n = 1
输出: True
示例 2:

输入: flowerbed = [1,0,0,0,1], n = 2
输出: False
注意:

数组内已种好的花不会违反种植规则。
输入的数组长度范围为 [1, 20000]。
n 是非负整数，且不会超过输入数组的大小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-place-flowers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
