#include<iostream>
#include<vector>
using namespace std;

bool is_utf8(vector<int>& nums)
{
	unsigned int nBytes = 0;
	bool bAllAscii = true;
 
	for (auto digit : nums){
		if (nBytes == 0 && (digit & 0x80) != 0){
			bAllAscii = false;
		}
 
		if (nBytes == 0) {
			if (digit >= 0x80) {
 
				if (digit >= 0xFC && digit <= 0xFD){
					nBytes = 6;
				}
				else if (digit >= 0xF8){
					nBytes = 5;
				}
				else if (digit >= 0xF0){
					nBytes = 4;
				}
				else if (digit >= 0xE0){
					nBytes = 3;
				}
				else if (digit >= 0xC0){
					nBytes = 2;
				}
				else{
					return false;
				}
 
				nBytes--;
			}
		}
		else{
			if ((digit & 0xC0) != 0x80){
				return false;
			}
			nBytes--;
		}
	}
 
	if (nBytes != 0)  {
		return false;
	}
 
	if (bAllAscii){
		return true;
	}
 
	return true;
}

int main(void){

	int N;
	while(cin>>N){
		vector<int> a(N);
		for(auto &item : a)
			cin>>item;
		cout<<(is_utf8(a)?1:0)<<endl;
	}
	return 0;
}