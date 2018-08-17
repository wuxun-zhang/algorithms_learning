#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void mySwap(T& a, T& b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

template<typename T>
void mySwap_v2(T& a, T& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void myQuickSort(vector<int>& num, int start, int end) {
	if (num.empty()) {
		return;
	}
	if (start >= end) {
		return;
	}
	int key = num[start];
	int low = start, high = end;
	while (low < high) {
		while (low < high&&num[high] >= key) {
			high--;
		}
		num[low] = num[high]; // high��λ���γ�һ�����ӡ�
		while (low < high&&num[low] <= key) {
			low++;
		}
		num[high] = num[low]; // ��high���С���ӡ�
	}
	num[low] = key; // ����ֽ�Ԫ�أ�������ֳɴ��ڡ�С���������֣�
	myQuickSort(num, start, low-1);
	myQuickSort(num, high + 1, end);
}

//int main() {
//	vector<int> a;
//	for (int i = 0; i < 5; i++) {
//		int tmp;
//		cin >> tmp;
//		a.push_back(tmp);
//	}
//	myQuickSort(a, 0, a.size() - 1);
//	for (auto& item : a) {
//		cout << item << " ";
//	}
//	cout << endl;
//	return 0;
//}