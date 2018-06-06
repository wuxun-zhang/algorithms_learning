#include<iostream>
using namespace std;

// 删除单链表、双链表中的第K个节点

struct singleList {
	int val;
	singleList *next;
	singleList(int x) :val(x), next(nullptr) {}
};

struct doubleList {
	int val;
	doubleList *prev, *next;
	doubleList(int x):val(x),prev(nullptr),next(nullptr){}
};

class Solution {
public:
	// 单链表，删除倒数第K个节点
	singleList* removeLastKthNode_v1(singleList *head, int K)
	{
		if (!head || K < 1)
			return nullptr;
		singleList *cur = head;
		while (cur != nullptr)
		{
			K--;
			cur = cur->next;
		}
		if (K == 0)
			return head->next;
		if (K < 0)
		{
			cur = head;
			while (++K != 0)
				cur = cur->next;
			cur->next = cur->next->next;
		}
		return head;
	}
	// 双链表，删除倒数第K个节点
	doubleList* removeLastKthNode_v2(doubleList *head, int K)
	{
		if (!head || K < 1)
			return nullptr;
		doubleList *cur = head;
		while (cur != nullptr)
		{
			K--;
			cur = cur->next;
		}
		if (K == 0)
		{
			head =  head->next;
			head->prev = nullptr;
		}
		if (K < 0)
		{
			cur = head;
			while (++K != 0)
				cur = cur->next;
			doubleList *newNext = cur->next->next;
			cur->next = newNext;
			// 判断删除的是否为尾节点，尾节点无前驱节点
			if (newNext != nullptr)
				newNext->prev = cur;
		}
		return head;
	}
	// 创建具有N个节点的单链表
	singleList *createSingleList(int N)
	{
		singleList *head = nullptr, *s = nullptr, *p = nullptr;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			s = new singleList(temp);
			if (!head)
				head = s;
			else
				p->next = s;
			p = s;
		}
		return head;
	}
	// 创建具有N个节点的双向链表
	doubleList *createDoubleList(int N) 
	{
		doubleList *head = nullptr, *s = nullptr, *p = nullptr;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			s = new doubleList(temp);
			if (!head)
				head = s;
			else
			{
				p->next = s;
				s->prev = p;
			}
			p = s;
		}
		return head;
	}
	// 打印链表信息
	void printLinkedList(singleList* head)
	{
		while (head)
		{
			cout << head->val;
			if (head->next)
				cout << "->";
			head = head->next;
		}
		cout << endl;
	}
};

void main()
{
	int N,K;
	Solution sol;
	while (cin >> N>>K)
	{
		singleList *head;
		head = sol.createSingleList(N);
		head = sol.removeLastKthNode_v1(head, K);
		sol.printLinkedList(head);
	}
}