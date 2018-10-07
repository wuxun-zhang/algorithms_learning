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

class BST_to_Dlist{
public:
	TreeNode* insertBST(int data, TreeNode* root){
		if (root == nullptr)
		{
			root = new TreeNode(data);
			cout<<"The inserted node is: "<<data<<endl;
			return root;
		}
		if (data < root->val)
			root->left = insertBST(data, root->left);
		else if (data > root->val)
			root->right = insertBST(data, root->right);
		else
			cout<<"The inserted node has been in the BST..."<<endl;
		return root;
	}

	// Time&Space: O(n) O(n)
	TreeNode* Convert(TreeNode* pRootOfTree){
		if(!pRootOfTree)
			return nullptr; 
		vector<TreeNode*> inOrderList;
		inOrder(pRootOfTree, inOrderList);
		return inOrderList_to_Dlist(inOrderList);
	}

	// Time&Space: O(n) O(1)
	TreeNode* _01_Convert(TreeNode* pRootOfTree){
		TreeNode* pLastNodeInList = nullptr;
		ConvertNodes(pRootOfTree, &pLastNodeInList);
		TreeNode* pHeadOfList = pLastNodeInList;
		while(pHeadOfList!=nullptr && pHeadOfList->left!=nullptr)
			pHeadOfList = pHeadOfList->left;
		return pHeadOfList;
	}
public:
	// in-order traversal
	void inOrder(TreeNode* root, vector<TreeNode*>& inOrderList){
		if(!root)
			return;
		inOrder(root->left, inOrderList);
		inOrderList.push_back(root);
		inOrder(root->right, inOrderList);
	}
	// convert in-order array to Dual linked list
	TreeNode* inOrderList_to_Dlist(vector<TreeNode*>& inOrderList){
		if(inOrderList.empty())
			return nullptr;
		TreeNode* treeHead = nullptr;
		TreeNode* current = treeHead;
		int i;
		for(i=0; i<inOrderList.size(); i++){
			if(!treeHead){
				treeHead = inOrderList[i];
				current = treeHead;
			}else{
				current->right = inOrderList[i];
				inOrderList[i]->left = current;
				current = current->right;
			}
		}
		return treeHead;
	}

	// in-Order traversal
	void ConvertNodes(TreeNode* pNode, TreeNode **pLastNodeInList){
		if(pNode == nullptr)
			return;

		TreeNode* pCurrent = pNode;
		if(pCurrent->left != nullptr)
			ConvertNodes(pCurrent->left, pLastNodeInList);

		// connect the previous and the current node
		pCurrent->left = *pLastNodeInList;
		if((*pLastNodeInList) != nullptr)
			(*pLastNodeInList)->right = pCurrent;
		*pLastNodeInList = pCurrent;

		if(pCurrent->right != nullptr)
			ConvertNodes(pCurrent->right, pLastNodeInList);
	}
};


// int main(void){
// 	int n;
// 	while(cin>>n){
// 		BST_to_Dlist AA;
// 		TreeNode* pRoot = nullptr;
// 		for(int i=0; i<n; i++){
// 			int x;
// 			cin>>x;
// 			pRoot = AA.insertBST(x, pRoot);
// 		}
// 		vector<TreeNode*> inOrderList;
// 		AA.inOrder(pRoot, inOrderList);
// 		cout<<"The inOrder array of BST : "<<endl;
// 		for(auto item : inOrderList)
// 			cout<<item->val<<" ";
// 		cout<<endl;
// 		cout << "after converting to D_list..." << endl;
// 		TreeNode* new_treeNode = AA.inOrderList_to_Dlist(inOrderList);
// 		cout << new_treeNode->val << endl;
// 	}
// 	return 0;
// }