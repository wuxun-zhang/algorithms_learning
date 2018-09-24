#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 

class Solution {
public:
    // code duplication happens, such as tag1, tag2 and tag3
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
        	return -1;
        int max_val = INT_MIN;
        int sum = 0;
        for(int i=0; i<array.size(); i++){
            // tag3
        	if(i>0){
        		if(array[i]>=0){
                    // tag1
        			if(sum<0) 
        				sum = array[i];
        			else // tag2
        				sum += array[i]; 
        		}
        		else{
                    // tag1
        			if(sum+array[i]<0)
        				sum = array[i];
        			else{ // tag2
        				sum += array[i];
        			}
        		}	
        		max_val = max(max_val, sum);
        	}else{ // tag3
        		sum += array[i];
        		max_val = max(max_val, sum);
        	}
        }
        return max_val;
    }

    // simple but wise solution
    int _01_FindGreatestSumOfSubArray(vector<int>& array){
        if(array.empty())
            return 0;
        int curSum = 0;
        int max_val = INT_MIN;
        for(int i=0; i<array.size();i++){
            if(curSum<=0){
                curSum = array[i];
            }else{
                curSum += array[i];
            }
            max_val = max(max_val, curSum);
        }
        return max_val;
    }
};


// int main(int argc, char const *argv[])
// {
// 	int n;
// 	while(cin>>n){
// 		vector<int> a(n);
// 		for(int i=0;i<n;i++)
// 			cin>>a[i];
// 		Solution sol;
// 		cout<<sol.FindGreatestSumOfSubArray(a)<<endl;
// 	}
// 	return 0;
// }