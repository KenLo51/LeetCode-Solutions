class Solution {
public:
  int goodNodes(TreeNode* root, int max_val = INT_MIN) {
    if (!root) return 0;//沒有結點
    return goodNodes(root->left, max(max_val, root->val))
           + goodNodes(root->right, max(max_val, root->val))
           + (root->val >= max_val ? 1 : 0);
  }
};