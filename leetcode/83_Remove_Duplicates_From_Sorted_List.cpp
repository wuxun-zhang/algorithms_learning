#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// 删除单向链表中的重复节点
ListNode* deleteDuplicates(ListNode* head)
{
	ListNode *pre = nullptr, *cur = nullptr;
	cur = head;
	pre = head;
	ListNode *new_head = nullptr;
	//stack<ListNode*> to_delete;
	// 头结点是否为空
	if (!head)
		return nullptr;
	// 链表中是否只有头结点
	if (!head->next)
		cur = cur->next;
	new_head = pre;

	// 判断pre节点与cur节点是否重复
	while (pre && cur)
	{
		// 是否到达链表尾端
		while (cur && pre->val == cur->val)
		{
			pre->next = cur->next;
			// 保存需要删除的节点指针
			//to_delete.push(cur);
			cur = cur->next;
		}
		// 更新双指针
		pre = pre->next;
		if (cur)
			cur = cur->next;
	}
	//// 释放删除的节点内存
	//while (!to_delete.empty())
	//{
	//	ListNode* top = to_delete.top();
	//	to_delete.pop();
	//	delete top;
	//}

	return new_head;
}

void main()
{
	int N;
	cout << "please input N: ";
	while (cin >> N)
	{
		ListNode *head = nullptr, *s = nullptr, *p = nullptr;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			s = new ListNode(a);
			if (!head)
				head = s;
			else
				p->next = s;
			p = s;
		}
		head = deleteDuplicates(head);
		while (head)
		{
			cout << head->val;
			head = head->next;
			if (head)
				cout << "->";
		}
		cout << endl;
		cout << "please input N: ";
	}
}