/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode* targetNode = root;
    while(targetNode != NULL){
        if(targetNode->val == val) break;
        
        if(val > targetNode->val)
            targetNode = targetNode->right;
        else
            targetNode = targetNode->left;
    }
    return targetNode;
}