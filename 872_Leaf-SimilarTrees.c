/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // get the leaf value sequence into seq
    void getLeaves(TreeNode* currNode, vector<int>& seq){
        // go to children
        if(currNode->left)  getLeaves(currNode->left, seq);
        if(currNode->right)  getLeaves(currNode->right, seq);
        // currNode is leaf
        if((currNode->left == NULL) && (currNode->right == NULL))
            seq.push_back(currNode->val);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // get leaf value sequences from 2 tree
        vector<int> seq1, seq2;
        getLeaves(root1, seq1);
        getLeaves(root2, seq2);

        // if different number of leaves in 2 tree
        if(seq1.size() != seq2.size()) return false;
        // if 2 sequences are same
        for(unsigned int i=0; i<seq1.size(); i++)
            if(seq1[i] != seq2[i]) return false;
        return true;
    }
};