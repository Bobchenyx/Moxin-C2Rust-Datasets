bool hasPathSum(struct TreeNode* root, int sum){
    if(!root)
        return 0;
    sum -= root->val;
    if(!root->left && !root->right)
        return 0 == sum;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}