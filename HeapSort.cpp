#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void mySwap(T& a, T& b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

class Solution {
public:
	void heapSort(vector<int>& num) {
		int length = num.size();
		int start = length / 2 - 1;
		for (int index = start; index >= 0; index--) {
			maxHeap(num, index, length-1);
		}
		for (int index = length - 1; index > 0; index--) {
			mySwap(num[0], num[index]);
			maxHeap(num, 0, index - 1);
		}
	}
private:
	void minHeap(vector<int>& num, int start, int end) {
		int lchild;
		while (1) {
			lchild = 2 * start + 1;
			if (lchild > end)
				break;
			if (lchild + 1 <= end && num[lchild] > num[lchild + 1])
				lchild += 1;
			if (num[start] > num[lchild]) {
				mySwap(num[start], num[lchild]);
				start = lchild;
			}
			else {
				break;
			}
		}
	}
	void maxHeap(vector<int>& num, int start, int end) {
		int lchild;
		while (1) {
			lchild = 2 * start + 1;
			if (lchild > end)
				break;
			if (lchild + 1 <= end && num[lchild] < num[lchild + 1])
				lchild += 1;
			if (num[start] < num[lchild]) {
				mySwap(num[start], num[lchild]);
				start = lchild;
			}
			else {
				break;
			}
		}
	}

};


//int main(void) {
//	vector<int> num{ 0,2,3,1,6,7,5,4,0 };
//	Solution sol;
//	sol.heapSort(num);
//	for (auto& item : num) {
//		cout << item << " ";
//	}
//	cout << endl;
//	return 0;
//}