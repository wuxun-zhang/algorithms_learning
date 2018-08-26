#include<string>
#include<vector>
#include<set>
using namespace std;

class Solution{
public:
	// DFS
	vector<string> generateParentheses(int n){
		vector<string> res;
		dfs(n, n, "", res);
		return res;
	}

	// ****
	vector<string> generateParentheses_v2(int n){
		set<string> t;
		if(n == 0)
			t.insert("");
		else{
			vector<string> pre=generateParentheses_v2(n-1);
			for(auto a: pre){
				for(int i=0;i<a.size();i++){
					if(a[i]=='(')
					{
						a.insert(a.begin()+i+1, '(');
						a.insert(a.begin()+i+2, ')');
						t.insert(a);
						a.erase(a.begin()+i+1, a.begin()+i+3);
					}
				}
				t.insert("()"+a);
			}
		}
		return vector<string>(t.begin(), t.end());
	}

private:
	void dfs(int left, int right, string out, vector<string>& res){
		// illegal expression
		if(left>right)
			return;
		if(left==0 && right==0)
			res.push_back(out);	
		else{
			if(left>0)
				dfs(left-1, right, out+'(', res);
			if(right>0)
				dfs(left, right-1, out+')', res);
		}
	}
};