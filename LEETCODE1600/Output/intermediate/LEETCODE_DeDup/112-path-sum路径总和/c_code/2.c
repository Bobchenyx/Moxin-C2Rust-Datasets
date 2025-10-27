/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
    bool left = false, right = false;

    if(root == NULL)
    {
        return false;
    }

    if((sum == root->val) && root->left == NULL && root->right == NULL)
    {
        return true;
    }

    sum -= root->val;

    if(root->left != NULL)
    {
        left = left | hasPathSum(root->left, sum);
    }
    
    if(root->right != NULL)
    {
        right = right | hasPathSum(root->right, sum);

    }
 
    return(left | right);
}