/*
Given two arrays, write a function to compute their intersection
*/

class Solution{
public:
	// STL
	// Space complexity: O(m+n)
	// Time complexity: O(mlogm+nlogn)
	vector<int> intersect(vector<int>& num1, vector<int>& num2){
		if(num1.empty() || num2.empty())
			return vector<int>{};
		vector<int> result(num1.size()+num2.size());

		sort(num1.begin(), num2.end());
		sort(num1.begin(), num2.end());

		vector<int>::iterator it = set_intersection(num1.begin(), num1.end(),
			num2.begin(), num2.end(), result.begin());
		result.resize(it-result.begin());
		return result;		
	}

	// Hash Table
	// Time: O(n)
	vector<int> intersect_v2(vector<int>& nums1, vector<int>& nums2){
		// int len1 = nums1.size();
		// int len2 = nums2.size();
		unordered_map<int, int> nums1Map;
		vector<int> result;

		// for(int i=0; i<len1; i++){
		// 	if(nums1Map.find(nums1[i]) == nums1Map.end())
		// 		nums1Map[nums1[i]] = 1;
		// 	else
		// 		nums1Map[nums1[i]]++;
		// }

		for(auto a : nums1)
			nums1Map[a]++;
		for(auto a : nums2){
			if(nums1Map[a]-- > 0)
				result.push_back(a);
		}

		// for(int i=0; i<len2; i++){
		// 	if(nums1Map.find(nums2[i]) != nums1Map.end()){
		// 		if(nums1Map[nums2[i]] > 0){
		// 			result.push_back(nums2[i]);
		// 			nums1Map[nums2[i]]--;
		// 		}
		// 	}
		// }
		return result;
	}

	// double pointers
	// binary search
	vector<int> intersect_v3(vector<int>& nums1, vector<int>& nums2){
		int len1 = nums1.size();
		int len2 = nums2.size();
		if(!len1 || !len2)
			return vector<int>{};
		// o(nlogn)
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		int i=0, j=0;
		while(i<len1 && j<len2){
			if(nums1[i] == nums2[j]){
				result.push_back(nums2[j]);
				i++;
				j++;
			}else if(nums1[i]>nums2[j]){
				j++;
			}
			else{
				i++;
			}	
		}
		return result;
	}
};