#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	// Time Complexity: O(n^2)
	int canCompleteCircuit_v1(vector<int>& gas, vector<int>& cost){
		int num = gas.size();
		// traverse the whole list
		int startIndex = 0;
		for(; startIndex<num; startIndex++){
			int curGas = 0;
			int j=0;
			for(; j<num; j++){
				int id = (startIndex+j)%num;
				curGas += gas[id];
				if(curGas < cost[id])
					break;
				curGas -= cost[id];
			}
			if(j==num && curGas>=0)
				return startIndex;
		}
		return -1;
	}

	// the start point that meet requirement is exist only
	// when the total amount of gas is no less than(>=) the 
	// amount of costs
	// Time Compexity: O(n)
	int canCompleteCircuit_v2(vector<int>& gas, vector<int>& cost){
		int start=0, netGasSum=0, curGasSum=0;
		for(int i=0; i<cost.size(); i++){
			netGasSum += gas[i] - cost[i];
			curGasSum += gas[i] - cost[i];
			if(curGasSum<0){
				start = i+1;
				curGasSum=0;
			}
		}
		if(netGasSum<0)
			return -1;
		return start;
	}

	int canCompleteCircuit_v3(vector<int>& gas, vector<int>& cost){
		int total=0, mx=-1, start=0;
		for(int i=gas.size()-1; i>=0; i--){
			// the amount of remaining gas currently
			total += gas[i]-cost[i];
			// mx: record the existed max amount of remaining gas
			if(total>mx){
				start = i;
				mx = total;
			}
		}
		return total<0?-1:start;
	}
};