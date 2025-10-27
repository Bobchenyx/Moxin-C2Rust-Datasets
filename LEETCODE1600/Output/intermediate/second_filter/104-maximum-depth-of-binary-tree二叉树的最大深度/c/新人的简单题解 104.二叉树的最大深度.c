/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int Max(int a,int b)
{
    return a>b?a:b;
}

int maxDepth(struct TreeNode* root)
{
    if(root==NULL) return 0;
    else
    {
        return 1+Max(maxDepth(root->left),maxDepth(root->right));
    }
}