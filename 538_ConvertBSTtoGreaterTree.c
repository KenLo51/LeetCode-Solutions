/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int convert(struct TreeNode* root, int sum){
    if(root == NULL) return sum;
    if(root->right != NULL)
        sum = convert(root->right, sum);
    sum = root->val + sum;
    root->val = sum;
    if(root->left != NULL)
        sum = convert(root->left, sum);
    return sum;
}
struct TreeNode* convertBST(struct TreeNode* root){
    convert(root, 0);
    return root;
}