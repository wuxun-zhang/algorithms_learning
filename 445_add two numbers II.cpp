#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *newHead = nullptr, *p, *s;
		stack<ListNode*> s1, s2;
		while (l1 || l2)
		{
			if (l1)
			{
				s1.push(l1);
				l1 = l1->next;
			}
			if (l2)
			{
				s2.push(l2);
				l2 = l2->next;
			}
		}
		// 求和
		int carry = 0;//进位信息
		ListNode *top1, *top2;
		while (!s1.empty() && !s2.empty())
		{
			top1 = s1.top(); s1.pop();
			top2 = s2.top(); s2.pop();
			int cur = top1->val + top2->val + carry;
			carry = cur / 10;
			s = new ListNode(cur%10);
			if (!newHead)
				newHead = s;
			else
			{
				p = newHead;
				newHead = s;
				newHead->next = p;
			}
		}
		while (!s1.empty())
		{
			top1 = s1.top(); s1.pop();
			int cur = carry + top1->val;
			carry = cur / 10;
			s = new ListNode(cur%10);
			// 更新头结点
			p = newHead;
			newHead = s;
			newHead->next = p;
		}
		while (!s2.empty())
		{
			top2 = s2.top(); s2.pop();
			int cur = carry + top2->val;
			carry = cur / 10;
			s = new ListNode(cur%10);
			carry = 0;
			// 更新头结点
			p = newHead;
			newHead = s;
			newHead->next = p;
		}
		if (carry)
		{
			s = new ListNode(carry);
			// 更新头结点
			p = newHead;
			newHead = s;
			newHead->next = p;
		}
		return newHead;
	}
	// 精简版本
	ListNode* addTwoNumbers_v2(ListNode* l1, ListNode *l2)
	{
		stack<ListNode*> s1, s2;
		ListNode *newHead = nullptr;
		while (l1)
		{
			s1.push(l1);
			l1 = l1->next;
		}
		while (l2)
		{
			s2.push(l2);
			l2 = l2->next;
		}
		int sum = 0;
		ListNode *list = new ListNode(0);
		while (!s1.empty() || !s2.empty())
		{
			if (!s1.empty())
			{
				sum += s1.top()->val;
				s1.pop();
			}
			if (!s2.empty())
			{
				sum += s2.top()->val;
				s2.pop();
			}
			list->val = sum % 10;	// 当前位上的数字
			newHead = new ListNode(sum / 10); // 进位信息
			newHead->next = list;
			list = newHead;
			sum /= 10;
		}
		return (list->val == 0) ? list->next : list;
	}
};
