#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
	// recursive
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead)
        	return pHead;
       	if(pHead && !pHead->next)
       		return pHead;

       	ListNode* cur;
       	if(pHead->next->val == pHead->val){
       		cur = pHead->next->next;
       		while(cur && cur->val==pHead->val)
       			cur = cur->next;
       		return deleteDuplication(cur);
       	}else{
       		cur = pHead->next;
       		pHead->next = deleteDuplication(cur);
       		return pHead;
       	}
    }

    // Space complexity: O(1)
    // Time complexity: O(n)
    ListNode* _01_deleteDuplication(ListNode* pHead){
    	ListNode *newHead = new ListNode(-1);
    	newHead->next = pHead;
    	ListNode *p = pHead;
    	ListNode *last = newHead;

    	while(p && p->next){
    		if(p->val == p->next->val){
    			int val = p->val;
    			while(p && p->val == val)
    				p = p->next;
    			last->next = p;
    		}else{
    			last = p;
    			p = p->next;
    		}
    	}
    	return newHead->next;
    }
};

// int main(){

// 	return 0;
// }