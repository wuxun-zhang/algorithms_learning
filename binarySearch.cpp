#include<iostream>
#include<vector>
using namespace std;

class _Binary_Search_{
public:
	// the input array is in the order(default ascend)
	// non-recursive
	int non_recursive(vector<int>& array, int target){
		if(array.empty())
			return -1;
		int left=0, right=array.size()-1;
		while(left<=right){
			int mid = (right-left)/2 + left;
			if(array[mid]>target)
				right = mid-1;
			else if(array[mid]<target)
				left = mid+1;
			else
				return mid;
		}
		return -1;
	}

	// recursive
	int recursive(vector<int>& array, int start, int end, int target){
		if(start<=end){
			int mid = start + (end-start)/2;
			if(array[mid] == target)
				return mid;
			else if(array[mid] > target)
				return recursive(array, start, mid-1, target);
			else
				return recursive(array, mid+1, end, target);
		}else
			return -1;
	}
};