/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root)
{
    //判断节点是否为空
    if(root == NULL)
    {
        return 0;
    }
    //判断左子树
    int left = maxDepth(root->left)+1;
    int right = maxDepth(root->right)+1;

    return (left > right ? left : right);
}