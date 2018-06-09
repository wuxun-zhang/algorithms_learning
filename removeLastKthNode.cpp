#include<iostream>
using namespace std;

// ɾ��������˫�����еĵ�K���ڵ�

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
	// ������ɾ��������K���ڵ�
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
	// ˫����ɾ��������K���ڵ�
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
			// �ж�ɾ�����Ƿ�Ϊβ�ڵ㣬β�ڵ���ǰ���ڵ�
			if (newNext != nullptr)
				newNext->prev = cur;
		}
		return head;
	}
	// ��������N���ڵ�ĵ�����
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
	// ��������N���ڵ��˫������
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
	// ��ӡ������Ϣ
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