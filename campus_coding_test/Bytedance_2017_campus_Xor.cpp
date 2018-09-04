#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Xor
{
public:
	Xor();
	~Xor();
	// find the total number of the xor results
	int findNumGTm(vector<int>& num, int m){
		int len=num.size();
		sort(num.begin(), num.end());
		int count=0;
		for(int i=0;i<num-1;i++){
			for(int j=i+1;j<num;j++){
					
			}
		}
	}
};

int main(void){
	int n, m;
	while(cin>>n>>m){
		vector<int> num(n);
		for(auto& item : num)
			cin>>item;
		Xor obj;
		cout<<obj.findNumGTm(num, m)<<endl;
	}
	return 0;
}