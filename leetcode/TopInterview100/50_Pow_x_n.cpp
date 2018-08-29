/*
Implement pow(x, n), which calculates x raised to the power n (x^n).
*/
#include<iostream>
using namespace std;

class Solution
{
public:
	double myPow(double x, int n){
		double res = 1.0;
		// the result is approching zero
		// it doesn't matter adding 2 on n
		if(n == INT_MIN)
			n += 2;
		int tempN = abs(n);
		for(int i=31; i>=0; i--){
			res *= res;
			if(tempN & (1<<i))
				res *= x;
		}

		if(n<0)
			res = 1/res;
		return res;
	}

	double myPow_v2(double x, int n){
		if(n<0)
			return 1/power(x, -n);
		return power(x, n);
	}	
	// recursive
	double myPow_v3(double x, int n){
		if(n==0)
			return 1;
		double half = myPow_v3(x, n/2);
		if(n%2==0)
			return half*half;
		else if(n>0){
			return half*half*x;
		}else{
			return half*half/x;
		}
	}

	// wrong answer when n == INT32_MIN
	double myPow_v4(double x, int n){
		// avoiding large number overflow
		if(n == INT_MIN)
			n+=2;
		return n>0 ? quickPow(x, n) : (1.0/quickPow(x, -n));
	}

private:
	// recursive
	double power(double x, int n){
		if(n==0)
			return 1;
		double half = power(x, n/2);
		if(n%2==0)
			return half*half;
		return x*half*half;
	}

	double quickPow(double x, int n){
		double ans = 1.0;
		while(n){
			if(n&1)
				ans *= x;
			x = x*x;
			n >>= 1;
		}
		return ans;
	}
};


//int main(void)
//{
//	double a;
//	int b;
//	Solution sol;
//	while (cin >> a >> b) {
//		cout << sol.myPow_v4(a, b) << endl;
//	}
//}