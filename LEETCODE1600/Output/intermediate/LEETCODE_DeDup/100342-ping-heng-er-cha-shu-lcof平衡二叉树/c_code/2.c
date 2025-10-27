/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode *root)
{
    //递归终止条件
    if(root == NULL)
    {
        return 0;
    }
    int left = maxDepth(root->left)+1;
    int right = maxDepth(root->right)+1;
    return (left > right ? left : right);
}

bool isBalanced(struct TreeNode* root)
{
    //递归终止条件
    if(root == NULL)
    {
        return true;
    }
    else
    {
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        //递归终止条件
        if(abs(left-right) > 1)
        {
            return false;
        }
    }
    return isBalanced(root->left) && isBalanced(root->right);
}