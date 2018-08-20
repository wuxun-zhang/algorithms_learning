#include<iostream>
#include<cstdlib>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        if(!head || k==1){
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy, *cur = head;
        dummy->next = head;
        int i=0;
        while(cur){
            i++;
            if(i%k == 0){
                pre = reverseOneGroup(pre, cur);
                cur = pre->next;
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
private:
    ListNode* reverseOneGroup(ListNode* p1, ListNode* p2){
        ListNode *p1next = p1->next;// 保存最初的头和尾部指针，以便完成翻转后返回头指针
        ListNode *p2next = p2->next;
        ListNode *prev = p2next;
        ListNode *p = p1next; 
        
        while (p != p2next) {
            ListNode *temp = p ->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        p1->next = p2;
        return p1next;
    }
    // version-2
    ListNode* reverseOneGroup_v2(ListNode* before_start, ListNode* end){
        ListNode *a=nullptr, *b=nullptr, *c=nullptr;
        a = before_start->next;
        c = end->next;
        while(a != end->next){
            b = a->next;
            a->next = c;
            c = a;
            a = b;
        }
        before_start->next = end;
        return before_start->next;
    }
};

int main(void){

    ListNode *head= nullptr, *p=nullptr, *s=nullptr;
    int a;
    bool isBreak = false;
    while(!isBreak && cin>>a){
        if(a<0){
            isBreak = true;
            continue;
        }
        s = new ListNode(a);
        if(!head){
            head = s;
        }
        else{
            p->next = s;
        }
        p = s;
    }
    int k;
    cin>>k;
    Solution sol;
    head = sol.reverseKGroup(head, k);
    s = head;
    while(s){
        cout<<s->val<<" ";
        s = s->next;
    }
    cout<<endl;
    return 0;
}