/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root==0)return 0;
    struct TreeNode* leftM=mirrorTree(root->left);
    struct TreeNode* rightM=mirrorTree(root->right);
    root->right=leftM;
    root->left=rightM;
    return root;
}