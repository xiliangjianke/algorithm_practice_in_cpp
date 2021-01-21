#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	vector<int> plus_one(vector<int> &s);
};

int main()
{
	vector<int> s = {4,3,2,1};	
	Solution test;
	vector<int> res = test.plus_one(s);

	for (const auto i: res)
	{
		cout << i;
	}
	cout << endl;




}

vector<int> Solution::plus_one(vector<int> &s)
{
	int len = s.size() - 1;

	for (int i = len; i >= 0; --i)
	{
		s[i]++;
		if (s[i] == 10) { s[i] == 0;}
		else return s;
	}
	s.insert(s.begin(), 1);
	return s;
}
