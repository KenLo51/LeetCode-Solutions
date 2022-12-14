class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!root) return {};
        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        findParent(root, parent);
        helper(target, K, parent, visited, res);
        return res;
    }
    void findParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;
        if (node->left) parent[node->left] = node;
        if (node->right) parent[node->right] = node;
        findParent(node->left, parent);
        findParent(node->right, parent);
    }
    void helper(TreeNode* node, int K, unordered_map<TreeNode*, TreeNode*>& parent, unordered_set<TreeNode*>& visited, vector<int>& res) {
        if (visited.count(node)) return;
        visited.insert(node);
        if (K == 0) {res.push_back(node->val); return;}
        if (node->left) helper(node->left, K - 1, parent, visited, res);
        if (node->right) helper(node->right, K - 1, parent, visited, res);
        if (parent[node]) helper(parent[node], K - 1, parent, visited, res);
    }
};