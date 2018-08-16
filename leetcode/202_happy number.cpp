#include<set>

//Starting with any positive integer, replace the number by the sum of the squares of its digits, 
//and repeat the process until the number equals 1 (where it will stay), 
//or it loops endlessly in a cycle which does not include 1. 
//Those numbers for which this process ends in 1 are happy numbers 

// ����������г����ظ���ֵ�����Ҳ�����1����ô������ֽ���unhappy
// ���ѡ�񽫳��ֹ����м���������set�У��Թ���������Ƚ�


class Solution {
public:
	bool isHappy(int x) {
		bool iamhappy = false;
		int sum = 0;
		std::set<int> list;
		while (x) {
			int digit = x % 10;
			sum += digit*digit;
			x /= 10;
			if (x == 0) {
				if (sum == 1)
				{
					iamhappy = true;
					break;
				}
				if (list.find(sum) == list.end())
					list.insert(sum);
				else {
					iamhappy == false;
					break;
				}
				x = sum;
				sum = 0;
			}
		}
		return iamhappy;
	}
};