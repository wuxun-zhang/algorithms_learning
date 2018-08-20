#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 实现通配符的功能
// abshdd = ab* = *hdd = *sh*d = *sh.d
// *: some characters(zero or nonzero)
// .: only one character
bool isMatch(string& s, string& p){
    if(p.empty()){
        return s.empty();
    }
    size_t m = s.size(), n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;
    for(int i=1;i<=m;i++){
        dp[i][0] = false;
    }
    for(int i=1;i<=n;i++){
        dp[0][i] = i>1 && dp[0][i-2] && (p[i-1] == '*');
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(p[j-1] != '*'){
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || '.' == p[j-1]);
            }else{
                // dp[i][j-2]：s中前i个元素与p中前j-2个元素相匹配，p中第j个元素是'*',未起到作用
                // dp[i-1][j]：s中前i-1个元素与p中前j个元素相匹配，p中第j个元素是'*'，此时起到了统配的作用
                dp[i][j] = j>1 && dp[i][j-2] || (s[i-1] == p[j-2] || '.' == p[j-2]) && dp[i-1][j]; 
            }
        }
    }
    return dp[m][n];
}

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        if (p.empty())    return s.empty();
        
        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};


int main(){
    string s, a;
    while(cin>>s>>a){
        cout<<(isMatch(s, a)?"true":"false")<<endl;
    }
    return 0;
}