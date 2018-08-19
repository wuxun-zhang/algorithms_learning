#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(nullptr){}
};

class Solution{
public:
	ListNode* mergeTwoLists_v1(ListNode* l1, ListNode* l2){
		ListNode* dummy = new ListNode(-1);
		ListNode* preHead = dummy;
		while(l1 || l2){
			while(l1 && l2){
				int new_val;
				if(l1->val>l2->val)
				{
					new_val = l2->val;
					l2 = l2->next;
				}
				else
				{
					new_val = l1->val;
					l1 = l1->next;
				}
				preHead->next = new ListNode(new_val);
				preHead = preHead->next;
			}

			if(l1){
				preHead->next = new ListNode(l1->val);
				preHead = preHead->next;
				l1 = l1->next;
			}

			if(l2){
				preHead->next = new ListNode(l2->val);
				preHead = preHead->next;
				l2 = l2->next;
			}
		}
		return dummy->next;
	}

	ListNode* mergeTwoLists_v2(ListNode* l1, ListNode* l2){
		ListNode* dummy = new ListNode(-1);
		ListNode* preHead = dummy;
		// !!!
		while(l1 && l2){
			int new_val;
			if(l1->val>l2->val)
			{
				new_val = l2->val;
				l2 = l2->next;
			}
			else
			{
				new_val = l1->val;
				l1 = l1->next;
			}
			preHead->next = new ListNode(new_val);
			preHead = preHead->next;	
		}
		// !!!
		preHead->next = l1 ? l1 : l2;
		return dummy->next;
	}
	// recursive
	ListNode* mergeTwoLists_v3(ListNode* l1, ListNode* l2){
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		if(l1->val < l2->val){
			l1->next = mergeTwoLists_v2(l1->next, l2);
			return l1;
		}
		else{
			l2->next = mergeTwoLists_v2(l1, l2->next);
			return l2;
		}
	}
	
	ListNode* mergeTwoLists_v4(ListNode* l1, ListNode* l2){
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		ListNode* head = l1->val < l2->val ? l1:l2;
		ListNode* nonhead = l1->val < l2->val ? l2:l1;
		head->next = mergeTwoLists_v4(head->next, nonhead);
		return head;
	}
private:
};

// int main(void){

// 	return 0;
// }