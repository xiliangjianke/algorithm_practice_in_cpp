#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
	int intRverse(int &s);
};

int main()
{
	
	int num{0};

	cout << "Please enter a number:" << endl;
	cin >> num;

	Solution test;

	int res = test.intRverse(num);

	cout << "After reverse the number is: "
		 << res << endl;


	
}

int Solution::intRverse(int &s)
/*
 *1.从低位到高位获取每一位数的方法：num%10
 *2.翻转凑整数的方法：res = res*10 + num
 *3.num/10将忽略尾部位数，从而获取高一位的数的数值
 *4.输出前需检查是否栈溢出，INT两端的极限值可在climits库中获取
*/
{
	long res{0};

	while (s != 0)
	{
		res = res*10 + s % 10;

		s /= 10;
	}
	
	return res <= INT_MAX - 1 && res >= INT_MIN ? res : 0;
}

/*
 *给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
*/
