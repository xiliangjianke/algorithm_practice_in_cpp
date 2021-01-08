#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	/*
	void rotate_array(vector<int> &s, int k) // 采用额外数组，new[(i + k)%len] = old[i]
	{
		int len = s.size();
		// 长度能确定的时候创建数组一定要指定长度,不然后面做反转啥的会出问题
		vector<int> temp(len);
		
		for (int i = 0; i < len; ++i)
		{
			temp[(i+k)%len] = s[i];
		}

		// 采用assign赋值，assign有三种构造方式：1.assign(it.begin(),it.end());2.assign(n, &val);3.assign(initializer_list)
		s.assign(temp.begin(), temp.end());
	}
	*/
	void rotate_array(vector<int> &s, int k) // 采用数组翻转，先整个翻转，再翻转前半部分，最后翻转后半部分
	{
		int len = s.size();
		k %= len;

		reverse(s, 0, len - 1);// 整个数组翻转
		reverse(s, 0, k - 1);	// 再翻转前半部分
		reverse(s, k, len - 1); // 最后翻转后半部
	}

	void reverse(vector<int>& s, int start, int end)
	{
		while ( start < end)
		{
			swap(s[start], s[end]);
			++start;
			-end;
		}
	}
};

int main()
{
	vector<int> s = {1,2,3,4,5,6,7};
	int k = {3};
	Solution test;
	
	test.rotate_array(s, k);

	for (const auto &i : s)
		cout << i ;
	cout << endl;
}





