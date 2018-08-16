#include<iostream>
#include<vector>
// 两个关键点：：：
// 1.旋转个数为0
// 2.中间元素与两端元素相等，无法判断到底属于第一个递增数组还是第二个递增数组，此时应采用顺序查找法找出最小值
// 时间复杂度log2(n)
using namespace std;
class Solution {
public:
	int minNumberInRotatedArray(vector<int>& rotateArray) {
		if (rotateArray.empty()) {
			return -1;
		}
		int start = 0, end = rotateArray.size() - 1;
		int midIndex = start;
		while (rotateArray[start] >= rotateArray[end]) {
			if (end - start == 1) {
				midIndex = end;
				break;
			}
			midIndex = (start + end) / 2;
			if (rotateArray[midIndex] == rotateArray[end] && rotateArray[midIndex] == rotateArray[start]) {
				return MinInOrder(rotateArray, start, end);
			}
			if (rotateArray[midIndex] >= rotateArray[start]) {
				start = midIndex;
			}
			else if (rotateArray[midIndex] <= rotateArray[end]) {
				end = midIndex;
			}
		}
		return rotateArray[midIndex];
	}
private:
	int MinInOrder(vector<int>& array, int start, int end) {
		int minV = INT32_MAX;
		for (int i = start; i <= end; i++) {
			if (array[i] < minV) {
				minV = array[i];
			}
		}
		return minV;
	}
};


//int main(void) {
//	int n;
//	Solution sol;
//	while (cin >> n) {
//		vector<int> array(n, 0);
//		for (int i = 0; i < n; i++)
//			cin >> array[i];
//		cout << sol.minNumberInRotatedArray(array) << endl;
//	}
//}