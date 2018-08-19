#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
	vector<vector<int>> pathSumII(TreeNode* root, int sum){
		vector<vector<int>> paths;
		vector<int> cur;
		dfs(root, paths, cur, sum);
		return paths;
	}
private:
	void dfs(TreeNode*root, vector<vector<int>>& paths, vector<int>& cur,int sum){
		if(!root)
			return;
		if(!root->left && !root->right && sum == 0)
			paths.push_back(cur);
		
		cur.push_back(root->val);
		dfs(root->left, paths, cur, sum-root->val);
		dfs(root->right, paths, cur, sum - root->val);
		cur.pop_back();
	}
};
