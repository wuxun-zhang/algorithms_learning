#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k<1)
        	return nullptr;
        if(k<2)
        	return lists[0];
        ListNode* newHead = mergeTwoLists(lists[0], lists[1]);
        for(int i=2; i<k; i++){
        	newHead = mergeTwoLists(newHead, lists[i]);
        }
        return newHead;
    }

    ListNode* _01_mergeKLists(vector<ListNode*>& lists){
    	if(!lists.size())
    		return nullptr;
    		return _01_mergeKListsWithPartition(lists, 0, lists.size()-1);
    }
private:
	ListNode* mergeTwoLists(ListNode* pHead1, ListNode* pHead2){
		ListNode* newHead = new ListNode(-1);
		ListNode* cur->next = newHead;
		while(pHead1 && pHead2){
			if(pHead1->val < pHead2->val){
				cur->next = pHead1;
				pHead1 = pHead1->next;
			}else{
				cur->next = pHead2;
				pHead2 = pHead2->next;
			}
			cur = cur->next;
		}
		if(!pHead1)
			cur->next = pHead2;
		else
			cur->next = pHead1;
		return newHead->next;
	}

	ListNode* _01_mergeTwoLists(ListNode* pHead1, ListNode* pHead2){
		if(!pHead1)
			return pHead2;
		if(!pHead2)
			return pHead1;
		if(pHead1->val <= pHead2->val){
			pHead1->next = _01_mergeTwoLists(pHead1->next, pHead2);
			return pHead1;
		}else{
			pHead2->next = _01_mergeTwoLists(pHead1, pHead2->next);
			return pHead2;
		}
	}

	ListNode* _01_mergeKListsWithPartition(vector<ListNode*>& lists, int start, int end){
		if(end - start == 0){
			return lists[start];
		}
		return _01_mergeTwoLists(_01_mergeKListsWithPartition(lists, start, (start+end)/2), 
			_01_mergeKListsWithPartition(lists, (start+end)/2+1, end));
	}
};