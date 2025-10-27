/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
    if (NULL == root)
    {
        return false;
    }

    sum -= root->val;

    if (NULL == root->left && NULL == root->right)
    {
        return (0 == sum);
    }

    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}