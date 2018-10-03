#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        stack<int> stack_;
        // 
        int push_id=0, pop_id=0;
        for(; pop_id<popV.size(); ){
        	if(!stack_.empty() && popV[pop_id] == stack_.top()){
        		stack_.pop();
        		pop_id++;
        	}else if(push_id<pushV.size()){
        		for(; push_id<pushV.size(); ){
					stack_.push(pushV[push_id]);
					if (popV[pop_id] == pushV[push_id++])
						break;
        		}
        	}else{
        		// the popV cannot be the pop sequence of pushV
        		return false;
        	}
        }
        // popV matched
        return true;
    }
};

// int main(void){
// 	int n;
// 	Solution sol;
// 	while(cin>>n){
// 		vector<int> a(n);
// 		for(auto &item:a){
// 			cin>>item;
// 		}
// 		vector<int> b(n);
// 		for(auto &item : b){
// 			cin>>item;
// 		}

// 		cout<<(sol.IsPopOrder(a, b)?"true":"false")<<endl;
// 	}
// }