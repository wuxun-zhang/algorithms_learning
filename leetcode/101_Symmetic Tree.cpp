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

// �ж϶������Ƿ�������Գ�����
// ���αȽ��������������Ľڵ��Ƿ���ͬ���ڵ��Ƿ�ȱʧ���ڵ�ֵ�Ƿ���ȣ�

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
			// node1����ڵ���ڣ���node2���ҽڵ㲻����
			// ����node1���ҽڵ㲻���ڣ���node2����ڵ����
			if ((node1 && !node2) || (!node1&&node2))
				return false;
			// node1��node2�����ҽڵ������ʱ
			if (node1) {
				// ֵ����ͬ
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
	// �ǵݹ�ʵ���������
	// �޷�����ͨ��һ�����������ж϶������������������������Ƿ��ǶԳƽṹ
	// ��Ϊ�������ĵ��ֱ�����ʽ������Ψһ��
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
				// ��һ������������Ƿ���������ڵ�
				cur = cur->right;
			}
		}
		return result;
	}
};