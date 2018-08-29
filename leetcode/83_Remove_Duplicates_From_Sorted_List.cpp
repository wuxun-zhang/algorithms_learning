#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// ɾ�����������е��ظ��ڵ�
ListNode* deleteDuplicates(ListNode* head)
{
	ListNode *pre = nullptr, *cur = nullptr;
	cur = head;
	pre = head;
	ListNode *new_head = nullptr;
	//stack<ListNode*> to_delete;
	// ͷ����Ƿ�Ϊ��
	if (!head)
		return nullptr;
	// �������Ƿ�ֻ��ͷ���
	if (!head->next)
		cur = cur->next;
	new_head = pre;

	// �ж�pre�ڵ���cur�ڵ��Ƿ��ظ�
	while (pre && cur)
	{
		// �Ƿ񵽴�����β��
		while (cur && pre->val == cur->val)
		{
			pre->next = cur->next;
			// ������Ҫɾ���Ľڵ�ָ��
			//to_delete.push(cur);
			cur = cur->next;
		}
		// ����˫ָ��
		pre = pre->next;
		if (cur)
			cur = cur->next;
	}
	//// �ͷ�ɾ���Ľڵ��ڴ�
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