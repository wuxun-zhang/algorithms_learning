#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
count prime numbers(>1) less than the given number
***** sieve-of-Eratosthenes method

Let A be an array of Boolean values, indexed by integers 2 to n,
initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding √n:
  if A[i] is true:
    for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n :
      A[j] := false
 
Output: all i such that A[i] is true.

*/

class CountPrimes{
public:
	int countPrimes(int n){
		int count = 0;
		vector<bool> flags(n-1, true);
		flags[0] = false;
		int limit = sqrt(n);
		for(int i=2; i<=limit; i++){
			if(flags[i-1]){
				// the multiple of a prime must not be a prime number!!!!
				for(int j=i*i; j<n; j+=i){
					flags[j-1] = false;
				}
			}
		}
		for(int i=0;i<n-1;i++){
			if(flags[i])
				count++;
		}
		return count;
	}
};

int main(void){
	int n;
	CountPrimes p;
	while(cin>>n){
		cout<< p.countPrimes(n) <<endl;
	}
	return 0;
}