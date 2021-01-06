#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>


using namespace std;

class Solution
{
public:
	int romanToInt(string s);
};

int main()
{
	string s = ("MCMXCIV");

	Solution test;

	int res = test.romanToInt(s);

	cout << res << endl;
	
}

int Solution::romanToInt(string s)
/*罗马数字有个特点，左边的数比右边的小就要减，比如'IV'=5-1=4,左边的数字比右边的大就加。
 *有的解法直接从0开始遍历s，对比s[i]和s[i+1]感觉最后一个会越界啊
 *所以采用从1开始遍历，每次将当前num记录给prenum进行对比
*/
{
	unordered_map<char,int> roman = 
	{
		{'I',1},
		{'V',5},
		{'X',10},
		{'L',50},
		{'C',100},
		{'D',500},
		{'M',1000}
	};

	int prenum = roman[s[0]];
	int sum = {0};
	int len = s.size();
	
	for (int i = 1; i < len; ++i)
	{
		int num = roman[s[i]];

		if (prenum < num) 
		{ 
			sum -= prenum;
		}
		else
		{
			sum += prenum;
		}

		prenum = num;
	}
	sum += prenum;
	return sum;

}
/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

 

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/roman-to-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
