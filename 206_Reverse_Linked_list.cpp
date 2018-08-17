#include<iostream>
using namespace std;

// test rebase second time in branch-leetcode_intervie


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

// 翻转单链表
// 非递归
class Solution {
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode *a = nullptr, *b = nullptr, *c = nullptr;
		if (!head)
			return nullptr;
		a = head;
		while (a)
		{
			b = a->next;
			a->next = c;
			c = a;
			a = b;
		}
		head = c;
		return head;
	}

	// 递归
	ListNode* reverseList_v2(ListNode* head)
	{
		return reverseListInt(head, nullptr);
	}
private:
	ListNode* reverseListInt(ListNode *head, ListNode *newHead)
	{
		if (head == nullptr)
			return newHead;
		ListNode *nextNode = head->next;
		head->next = newHead;
		newHead = head;
		return reverseListInt(nextNode, newHead);
	}
};



//void main()
//{
//	int N;
//	Solution sol;
//	cout << "Please input N：";
//	while (cin >> N)
//	{
//		ListNode *head = nullptr, *s, *p = nullptr;
//		for (int i = 0; i < N; i++)
//		{
//			int a;
//			cin >> a;
//			s = new ListNode(a);
//			if (!head)
//				head = s;
//			else
//				p->next = s;
//			p = s;
//		}
//		head = sol.reverseList_v2(head);
//		while (head)
//		{
//			cout << head->val;
//			if (head->next)
//				cout << "->";
//			head = head->next;
//		}
//		cout << endl;
//	}
//}
