/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    if(root->left==NULL)return (minDepth(root->right)+1);
    if(root->right==NULL)return (minDepth(root->left)+1);
    int n_left=minDepth(root->left)+1;
    int n_right=minDepth(root->right)+1;
    return (n_left<n_right?n_left:n_right);
}