/*
calculate (a^b)%c, where a, b are very large number
maybe overflow
*/

#include<iostream>
using namespace std;

class Solution{
public:
	int quick(int a, int b, int c){
		int ans = 1;
		a = a%c;
		while(b){
			if(b&1)
				ans = (ans*a)%c;
			b >>= 1;
			a = (a*a)%c;
		}
		return ans;
	}
};