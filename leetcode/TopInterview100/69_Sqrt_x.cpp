#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
	// binary search
    int mySqrt(int x) {
    	if(1 == x)
    		return x;
  		double left=0, right=static_cast<double>(x);
  		double mid = (left+right)/2;
  		while(_is_a_ne_b_(POWER2(mid), static_cast<double>(x))){
  			if(_is_a_gt_b_(POWER2(mid), static_cast<double>(x)))
  				right = mid;
  			else
  				left = mid;
  			mid = (left+right)/2;
  		}
  		return static_cast<int>(mid);
    }

    // find the last value whose square is not less than the given input x
    int _mySqrt_x(int x){
    	if(x<=1)
    		return x;
    	int left=0, right=x;
    	while(left<right){
    		// avoiding overflow
    		int64_t mid = (right-left)/2 + left;
    		if((mid+1)*(mid+1) <= x)
    			left = mid + 1;
    		else
    			right = mid;
		}
		return static_cast<int>(left);
    }

    // Newton's iteration method
    // f(x) = x^2-n --> f'(x)=0 -->
    // x2 = (x1+n/x1)/2
    int _01_mySqrt_x(int n){
    	int64_t res=n;
    	while(res*res > n){
    		res = (res + n/res) / 2;
    	}
    	return res;
    }
private:
	static constexpr double eps = 0.001;
	static inline bool _is_a_ne_b_(double a, double b){
		return (abs(a-b)>eps);
	}

	static inline bool _is_a_gt_b_(double a, double b){
		return (a-b>eps);
	}

	static inline double POWER2(double x){
		return pow(x, 2);
	}
};


// int main(void){
// 	Solution sol;
// 	int x;
// 	while(cin>>x){
// 		cout<<"The square root of "<<x<<" is "<<sol._mySqrt_x(x)<<endl;
// 	}
// }