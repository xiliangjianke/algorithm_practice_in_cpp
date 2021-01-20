#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	int length_of_last_word(string &s);
};

int main()
{
	string s("Hello World");	
	Solution test;
	int res = test.length_of_last_word(s);
	cout << res << endl;

}

int Solution::length_of_last_word(string &s)
{
	int end = s.size() - 1;
	while (end >= 0 && s[end] == ' ') { --end; }
	if (end < 0) { return 0; }
	int start = end;
	while (start >= 0 && s[start] != ' ') { --start; }

	return end -start;
}
