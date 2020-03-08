#include<iostream>
using namespace std;


int gcd(int a, int b){
	if(a == 0)
		return b;
	if(b == 0)
		return a;

	if(a<b){
		int temp = a;
		a = b;
		b = temp;
	}

	while(b!=0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
//
//int main(){
//	int a, b;
//	while(cin>>a>>b){
//		cout<<"gcd(a, b) = "<<gcd(a, b)<<endl;
//	}
//	return 0;
//}