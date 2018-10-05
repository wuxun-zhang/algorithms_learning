#include<iostream>
#include<vector>
using namespace std;

struct listNode{
	int val;
	listNode* next;
	listNode(int x):val(x), next(nullptr){}
};

class _cyclic_singleLinkedList{
public:
	// "fast-slow" pointers
	// if cyclic, slow pointer must be catched by the fast one
	bool isCyclic(listNode* head){
		if(!head)
			return false;
		listNode *fast=head, *slow=head;
		while(fast && fast!=slow){
			if(fast->next)
				fast = fast->next->next;
			else
				fast = fast->next;
			slow = slow->next;
		}
		// the fast/slow pointer represent one node in the cycle
		// we can calculate the length of this cycle through this node
		if(!fast)
			return true;
		return false;
	}

	// ringMeetNode : one node in the ring/cycle
	int lengthOfCycle(listNode* ringMeetNode){
		listNode* fast = ringMeetNode;
		listNode* slow = ringMeetNode;
		int ringLength = 0;
		while(fast!=slow){
			fast = fast->next->next;
			slow = slow->next;
			ringLength++;
		}
		return ringLength;
	}
private:

};

// int main(void){

// 	return 0;
// }