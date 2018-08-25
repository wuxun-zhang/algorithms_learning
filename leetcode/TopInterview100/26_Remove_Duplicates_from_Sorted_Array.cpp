#include <vector>
#include <algorithm>
using namespace std;

// two pointers

class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		if(nums.empty())
			return 0;
		int count = 1;
		int cur=0;
		for(int i=1; i<nums.size(); i++){
			if(nums[i] != nums[cur]){
				count++;
				cur = i;
			}
			else{
				nums.erase(nums.begin()+i, nums.begin()+i+1);
				i--;
			}
		}
		return count;
	}

	int removeDuplicates_v2(vector<int>& nums){
		int length = nums.size();
		if(length<2)
			return length;
		int current_empty_index = 1;
		for(int i=1; i<length; i++){
			// boundary
			if(nums[i] > nums[i-1]){
				// value assignment only
				num[current_empty_index] = nums[i];
				current_empty_index++;
			}
		}
		return current_empty_index;
	}
};