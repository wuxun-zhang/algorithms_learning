#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2. 
// 采用DP思想，分为三种情况
// 1. s1空，s2非空 -> 若dp[0][j-1]为true（s3中的前j-1个元素由s2交错而来），则dp[0][j]的值由s2与s3当前位字符是否相同确定
// 2. s1非空，s2空 -> 同上
// 3. s1、s2非空 -> 此时dp[i][j-1]由dp[i-1][j]&&s1[i - 1] == s3[i + j - 1] 或 dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]确定

// 2-D dp
bool isInterleave_v1(const string& s1, const string &s2, const string& s3)
{
	int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
	if (l3 != l1 + l2)
		return false;
	vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1));
	for (int i = 0; i <= l1; i++)
	{
		for (int j = 0; j <= l2; j++)
		{
			if (i == 0 && j == 0)
				dp[i][j] = true;
			else if (i == 0)
				dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
			else if (j == 0)
				dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
			else {
				dp[i][j] = ((dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])));
			}
		}
	}
	return dp[l1][l2];
}
// after initialize dp array
bool isInterleave(string& s1, string& s2, string& s3)
{
	int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
	if (l3 != l1 + l2)
		return false;
	vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1));
	dp[0][0] = true;
	for (int i = 1; i < l1; i++)
		dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
	for (int i = 1; i < l2; i++)
		dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
	for (int i = 1; i <= l1; i++)
		for (int j = 1; j <= l2; j++)
			dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
	return dp[l1][l2];
}

// 1-D dp
bool isInterleave_v2(const string& s1, const string &s2, const string& s3)
{
	int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
	if (l3 != l1 + l2)
		return false;
	vector<bool> dp(l2 + 1);
	for (int i = 0; i <= l1; i++)
	{
		for (int j = 0; j <= l2; j++)
		{
			if (i == 0 && j == 0)
				dp[j] = true;
			else if (i == 0)
				dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
			else if (j == 0)
				dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
			else {
				dp[j] = ((dp[j] && (s1[i - 1] == s3[i + j - 1])) || (dp[j - 1] && (s2[j - 1] == s3[i + j - 1])));
			}
		}
	}
	return dp[l2];
}

void main()
{
	string s1, s2, s3;
	while (cin >> s1 >> s2 >> s3)
	{
		cout << (isInterleave_v2(s1, s2, s3) ? "Yes":"No") << endl;
	}
}
