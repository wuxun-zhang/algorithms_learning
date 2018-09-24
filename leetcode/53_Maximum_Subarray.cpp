#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
        	return -1;
        int current = 0;
        int greatest = INT32_MIN;
        // like greedy algorithm
        for(int i=0; i<nums.size(); i++){
        	if(current<=0){
        		current = nums[i];
        	}else{
        		current += nums[i];
        	}
        	greatest = max(greatest, current);
        }
        return greatest;
    }

    // Divide and Conquer Approach
    // firstly, divide the whole array into two subarrays
    // then find the continous subarray's greatest sum of these two parts 
    int _01_maxSubArray(vector<int>& nums){
    	if(nums.epmty())
    		return 0;
    	return helper(nums, 0, nums.size()-1);
    }

private:
	int helper(vector<int>& nums, int left, int right){
		if(left>=right)
			return nums[left];
		int mid = left + (right-left)/2;
		int lmax = helper(nums, left, mid-1);
		int rmax = helper(nums, mid+1, right);
		// from the mid, scan the array in two directions
		int mmax = nums[mid], t = mmax;
		for(int i=mid-1; i>=left; i--){
			t+=nums[i];
			mmax = max(mmax, t);
		}
		t = mmax;
		for(int i=mid+1; i<=right; i++){
			t+=nums[i];
			mmax = max(mmax, t);
		}
		return max(mmax, max(lmax, rmax));
	}
};