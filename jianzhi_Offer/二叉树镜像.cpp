#include<iostream>
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
    void Mirror(TreeNode *pRoot) {
    	if(!pRoot || (!pRoot->left && !pRoot->right))
    		return;
    	SwapLeftAndRightNode(&pRoot, pRoot->left, pRoot->right);

    	if(pRoot->left) Mirror(pRoot->left);
    	if(pRoot->right) Mirror(pRoot->right);

    	return;
    }
private:
	inline void SwapLeftAndRightNode(TreeNode** parent, TreeNode* lcild, TreeNode* rchild){
		if(!lcild && !rchild)
			return;
		(*parent)->left = rchild;
		(*parent)->right = lcild;

		return;
	}
};