#include<iostream>
using namespace std;

int NumberOf1(int n) {
	int count = 0;
	while (n) {
		n &= (n - 1);
		count++;
	}
	return count;
}

////int main(void) {
//	int n;
//	while (cin >> n) {
//		cout << "number of 1: " << NumberOf1(n) << endl;
//	}
//	return 0;
//}