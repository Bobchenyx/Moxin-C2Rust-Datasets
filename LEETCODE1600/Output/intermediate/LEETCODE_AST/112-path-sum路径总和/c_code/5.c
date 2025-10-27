/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
    if(!root)
        return false;
    if (!root->left && !root->right && root->val == sum)
        return true;
    if(root->left)
        root->left->val += root->val;
    if(root->right)
        root->right->val += root->val;
    return (hasPathSum(root->left,sum) || hasPathSum(root->right,sum));
        
}