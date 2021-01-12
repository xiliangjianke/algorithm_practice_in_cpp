#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct list_node
{
	int val;
	list_node *next;
	list_node() : val(0), next(nullptr) {}
	list_node(int x) : val(x), next(nullptr) {}
	list_node(int x, list_node *next): val(x), next(next) {}
};

class Solution
{
public:
	list_node* merge_two_lists(list_node* l1, list_node* l2);
};

int main()
{
	
	Solution test;


}

list_node* Solution::merge_two_lists(list_node* l1, list_node* l2)
/*递归的解法不太好理解，就用了这个迭代的方法，很巧妙。
 *pre_head为头结点，方便结果返回，prev为移动节点不断指向l1/l2中满足条件的节点
 *相当于以prev作为蛇头，不断连接l1/l2中较小的节点，连接哪个链表的节点哪个链表的就往后移动一位
 *同时蛇头也往后移动一位，当有一个链表连接完后，当前完成的链表一定为有序的，直接和未完的链表连接即可
*/
{
	list_node pre_head = new list_node(-1);
	list_node *prev = pre_head;

	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->val < l2->val)
		{
			prev->next = l1;
			l1 = l1->next;
		}
		else
		{
			prev->next = l2;
			l2 = l2->next;
		}
		prev = prev->next;
	}
	prev->next = (l1 == nullptr?l2:l1);

	return pre_head->next;

}
/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
