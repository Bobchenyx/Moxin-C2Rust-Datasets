bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }

    /* 操作 */
    sum -= root->val;

    /* 递归结束条件 */
    if (root->left == NULL && root->right == NULL) {
        if (sum == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    /* 递归 */
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}