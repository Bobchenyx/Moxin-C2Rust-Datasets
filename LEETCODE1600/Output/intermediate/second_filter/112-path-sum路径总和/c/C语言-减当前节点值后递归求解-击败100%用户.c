bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return (sum == root->val);
    }

    int remainSum = sum - root->val;

    return hasPathSum(root->left, remainSum) || hasPathSum(root->right, remainSum);
}