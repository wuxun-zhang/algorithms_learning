#include<iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		int prev = 1, next = 2;
		int res = 0;
		for (int i = 3; i <= n; i++) {
			res = prev + next;
			prev = next;
			next = res;
		}
		return res;
	}
};