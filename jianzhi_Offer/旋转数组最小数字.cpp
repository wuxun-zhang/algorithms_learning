#include<iostream>
#include<vector>
// �����ؼ��㣺����
// 1.��ת����Ϊ0
// 2.�м�Ԫ��������Ԫ����ȣ��޷��жϵ������ڵ�һ���������黹�ǵڶ����������飬��ʱӦ����˳����ҷ��ҳ���Сֵ
// ʱ�临�Ӷ�log2(n)
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