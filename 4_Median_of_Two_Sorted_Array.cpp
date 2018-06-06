#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	// 空间、时间复杂度都是O(m+n)
	double findMedianSortedArrays_v1(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int>::size_type m = nums1.size(), n = nums2.size();
		vector<int> c(m + n);
		unsigned int i = 0, j = 0, t = 0;
		while (i < m || j < n)
		{
			if (i < m && j < n)
			{
				if (nums1[i] > nums2[j])
					c[t++] = nums2[j++];
				else
					c[t++] = nums1[i++];
				continue;
			}
			while (i < m)
				c[t++] = nums1[i++];
			while (j < n)
				c[t++] = nums2[j++];
		}
		if ((m + n) % 2 == 0)
			return ((c[(m + n - 1) / 2] + c[(m + n - 1) / 2 + 1]) / 2.0);
		else
			return (double)c[(m + n) / 2];
	}
	double findMedianSortedArrays_v2(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int>::size_type m = nums1.size(), n = nums2.size();
		if (m > n)
		{
			vector<int> temp = nums1;
			nums1.swap(nums2);
			nums2.swap(temp);
			int t = m;
			m = n;
			n = t;
		}
		if (n == 0)
			return -1.0;
		int imin = 0, imax = m, half_len = (m + n + 1) / 2;
		int max_of_left, min_of_right;
		while (imin <= imax)
		{
			int i = (imin + imax) / 2;
			int j = half_len - i;
			if (i < m && nums2[j - 1] > nums1[i])
				imin = i + 1;
			else if (i > 0 && nums1[i - 1] > nums2[j])
				imax = i - 1;
			else
			{
				if (i == 0)
					max_of_left = nums2[j - 1];
				else if (j == 0)
					max_of_left = nums1[i - 1];
				else
					max_of_left = max(nums1[i - 1], nums2[j - 1]);

				if ((m + n) % 2 == 1)
					return (double)max_of_left;

				if (i == m)
					min_of_right = nums2[j];
				else if (j == n)
					min_of_right = nums1[i];
				else
					min_of_right = min(nums1[i], nums2[j]);

				return (min_of_right + max_of_left) / 2.0;
			}
		}
		return -1.0;
	}
};

//void main()
//{
//	vector<int> a, b;
//	int m, n;
//	Solution sol;
//	while (cin >> m >> n)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			int temp;
//			cin >> temp;
//			a.push_back(temp);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			int temp;
//			cin >> temp;
//			b.push_back(temp);
//		}
//		cout << sol.findMedianSortedArrays_v2(a, b) << endl;
//	}
//}