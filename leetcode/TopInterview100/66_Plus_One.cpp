#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> carry_flag(n, 0);
        int i;
        for(i=0; i<n; i++){
        	if(digits[i] == 9)
        		carry_flag[i] = 1;
        }

        if(!carry_flag[n-1]){
        	digits[n-1]++;
        	return digits;
        }
        digits[n-1] = 0;
        for(i=n-2; i>=0; i--){
        	if(carry_flag[i+1])
        		digits[i] = (digits[i]+1==10) ? 0 : (++digits[i]);
        	else{
        		break;
        	}
        }	
        if(!carry_flag[0])
        	return digits;

        vector<int> new_digits(1, 0);
        if(carry_flag[0]){
        	new_digits[0] = 1;
        	new_digits.insert(new_digits.end(), digits.begin(), digits.end());
        }
        return new_digits;
    }

    // from right to left
    // no need to store carry information
    // because we can scan element in array inversely, unlike linked list!!!
    vector<int> _01_plusOne(vector<int>& digits){
        for(int i=digits.size()-1; i>=0;i--){
            if(digits[i] != 9){
                digits[i]++;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// int main(void){
// 	int n;
// 	while(cin>>n){
// 		vector<int> a(n);
// 		for(auto &item : a){
// 			cin>>item;
// 		}
// 		Solution sol;
// 		a = sol._01_plusOne(a);
// 		for(auto item : a)
// 			cout<<item<<" ";
// 		cout<<endl;
// 	}
// 	return 0;
// }