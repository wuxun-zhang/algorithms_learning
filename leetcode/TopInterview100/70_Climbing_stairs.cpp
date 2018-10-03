#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	// n mab be very small
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

	// if n is a positive number and less than 0x7FFFFFFF
	// we must consider the overflow of the result
	// O(n)
	unsigned int _01_climbStairs(unsigned int n){
		if(n<4)
			return n;
		long long count=0;
		long long pre1=2, pre2=3;
		for(unsigned int i=4; i<=n; i++){
			count = (pre2+pre1) % mode;
			pre1 = pre2;
			pre2 = count;
		}
		return count;
	}

	// O(lg(n))
	// [f(n);f(n-1)] = ([1,1;1,0])^(n-1) * [f(1);f(0)] 
	// 				 = ([1,1;1,0])^(n-2) * [f(2);f(1)]
	unsigned int _02_climbStairs(unsigned int n){
		if(n<2)
			return n;
		vector<vector<int>> factors = {{1,1}, {1,0}};
		vector<vector<int>> res = {{1,0}, {0,1}};
		int p = n-2;
		while(p){
			if(p&0x1)
				res = matMul_bit_0_1(res, factors);
			factors = matMul_bit_0_1(factors, factors);
			p >>= 1;
		}
		return res[0][0] + res[1][0];
	}
private:
	static const unsigned int mode = 0x7FFFFFFF;
	// mat has a 2x2 dimension
	static inline vector<vector<int>> matMul_bit_0_1(vector<vector<int> >& mat1, 
		vector<vector<int> >& mat2){
		int m = mat1.size(), n = mat1[0].size();
		vector<vector<int>> res(m, vector<int>(n, 0));
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					res[i][j]+=mat1[i][k] * mat2[k][j];
				}
			}
		}
		return res;
	}
};

//int main(int argc, char const *argv[])
//{
//	int n;
//	Solution sol;
//	while(cin>>n){
//		cout<<sol._02_climbStairs(n)<<endl;
//	}
//	return 0;
//}