#include<iostream>
#include<unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


class Solution {
public:
	// Time&Space: O(n) & O(n)
    RandomListNode* Clone(RandomListNode* pHead){
        if(!pHead)
        	return nullptr;
        unordered_map<RandomListNode*, RandomListNode*> nodeMap;
		RandomListNode* new_head = new RandomListNode(-1), *new_current = new_head;
		RandomListNode* current = pHead;
		// Step1: copy the direct next relationship
		while(current){
			if(!new_head)
				new_head->next = new RandomListNode(current->label);
			else{
				new_current->next = new RandomListNode(current->label);
			}
			// store current <-> new_current
			nodeMap[current] = new_current->next;
			// the next node
			current = current->next;
			new_current = new_current->next;
		}

		// copy the random pointing realtionship
		current = pHead;
		while(current){
			RandomListNode* mirrorNode = nodeMap[current];
			if(!current->random)
				mirrorNode->random = nullptr;
			else
				mirrorNode->random = nodeMap[current->random];
			current = current->next;
		}
		return new_head->next;
    }

    // Time&Sapce: O(n) & O(1)
    RandomListNode* _01_Clone(RandomListNode* pHead){
    	CloneNodes(pHead);
    	connectRandomNodes(pHead);
    	return reconnectNodes(pHead);
    }

private:
	// step 1
	// A->A'->B->B'->C->C'->D->D'->nullptr;
	void CloneNodes(RandomListNode* pHead){
		RandomListNode* pNode = pHead;
		while(pNode){
			RandomListNode* pCloned = new RandomListNode(pNode->label);
			pCloned->next = pNode->next;
			pCloned->random = nullptr;
			pNode->next = pCloned;
			pNode = pNode->next;
		}
	}

	// step 2
	// if A's random is D, then A'(A->next) random must be D'(D->next)
	void connectRandomNodes(RandomListNode* pHead){
		RandomListNode* pNode = pHead;
		while(pNode){
			RandomListNode* pCloned = pNode->next;
			if(pNode->random)
				pCloned->random = pNode->random->next;
			pNode = pCloned->next;
		}
	}

	// step 3
	// linking all nodes at odd places to recover the origin linked list, 
	// and linking all nodes at even places to generate the copied linked list
	RandomListNode* reconnectNodes(RandomListNode* pHead){
		RandomListNode* pNode = pHead;
		RandomListNode* pClonedHead = nullptr, *pClonedNode = nullptr;
		if(pNode){
			pClonedHead = pNode->next;
			pClonedNode = pNode->next;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}

		while(pNode){
			pClonedNode->next = pNode->next;
			pClonedNode = pClonedNode->next;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}

		return pClonedHead;
	}
};

// int main(void) {
// 	Solution sol;
// 	int n;
// 	while (cin >> n) {
// 		RandomListNode* head = new RandomListNode(-1);
// 		RandomListNode* cur = head;
// 		while (n--) {
// 			int x;
// 			cin >> x;
// 			if (!head)
// 				head->next = new RandomListNode(x);
// 			else {
// 				RandomListNode* tmp = new RandomListNode(x);
// 				cur->next = tmp;
// 			}
// 			cur = cur->next;
// 		}
// 		cur = head;
// 		while (cur) {
// 			if (cur->next && cur->next->next)
// 				cur->random = cur->next->next;
// 			else
// 				cur->random = head->next;
// 			cur = cur->next;
// 		}

// 		head = sol.Clone(head);
// 		cur = head->next;
// 		while (cur) {
// 			cout << cur->label;
// 			cout << "("<<cur->label << "'s random node is " << cur->random->label<<")";
// 			cur = cur->next;
// 			if (cur)
// 				cout << "->";
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }