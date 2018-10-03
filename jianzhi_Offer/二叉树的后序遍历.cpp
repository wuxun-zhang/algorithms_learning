#include<iostream>
#include<vector>
using namespace std;

// 

class Solution {
public:
	// verify if the given sequence is post-order sequence of BST
    bool VerifySquenceOfBST(vector<int> sequence) {
    	if(sequence.empty())
    		return false;
    	return helper(sequence, 0, sequence.size()-1);
    }
private:
	bool helper(vector<int>& sequence, int start, int end){
		if(start>end)
			return true;
		int left = start, right = end;
		while(left<=right && sequence[left]<sequence[right])
			left++;
		for(int i=left; i<right; i++){
			if(sequence[i]<sequence[right])
				return false;
		}
		// search the two parts
		return helper(sequence, start, left-1) && helper(sequence, left, end-1);
	}
};

// int main(void){
// 	int n;
// 	Solution sol;
// 	while(cin>>n){
// 		vector<int> a(n);
// 		for(auto &item : a){
// 			cin>>item;
// 		}
// 		cout<<(sol.VerifySquenceOfBST(a)?"true":"false")<<endl;
// 	}
// 	return 0;
// }
