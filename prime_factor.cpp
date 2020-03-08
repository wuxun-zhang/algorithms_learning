#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

// get all the factors of a number
vector<int> factorOfNumber(int num){
	vector<int> res;
	if(num == 1)
		return vector<int>{1};
	if(num == 2)
		return vector<int>{1,2};
	res.push_back(1);
	res.push_back(num);
	for(int i = 2; i<=sqrt(num);i++){
		if(num % i == 0){
			res.push_back(i);
			if(num/i != i)
				res.push_back(num/i);
		}
	}	
	// acesend order
	sort(res.begin(), res.end());
	return res;
}

// Perfect: the sum of all factors of num equals the value of num
// e.g. 6 has 1,2,3,6 factors, and 6=1+2+3, so 6 is a perfect number
bool isPerfectNum(int num){
	vector<int> factors;
	factors = factorOfNumber(num);
	int s = accumulate(factors.begin(), factors.end(), 0);
	return (s-num==num)?true:false;
}


// int main(void){
// 	int n;
// 	while(cin>>n){
// 		vector<int> result = factorOfNumber(n);
// 		cout << n << " is a perfect number? " << (isPerfectNum(n) ? "true" : "false") << endl;
// 		for(auto item : result){
// 			cout<<item<<" ";
// 		}
// 		cout<<endl;
// 	}
// }