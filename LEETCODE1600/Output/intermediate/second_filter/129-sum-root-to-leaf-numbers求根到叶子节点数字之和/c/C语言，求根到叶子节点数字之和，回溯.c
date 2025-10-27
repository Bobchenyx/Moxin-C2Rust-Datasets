void backtrack(struct TreeNode* root, int* res, int path) {
    if (!root) return;
    path = path * 10 + root->val;                   // 1. 变更状态
    if (!root->left && !root->right) *res += path;  // 2. 操作/递归
    else backtrack(root->left, res, path), backtrack(root->right, res, path);
    path = path / 10;                               // 3. 恢复状态
}
int sumNumbers(struct TreeNode* root){
    int res = 0;
    backtrack(root, &res, 0);
    return res;
}