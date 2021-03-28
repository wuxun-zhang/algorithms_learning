#include <deque>
#include <stack>
#include <vector>
#include <unordered_set>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Preorder {
public:
    std::vector<int> preorderTraverse(TreeNode *root) {
        std::vector<int> ret;
        recursive_traverse(root, ret);
        return ret;
    }

private:
    void recursive_traverse(TreeNode *root, std::vector<int> &ret) {
        if (!root) return;
        ret.push_back(root->val);
        // search left child
        recursive_traverse(root->left, ret);
        // search right child
        recursive_traverse(root->right, ret);
    }

    void iterate_traverse(TreeNode *root, std::vector<int> &ret) {
        if (!root) return;
        //use deque to simulate stack
        std::deque<TreeNode *> tree_queue;
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            TreeNode *front = tree_queue.front();
            tree_queue.pop_front();
            ret.push_back(front->val);
            // first push last pop
            if (front->right) tree_queue.push_front(front->right);
            if (front->left) tree_queue.push_front(front->left);
        }
    }

    void iterate_traverse_v2(TreeNode *root, std::vector<int> &ret) {
        if (!root) return;
        // use stack
        std::stack<TreeNode *> tree_stack;
        TreeNode *cur_node = root;
        while (!tree_stack.empty() || cur_node) {
            while (cur_node) {
                ret.push_back(cur_node->val);
                tree_stack.push(cur_node);
                cur_node = cur_node->left;
            }

            TreeNode *top = tree_stack.top();
            tree_stack.pop();
            cur_node = top->right;
        }
    }
};

class Inorder {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> ret;
        recursive_traverse(root, ret);
        return ret;
    }

private:
    void recursive_traverse(TreeNode *root, std::vector<int> &ret) {
        if (!root) return;
        recursive_traverse(root->left, ret);
        ret.push_back(root->val);
        recursive_traverse(root->right, ret);
    }

    void iterate_traverse(TreeNode *root, std::vector<int> &ret) {
        if (!root) return;
        // use stack
        std::stack<TreeNode *> tree_stack;
        TreeNode *cur_node = root;
        while (!tree_stack.empty() || cur_node) {
            // find the left-est leaf
            while (cur_node) {
                tree_stack.push(cur_node);
                cur_node = cur_node->left;
            }
            TreeNode *top = tree_stack.top();
            tree_stack.pop();
            ret.push_back(top->val);

            cur_node = top->right;
        }
    }

    void iterate_traverse_v2(TreeNode *root, std::vector<int> &ret) {
        if (!root) return;
        // use deque to simulate stack
        std::deque<TreeNode *> tree_deque;
        TreeNode *cur_node = root;
        while (!tree_deque.empty()) {
            while (cur_node) {
                tree_deque.push_front(cur_node);
                cur_node = cur_node->left;
            }

            TreeNode *front = tree_deque.front();
            tree_deque.pop_front();
            ret.push_back(front->val);

            if (front->right) cur_node = front->right;
        }
    }
};

class Postorder {
public:
    std::vector<int> postorderTraversal(TreeNode *tree) {
        std::vector<int> ret;
        recursive_traverse(root, ret);
        return ret;
    }

private:
    void recursive_traverse(TreeNode *root, std::vector<int> &ret) {
        if (!root) return;
        recursive_traverse(root->left, ret);
        recursive_traverse(root->right, ret);
        ret.push_back(root->val);
    }

    void iterate_traverse(TreeNode *root, std::vector<int> &ret) {
        if (!root) return;
        std::deque<TreeNode *> tree_deque;
        std::unordered_set<TreeNode *> visited;
        tree_deque.push_back(root);
        // visited.insert(root);
        while (!tree_deque.empty()) {
            TreeNode *cur_node = tree_deque.front();
            while (cur_node && visited[cur_node] == visited.end()) {
                visited.insert(cur_node);
                TreeNode *next_node = nullptr;
                if (cur_node->right) {
                    tree_deque.push_front(cur_node->right);
                    next_node = cur_node->right;
                }
                if (cur_node->left) {
                    tree_deque.push_front(cur_node->left);
                    next_node = cur_node->left;
                }
                cur_node = next_node;
            }
            TreeNode *front = tree_deque.front();
            tree_deque.pop_front();
            ret.push_back(front->val);
        }
    }
};

class Levelorder {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> ret;
        // use queue is okay
        std::deque<TreeNode *> tree_deque;
        tree_deque.push_back(root);
        std::unordered_set<TreeNode *> visited;
        while (!tree_deque.empty()) {
            std::vector<int> res;
            int cur_level_size = tree_deque.size();
            for (int i = 0; i < cur_level_size; ++i) {
                TreeNode *front = tree_deque.front();
                tree_deque.pop_front();
                res.push_back(front->val);
                if (front->left) tree_deque.push_back(front->left);
                if (front->right) tree_deque.push_back(front->right);
            }
            ret.push_back(res);
        }
    }
};
