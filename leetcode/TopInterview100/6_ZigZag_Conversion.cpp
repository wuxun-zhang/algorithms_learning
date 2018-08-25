#include <iostream>
#include <string>
using namespace std;

//1. determine  

class Solution{
public:
	string convert(string s, int numRows){
		if(s.empty() || numRows<2)
			return s;
		string output = "";
		int length = s.size();
		int stride = numRows + (numRows-2);
		for(int r=0; r<numRows; r++){
			for(int c=r; c<length; c+=stride){
				output.push_back(s[c]);
				// calculate the index
				int tmp = c+stride-2*r;
				if(r!=0 && r!=numRows-1 && tmp<len)
					output.push_back(s[tmp]);
			}
		}
		return output;
	}
};