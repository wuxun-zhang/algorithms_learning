#include<iostream>
using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
	// recursive
	// traverse from leaf node to root node
    int maxDepth(TreeNode* root) {
		if(!root)
			return 0;
		int mx=0;
		int leftDepth = maxDepth(root->left);
		if(mx<leftDepth)
			mx = leftDepth;
		int rightDepth = maxDepth(root->right);
		if(mx<rightDepth)
			mx = rightDepth;
		return mx+1;
    }

    int maxDepth_opt(TreeNode* root){
    	if(!root)
    		return 0;
    	return max(maxDepth_opt(root->left)+1, maxDepth_opt(root->right)+1);
    }
};