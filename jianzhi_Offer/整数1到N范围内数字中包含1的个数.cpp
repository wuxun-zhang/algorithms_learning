#include<iostream>
#include<string>
// #include<vector>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n){
  		if(n==0)
  			return 0;
  		string strN = to_string(n);
  		return numberOf1(strN);      
    }
private:
	int numberOf1(string strN){
		if(strN.empty() || strN[0]<'0' || strN[0]>'9')
			return 0;
		int first = strN[0] - '0';
		unsigned int length = static_cast<unsigned int>(strN.size());
		if(length==1 && first==0)
			return 0;
		if(length==1 && first>=1)
			return 1;
		// the most significant bit
		// the MSB is 1 or not
		int numFirstDigit=0;
		if(first==1)
			numFirstDigit = stoi(strN.substr(1)) + 1;
		else if(first > 1)
			numFirstDigit = PowerBase10(length-1);
		// except the most significant bit
		int numOtherDigits = first * (length-1) * PowerBase10(length-2);
		// discard the MSB, then recursively find the number of 1 
		int numRecursive = numberOf1(strN.substr(1));
		
		return numFirstDigit + numOtherDigits + numRecursive;
	}

	static inline int PowerBase10(int n){
		int res = 1;
		for(int i=0; i<n; i++)
			res *= 10;
		return res;
	}
};

// int main(void){
// 	Solution sol;
// 	int n;
// 	while(cin>>n){
// 		cout<<"The number of 1 in "<<n<<" is "<<sol.NumberOf1Between1AndN_Solution(n)<<endl;
// 	}
// }
