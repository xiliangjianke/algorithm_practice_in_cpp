#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

class LinkList {
private:
	Node *Head;

public:
	LinkList();
	void CreatList1(int n); // 尾插法
	void CreatList2(int n); // 头插法
	void Insert(int i, int e); // 在位置i处插入元素e
	bool DeleteIndex(int i); // 删除指定位置的元素
	bool DeleteElem(int i); // 删除指定元素
	int GetData(int i); // 查询指定下标的元素
	int Search(int obj);// 查找链表中是否有此元素
	int ListLength(); // 返回链表长度
	void Display(); // 打印链表
};

int main() 
{
	LinkList test;
//	test.CreatList1(4);
	test.CreatList2(4);
	// insert
	//test.Insert(2, 10);

	// print
	//test.Display();

	// delete
	//test.DeleteIndex(2);
	//test.DeleteElem(2);
	test.Display();
	//test.Search(2)
	test.GetData(2);
	//int len = {test.ListLength()};
}

LinkList::LinkList() {
	Head = new Node;
	Head->next = NULL;
}

void LinkList::CreatList1(int n) {
	Node *pre = Head;

	for (int i = 0; i < n; ++i) {
	    Node *temp = new Node;
		cout << "Please enter number:" << endl;
		cin >> temp->data;
		
		// 尾插法的奥义就是将插入节点变为尾结点，由于前一个尾结点被覆盖，需要将插入节点的next指向null
		pre->next = temp; // 尾部插入头结点
		pre = temp; // 更新前驱节点位置，为下一次插入做准备
		temp->next = NULL; // 尾结点被插入节点覆盖，需重新将变为尾结点的插入节点指向null
	}

}

void LinkList::CreatList2(int n)
{
	Node *first = Head;

	for (int i = 0; i < n; ++i) 
	{
	    Node *temp = new Node;
		cout << "Please enter number:" << endl;
		cin >> temp->data;
		// 头插法的奥义就是插入的节点变为起始节点
		// 当节点链表为空时，起始节点作为头结点的副本，其next已经指向null，因此插入节点后不用再指向null
		temp->next = first->next; // 插入的节点指向起始节点
		Head->next = temp;	// 头结点指向插入节点，使插入节点变为起始节点
	}
}

void LinkList::Insert(int i, int e)
{
	Node *temp = {Head->next};
	int cnt = {0};
	// 指定下标插入元素的奥义是找到下标的前驱元素
	while (cnt < i - 1)
	{
		temp = temp->next;
		++cnt;
	}

	Node *ins = new Node;
	ins->data = e;
	ins->next = temp->next;
	temp->next = ins;
}

bool LinkList::DeleteIndex(int i)
{
		
	Node *pre = {Head->next};
	Node *cur;
	int cnt = {0};
	while (cnt < i - 1)
	{
		// 遍历完毕后，temp为下标元素前驱，cur为下标元素
		pre = pre->next; // temp指向链表下一元素
		cur = pre->next; // cur指向temp下一元素
		++cnt;
	}

	pre->next = cur->next;
	delete cur;
}

bool LinkList::DeleteElem(int i)
{
		
	Node *cur = {Head->next};
	Node *pre;

	if (!Head->next) return false;

	while (cur)
	{

		// 删除起始元素
		if (Head->next->data == i)
		{
			Head->next = cur->next;
			cur = Head->next;
			continue;
		}

		if (cur->data == i)
		{
			// 删除尾元素
			if (!cur->next)
			{	
				// 看看尾元素前驱是否为空
				if (pre->next)
				{
					pre->next = NULL;
					delete cur;
					return true;
				}
				else
				{
					delete cur;
					return true;
				}
			}
			pre->next = cur->next;
			delete cur;
			cur = pre->next;
		}
		pre = cur; // pre为当前元素前驱
		cur = cur->next; // cur为当前元素
	}
	return true;
}

int LinkList::GetData(int i)
{
	if (i < 0 || i > this->ListLength())
	{
		cout << "Error index!" << endl;
		return -1;
	}

	int cnt = {0};

	Node *cur = Head->next;
	while (cnt < i)
	{
		cur = cur->next;
		++cnt;
	}

	cout << "Data is: " << cur->data << endl;
	return cur->data;
}

int LinkList::Search(int obj)
{
	Node *cur = Head->next;

	while (cur)
	{
		if (cur->data == obj) { cout << "Find data!" << endl; return obj;}	
		cur = cur->next;
	}

	cout << "Can't find data!" << endl;
	return 0;
}

int LinkList::ListLength()
{
	Node *cur = Head->next;
	int cnt = {0};

	while (cur)
	{
		cur = cur->next;
		++cnt;
	}

	cout << "Length is: " << cnt << endl;

	return cnt;
}

void LinkList::Display()
{
	Node *temp = {Head->next};
	while (temp)
	{
		cout << temp->data  << " ";
		temp = temp->next;
	}
	cout << endl;
}
