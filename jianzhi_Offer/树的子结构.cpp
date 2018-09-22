

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};


class Solution {
public:
	// recursive 
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	bool result = false;
        if(!pRoot1 || !pRoot2)
        	return result;
        if(pRoot1->val == pRoot2->val)
        	result = DoesTree1HasTree2(pRoot1, pRoot2);
        if(!result)
        	result = HasSubtree(pRoot1->left, pRoot2);
        if(!result)
        	result = HasSubtree(pRoot1->right, pRoot2);
        return result;
    }
private:
	bool DoesTree1HasTree2(TreeNode* t1, TreeNode* t2){
		// the leaf node in t2 found
		// matched
		if(!t2)
			return true;
		if(!t1)
			return false;
		// not matched
		if(t1->val != t2->val)
			return false;

		return DoesTree1HasTree2(t1->left, t2->left) &&
			DoesTree1HasTree2(t1->right, t2->right);
	}
};
