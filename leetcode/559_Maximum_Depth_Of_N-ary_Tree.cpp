#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
	// BFS
    int maxDepth(Node* root) {
		if(!root)
			return 0;
		int max_depth = 1;
		queue<pp> q;
		q.push({root, 1});
		while(!q.empty()){
			auto t = q.front();
			q.pop();
			if(!t.first->children.empty())
				max_depth = max(max_depth, t.second+1);
			else
				continue;
			// search all childs
			for(auto item : t.first->children){
				q.push(make_pair(item, t.second+1));
			}
		}
		return max_depth;
    }

    // recursive
    int maxDepth_recursive(Node* root){
    	if(!root)
    		return 0;
    	int mx = 0;
    	for(auto item : root->children){
    		int h = maxDepth_recursive(item);
    		if(mx < h)
    			mx = h;
    	}
    	return mx+1;
    }
private:
	using pp = pair<Node*, int>;
};
