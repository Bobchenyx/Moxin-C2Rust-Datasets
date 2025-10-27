/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root){
    int left=1,right=1;
    if(root==NULL)
        return 0;
    else
    {
        left+=maxDepth(root->left);
        right+=maxDepth(root->right);
    }
    return left>right?left:right;//很基础的判断
}