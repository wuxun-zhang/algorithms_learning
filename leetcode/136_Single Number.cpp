#include<iostream>
#include<vector>
using namespace std;

// tips�����
// 1��һ������0��򣬻��ǵ��ڱ���
// 2��һ�������䱾��������0
// -> һ��������һ����������Σ����ǵ��ڱ���

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