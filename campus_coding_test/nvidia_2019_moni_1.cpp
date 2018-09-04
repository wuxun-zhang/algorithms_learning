#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

double Sum(int x, int n) {
	double res = 0.0;
	double x_ref = x;
	while (n) {
		double root = sqrt(x_ref);
		res += x_ref;
		x_ref = root;
		n--;
	}
	return res;
}

void printFlowerNum(int m, int n) {
	for (int i = m; i <= n; i++) {
		int ge = i % 10;
		int shi = i / 10 % 10;
		int bai = i / 100;
		if (pow(ge, 3) + pow(shi, 3) + pow(bai, 3) == i)
			cout << i << " ";
	}
	cout << endl;
}

double findMinDis(vector<int>& pos, int len){
	int num = pos.size();
	int maxDist=INT_MIN;
	sort(pos.begin(), pos.end());
	int pre = pos[0];
	for(int i=1;i<num;i++){
		if(pos[i]-pre>maxDist)
			maxDist=pos[i]-pre;
		pre = pos[i];
	}
	double res = max(maxDist/2.0, double(pos[0]));
	res = max(res, double(len-pos[num-1]));
	return res;
}

// int main(void){
// 	int n, len;
// 	while(cin>>n>>len){
// 		vector<int> posi(n);
// 		for(int i=0;i<n;i++)
// 			cin>>posi[i];
// 		cout<<fixed<<setprecision(2)<<findMinDis(posi, len)<<endl;
// 	}
// 	return 0;
// }