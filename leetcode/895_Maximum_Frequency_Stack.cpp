#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

// push: insert a value into FreqStack
// pop: pop a value which is the most frequent
// note: If there is a tie for most frequent element, 
//       the element closest to the top of the stack is removed and returned 

class FreqStack{
public:
	FreqStack(): maxFreq(0){
	}

	void push(int x){
		maxFreq = max(maxFreq, ++freq[x]);
		m[freq[x]].push(x);
	}

	int pop(){
		int x = m[maxFreq].top();
		m[maxFreq].pop();
		// when m[maxFreq] is empty, then maxFreq must minus 1
		if(m[freq[x]--].empty())
			maxFreq--;
		return x;
	}
private:
	unordered_map<int, int> freq;
	unordered_map<int, stack<int>> m;
	int maxFreq;
};


class FreqStack_v2{
public:
	FreqStack(){
	}
	
	void push(int x){
		if(freq_mp.count(x) == 0){
			freq_mp[x] = 1;
			auto freq=1;
			if(elem_st.size() < freq)
				elem_st.push_back({x});
			else
				elem_st[freq-1].push_back(x);
		}else{
			++freq_mp[x];
			auto freq = freq_mp[x];
			if(elem_st.size() < freq)
				elem_st.push_back({x});
			else
				elem_st[freq-1].push_back(x);
		}
	}

	int pop(){
		// fetch the most frequent value
		auto ans = elem_st.back().back();
		elem_st.back().pop_back();
		// maxFreq--
		if(elem_st.back().empty())
			elem_st.pop_back();
		--freq_mp[ans];
		return ans;
	}
private:
	// use the push_back and pop_back method of vector object to
	// simulate push and pop of the stack object
	vector<vector<int>> elem_st;
	unordered_map<int, int> freq_mp;
};