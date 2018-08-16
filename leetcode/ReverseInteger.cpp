#include<iostream>
using namespace std;

int reverseInteger(int x) {
	int sign = x > 0 ? 1 : -1;
	x *= sign;
	int result = 0;
	bool isOverflow = false;
	while (x > 0) {
		int digit = x % 10;
		if (result > (INT32_MAX - digit) / 10 || result<(INT32_MIN-digit)/10) {
			isOverflow = true;
			break;
		}
		result = result * 10 + digit;
		x /= 10;
	}
	if (isOverflow) {
		return 0;
	}
	return result*sign;
}

class Solution {
public:
	int reverse(int x) {
		long long result = 0;
		int sign = mysign(x);
		x *= sign;
		while (x>0) {
			result = 10 * result + (x % 10);
			x /= 10;
		}
		result *= sign;
		if (result > (1 << 31) - 1 || result < -(1 << 31)) {
			result = 0;
		}
		return result & 0xffffffff;
	}
	int reverse_v1(int x) {
		if (x > INT32_MAX)
			return 0;

		int prev;
		int curr = 0;
		while (x != 0) {
			prev = curr;
			curr = (10 * prev) + (x % 10);
			x = x / 10;
		}
		//cout << curr;
		if (curr / 10 != prev) { return 0; }
		return curr;
	}
	int reverse_v2(int x) {
		int result = 0;
		while (true) {
			if (x == 0) break;
			int pop = x % 10;
			x /= 10;
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
				return 0;

			if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8))
				return 0;

			result = result * 10 + pop;
		}

		return result;
	}
private:
	int mysign(int x) {
		return (x>0) ? 1 : -1;
	}
};

//int main(void) {
//	int n;
//	Solution sol;
//	while (cin >> n) {
//		cout << sol.reverse_v2(n) << endl;
//	}
//	return 0;
//}