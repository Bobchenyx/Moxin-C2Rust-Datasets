/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool haha(struct TreeNode* root, int sum){
    if(!root)
        if(sum==0)
            return true;
        else
            return false;
    if(root->left&&!root->right)
        return haha(root->left,sum-root->val);
    if(!root->left&&root->right)
        return haha(root->right,sum-root->val);
    return (haha(root->left,sum-root->val)||haha(root->right,sum-root->val));
}
bool hasPathSum(struct TreeNode* root, int sum){
    if(!root)
        return false;
    return haha(root,sum);
}