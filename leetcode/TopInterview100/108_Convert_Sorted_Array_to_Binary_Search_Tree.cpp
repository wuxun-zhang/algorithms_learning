#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, *right;
	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return nullptr;
		TreeNode* root = nullptr;
		helper(nums, 0, nums.size() - 1, &root);
		return root;
	}

private:
	// pointer to pointer
	void helper(vector<int>& nums, int start, int end, TreeNode** root) {
		if (start > end) {
			return;
		}
		int mid = (start + end) / 2;
		*root = new TreeNode(nums[mid]);
		helper(nums, start, mid - 1, &((*root)->left));
		helper(nums, mid + 1, end, &((*root)->right));
		return;
	}
};

