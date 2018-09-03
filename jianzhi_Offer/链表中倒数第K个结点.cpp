#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(nullptr){}
};

class Solution{
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
		if(!pListHead || k==0)
			return nullptr;
		ListNode* p1 = pListHead;
		ListNode* p2 = pListHead;
		for(int i=0; i<k-1; i++){
			if(p1->next)
				p1 = p1->next;
			else
				return nullptr;
		}
		while(p1->next){
			p1 = p1->next;
			p2 = p2->next;
		}
		return p2;
	}
};