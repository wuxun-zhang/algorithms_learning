#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	double findMedianNumberInSortedTwoArrays(vector<int>& nums1, vector<int>& nums2){
		if(nums1.empty())
			return getMidNumber(nums2);
		if(nums2.empty())
			return getMidNumber(nums1);

		int len1 = nums1.size(), len2 = nums2.size();
		if(nums1[len1-1]<=nums2[0]){
			
		}
	}

	// binary search
	// O(log(m+n))
	double _01_findMedianNumberInSortedTwoArrays(vector<int>& nums1, vector<int>& nums2){
		int m = nums1.size(), n = nums2.size();
		if(m<n)
			return _01_findMedianNumberInSortedTwoArrays(nums2, nums1);
		if(n == 0)
			return ((double)nums1[(m-1)/2] + (double)nums1[m/2])/2.0;
		int low=0, high=2*n;
		while(low<=high){
			int mid2 = (low+high)/2;
			int mid1 = m+n-mid2;
			double L1= (mid1==0)?INT_MIN : nums1[(mid1-1)/2];
			double L2= (mid2==0)?INT_MIN : nums2[(mid2-1)/2];
			double R1= (mid1==2*m)?INT_MAX : nums1[mid1/2];
			double R2= (mid2==2*n)?INT_MAX : nums2[mid2/2];

			if(L1 > R2)
				low = mid2+1;
			else if(L2 > R1)
				high = mid2 - 1;
			else
				return (max(L1, L2) + min(R1, R2))/2.0;
		}
		return -1.0;
	}
private:
	// find the median number of a sorted array
	inline double getMedianNumber(vector<int>& array){
		if(array.empty())
			return -1.0;
		int len = array.size();
		if(len % 2 == 1)
			return (double)array[len/2];
		else
			return (array[len/2-1]+array[len/2])/2.0;
	}
};