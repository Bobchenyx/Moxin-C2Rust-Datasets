bool hasPathSum(struct TreeNode* root, int sum){
    if (!root) return false;
    sum = sum - root->val;
    // 左右节点均为 NULL ，且 sum 为 0 时, 满足条件
    if (!root->left && !root->right && !sum) return true;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}