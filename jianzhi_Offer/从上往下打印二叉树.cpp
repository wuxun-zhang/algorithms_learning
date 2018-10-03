#include<iostream>
#include<vector>
#include<queue>
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
	// level traversal
	// non-recursive
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(!root)
        	return vector<int>{};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
        	TreeNode* cur = q.front();
        	q.pop();
        	res.push_back(cur->val);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return res;
    }

    // recursive
   /* vector<vector<int>> levelOrder_traversal(TreeNode* root){
        if(!root)
            return vector<int>{};
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }*/

private:
    void helper(TreeNode* root, int level, vector<vector<int> >& res){
        if(!root)
            return;
        if(res.size() == level)
            res.push_back({});
        // find the matched level 
        res[level].push_back(root->val);
        if(root->left)
            helper(root->left, level+1, res);
        if(root->right)
            helper(root->right, level+1, res);
    }
};