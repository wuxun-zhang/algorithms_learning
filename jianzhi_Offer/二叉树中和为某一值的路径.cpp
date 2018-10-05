#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> paths;
		vector<int> cur;
		helper(root, paths, cur, expectNumber);
		return paths;
	}
private:
    void helper(TreeNode* root, vector<vector<int>>& paths, vector<int>& cur, int expectNumber){
    	if(!root)
    		return;
    	cur.push_back(root->val);
    	// (1) reach the leaf node
    	// (2) expectNumber==(leaf_node)->val
    	// (1) and (2) -> path found
    	if(!root->left && !root->right && expectNumber == root->val)
    		paths.push_back(cur);
    	// search left/right nodes
    	helper(root->left, paths, cur, expectNumber - root->val);
    	helper(root->right, paths, cur, expectNumber - root->val);
    	cur.pop_back();
    }
};