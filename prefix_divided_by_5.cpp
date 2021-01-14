#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	vector<bool> prefix_div_by_5(vector<int> &s);
};

int main()
{
	vector<int> nums = {0,1,1,1,1,1};	
	Solution test;
	vector<bool> ret = test.prefix_div_by_5(nums);

	for (const auto& i: ret)
	{
		cout << i;	
	}
	cout << endl;


}

vector<bool> Solution::prefix_div_by_5(vector<int> &s)
/*这里面二进制转十进制可以用：a[i-1]*2 + a[i]
 *而且a[i]%5 = (mod_a[i-1] + a[i])%5，这个确实不好想到。。。
 *还有点要注意vector<bool>类型的emplace_back只导入vector还没法用，具体在那个头文件里找半天也没找到。。。
*/
{
	int len = s.size();
	vector<bool> res;
	int prefix = 0;

	for (int i = 0; i < len; ++i)
	{
		prefix = (prefix*2 + s[i]) % 5;
		//res.emplace_back (prefix == 0);
		res.emplace_back(prefix == 0);
	}
	return res;
}
