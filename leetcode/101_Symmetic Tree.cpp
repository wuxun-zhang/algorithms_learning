#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// 判断二叉树是否是满足对称条件
// 依次比较左右两个子树的节点是否相同（节点是否缺失、节点值是否相等）

class Solution {
public:
	// not recursive
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		queue<TreeNode*> q1, q2;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty()) {
			TreeNode *node1 = q1.front();
			TreeNode *node2 = q2.front();
			q1.pop();
			q2.pop();
			// node1的左节点存在，但node2的右节点不存在
			// 或者node1的右节点不存在，但node2的左节点存在
			if ((node1 && !node2) || (!node1&&node2))
				return false;
			// node1和node2的左右节点均存在时
			if (node1) {
				// 值不相同
				if (node1->val != node2->val)
					return false;
				q1.push(node1->left);
				q1.push(node1->right);
				q2.push(node2->right);
				q2.push(node2->left);
			}
		}
		return true;
	}
	// recursive
	bool isSymmetric_v2(TreeNode* root) {
		if (!root)
			return true;
		return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode* left, TreeNode* right) {
		if (!left && !right)
			return true;
		if ((left && !right) || (!left&&right) || (left->val != right->val))
			return false;
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
private:
	// 非递归实现中序遍历
	// 无法仅仅通过一个遍历数组判断二叉树（除非是满二叉树）是否是对称结构
	// 因为二叉树的单种遍历方式不存在唯一性
	vector<int> Inorder(TreeNode* root) {
		if (!root)
			return{};
		vector<int> result;
		stack<TreeNode*> TreeStack;
		TreeNode* cur = root;
		while (cur || !TreeStack.empty()) {
			while (cur) {
				TreeStack.push(cur);
				cur = cur->left;
			}
			if (!TreeStack.empty()) {
				cur = TreeStack.top();
				result.push_back(cur->val);
				TreeStack.pop();
				// 进一步检查右子树是否存在其他节点
				cur = cur->right;
			}
		}
		return result;
	}
};