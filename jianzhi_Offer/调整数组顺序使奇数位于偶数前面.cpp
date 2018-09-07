#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	// bitmap
	// Wrong
	void reOrderArray_wrong(vector<int>& array){
		if(array.empty())
			return;
		int n = array.size();
		vector<int> mask((n+32-1)/32, 0);
		for(int i=0; i<n; i++){
			// set the bit mapping to the odd number to 1
			if(array[i]%2 != 0){
				int no = i>>5;
				mask[no] |= 1 << (i&0x1f);
			}
		}
		// count all 1s in the binary code
		int count_1 = 0;
		for(int i=0;i<mask.size();i++){
			while(mask[i]){
				if(mask[i]&1)
					count_1++;
				mask[i] &= mask[i]-1;
			}
		}
		vector<int> res(n, 0);
		int t=0;
		for(int i=0; i<mask.size(); i++){
			int no = i;
			for(int k=0; k<32; k++){
				if (no + k < n) {
					if (mask[no] & (1 << k))
						res[t++] = array[no<<5 + k];
					else
						res[count_1++] = array[no<<5 + k];
				}
			}
		}
		array.swap(res);
	}

	// double pointers
	// head and tail pointers
	// cannot make sure that relative order between two odds or evens
	void reOrderArray(vector<int>& array){
		if(array.empty())
			return;

		int n = array.size();
		int head=0, tail=n-1;
		while(head<tail){
			while(head<tail && (array[head]&0x1)!=0)
				head++;
			while(head<tail && (array[tail]&0x1)==0)
				tail--;
			if(head<tail)
				mySwap(array[head], array[tail]);
		}
	}

	// use function pointer to determine the ruler that 
	// cannot make sure that relative order between two odds or evens
	void reOrderArray_FuncPointer(vector<int>& array, bool (*func)(int)){
		if(array.empty())
			return;
		int n = array.size();
		int head=0, tail=n-1;
		while(head<tail){
			while(head<tail && !func(array[head]))
				head++;
			while(head<tail && func(array[tail]))
				tail--;
			if(head<tail)
				mySwap(array[head], array[tail]);
		}
	}

	// O(n^2)
	void reOrderArray_right(vector<int>& array){
		if(array.empty())
			return;
		for(int i=0;i<array.size();i++){
			for(int j=array.size()-1; j>i; j--){
				if((array[j-1]&0x1)==0 && (array[j]&0x1)!=0)
					mySwap(array[j-1], array[j]);
			}
		}
	}
private:
	void mySwap(int &a, int &b){
		a = a^b;
		b = a^b;
		a = a^b;
	}
};

int main(void) {
	vector<int> a{ 1,2,3,4,5,6,7,8,9,10 };
	cout << "before:" << endl;
	for (auto item : a)
		cout << item << " ";
	cout << endl;
	Solution sol;
	sol.reOrderArray(a);
	cout << "after:" << endl;
	for (auto item : a)
		cout << item << " ";
	cout << endl;
	return 0;
}