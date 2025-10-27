/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    if(!root)
        return 0;                 
    if(!root->left && !root->right)
        return 1;
    if(!root->left)
        return minDepth(root->right)+1;
    if(!root->right)
        return minDepth(root->left)+1;
      int  n = minDepth(root->left);
      int  m = minDepth(root->right);
    if(n>m)
        return m+1;
        return n+1;
}