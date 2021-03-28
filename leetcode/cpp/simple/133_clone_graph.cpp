#include <iostream>
#include <vector>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node *>();
    }
    Node(int _val, std::vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class GraphClone {
public:
    Node *cloneGraph(Node *node) {
        if (!node) return nullptr;
        std::unordered_map<Node *, Node *> visited;
        Node *new_root = new Node(node->val);
        visited[node] = new_root;
        clone_(node, new_root, visited);
        return new_root;
    }

private:
    // recursive search (DFS)
    void clone_(Node *node, Node *new_root,
            std::unordered_map<Node *, Node *> &visited) {
        if (!node) return;
        for (auto child : node->neighbors) {
            // terminate condition
            if (visited.find(child) != visited.end()) {
                new_root->neighbors.push_back(visited[child]);
                continue;
            }
            Node *tmp = new Node(child->val);
            new_root->neighbors.push_back(tmp);
            visited[child] = tmp;
            clone_(child, new_root->neighbors.back(), visited);
        }
    }
};
