#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> myMap;
        for(int i=0;i<nums.size(); i++){
            if(myMap.find(nums[i]) != myMap.end()){
                return vector<int>{myMap.find(nums[i])->second, i};
            }else{
                myMap.insert(make_pair(target - nums[i], i));
            }
        }
        return vector<int>{};
    }
};

int main(void){
    Solution sol;
    int n, target;
    cin>>n>>target;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> result = sol.twoSum(a, target);
    if(!result.empty()){
        cout<<result[0]<<" "<<result[1]<<endl;
    }
    return 0;
}