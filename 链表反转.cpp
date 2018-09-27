#include<iostream>
#include<vector>
using namespace std;

struct S_listNode{
	int val;
	S_listNode *next;
	S_listNode(int x): val(x), next(nullptr){}
};

struct D_listNode{
	int val;
	D_listNode *pre, *next;
	D_listNode(int x): val(x), pre(nullptr), next(nullptr){}
};

class reverseLinkedList{
public:
	S_listNode* reverseSingleList(S_listNode* head){
		S_listNode *pcur = head, *pnext=nullptr;
		while(pcur){
			S_listNode* ptmp = pcur->next;
			pcur->next = pnext;
			pnext = pcur;
			pcur = ptmp;
		}
		return pnext;
	}

	// need two pointers: one is for current node
	// another for the next node of the current
	D_listNode* reverseDoubleList(D_listNode* head){
		D_listNode* pcur=head, ppre=nullptr;
		while(pcur){
			D_listNode* ptmp = pcur->next;
			pcur->pre = ptmp;
			pcur->next = ppre;
			ppre = pcur;
			pcur = ptmp;
		}
		return ppre;
	}
};