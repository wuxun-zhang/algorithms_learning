#include<iostream>
using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		if(x<0)
			return false;
		int y = x;
		int x_ref = 0;
		while(y){
			x_ref = 10*x_ref + y%10;
			y /= 10;
		}
		return x_ref == x;
	}

	bool isPalindrome_v2(int x){
		if(x<0)
			return false;
		int res=0;
		int orgin=x;
		while(x){
			int temp = res*10 + x%10;
			if(temp/10 != res)
				return false;
			res = temp;
			x /= 10;
		}
	}

	// compare the first digit with the last digit
	// e.g 1221 -> 1 and 1, 2 and 2	(true)
	// 1889	-> 1 and 9, 8 and 8	(false)
	bool isPalindrome_v3(int x){
		if(x<0)
			return false;
		int div=1;
		while(x/div>=10)
			div*=10;
		while(x>0){
			int left = x/div;
			int right = x%10;
			if(left != right)
				return false;
			x = (x%div)/10;
			div /= 10;
		}
		return true;
	}

	// *** trick ***
	// compare the first half part with the second half part
	bool isPalindrome_v4(int x){
		if(x<0 || (x%10 == 0 && x!=0))
			return false;
		int revertNum = 0;
		while(x>revertNum){
			revertNum = revertNum*10 + x%10;
			x /= 10;
		}
		return x == revertNum || x == revertNum/10;
	}

	bool isPalindrome_v5(int x){
		if(x<0 || (x%10==0 && x!=0))
			return false;
		return reverse(x) == x;
	}

private:
	int reverse(int x){
		int res = 0;
		while(x){
			if(res>INT_MAX/10)
				return -1;
			res = res*10 + x%10;
			x /= 10;
		}
		return res;
	}
};