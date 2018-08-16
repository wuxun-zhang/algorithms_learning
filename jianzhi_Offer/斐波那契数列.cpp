#include<iostream>
#include<chrono>
using namespace std;

// for-loop
long long Fibonacci_v1(int n) {
	if (n<0) {
		return -1;
	}
	else if (n == 0)
	{
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	long long sum = 0;
	long long prev = 0, next = 1;
	for (int i = 2; i <= n; i++) {
		sum = prev + next;
		prev = next;
		next = sum;
	}
	return sum;
}

// recursive
int Fibonacci_v2(int n) {
	if (n < 0)
		return -1;
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	return Fibonacci_v2(n-1) + Fibonacci_v2(n-2);
}

//int main() {
//	int n;
//	while (cin >> n) {
//		cout << "Fibonacci_v1: " << Fibonacci_v1(n) << endl;
//		cout << "Fibonacci_v2: " << Fibonacci_v2(n) << endl;
//	}
//}