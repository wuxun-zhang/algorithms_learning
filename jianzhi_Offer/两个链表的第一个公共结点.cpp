#include<iostream>
#include<stack>
using namespace std;

// find the common node of two linked list

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x){}
};

class Solution{
public:
	// use stack
	// Time&Space complexity: m+n
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
		if(!pHead2 || !pHead1)
			return nullptr;
		stack<ListNode*> nodeStack1, nodeStack2;
		while(pHead1 || pHead2){
			if(pHead1){
				nodeStack1.push(pHead1);
				pHead1 = pHead1->next;
			}
			if(pHead2){
				nodeStack2.push(pHead2);
				pHead2 = pHead2->next;
			}
		}
		ListNode* commonNode = nullptr;
		while(!nodeStack1.empty() && !nodeStack2.empty() && 
				nodeStack1.top() == nodeStack2.top()){
			commonNode = nodeStack1.top();
			nodeStack2.pop();
			nodeStack1.pop();
			if(!nodeStack1.empty()&&!nodeStack2.empty()&&
				nodeStack1.top()!=nodeStack2.top())
				break;
		}
		return commonNode;
	}

	// non-stack solution
	// Time complexity: m+n 
	// Space complexity: 1
	ListNode* FindFirstCommonNode_opt(ListNode* pHead1, ListNode* pHead2){
		if(!pHead2 || !pHead1)
			return nullptr;
		int length1=0, length2=0;
		ListNode* tmp = pHead1;
		while(tmp){
			length1++;
			tmp = tmp->next;
		}
		tmp = pHead2;
		while(tmp){
			++length2;
			tmp = tmp->next;
		}

		int k = length1-length2;
		ListNode* first = pHead1, *second = pHead2;
		if(length1 < length2){
			k = length2-length2;
			// swap nodes, make sure the first list has the greater length
			first = pHead2;
			second = pHead1;
		}
		while(first && second){
			while(k>0){
				k--;
				first = first->next;
			}
			if(first == second)
				 return first;
			first = first->next;
			second = second->next;	
		}
		return nullptr;
	}
private:

};

int main(void){

	return 0;
}