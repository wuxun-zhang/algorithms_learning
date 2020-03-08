#include<iostream>
using namespace std;

// ax + by = gcd(a, b) = d
// x = ?
int extend_gcd(int a, int b, int& x, int& y){
	if(b == 0){
		x=1;
		y=0;
		return a;
	}
	int r = extend_gcd(b, a%b, x, y);
	int temp = x;
	x = y;
	y = temp - a/b*y;
	return r;
}

//
//int main(){
//	int a, b;
//	while(cin>>a>>b){
//		cout<<"gcd(a, b) = "<<gcd(a, b)<<endl;
//	}
//	return 0;
//}