#include<iostream>
#include<vector>
using namespace std;

// tips：异或
// 1：一个数与0异或，还是等于本身
// 2：一个数与其本身异或等于0
// -> 一个与另外一个数异或两次，还是等于本身

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (auto& item : nums)
			result ^= item;
		return result;
	}
private:
	
};