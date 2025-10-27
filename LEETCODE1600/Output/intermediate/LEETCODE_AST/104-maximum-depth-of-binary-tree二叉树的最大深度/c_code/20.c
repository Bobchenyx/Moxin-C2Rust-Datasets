int TreeDepthDfs(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    int left = TreeDepthDfs(root->left) + 1;
    int right = TreeDepthDfs(root->right) + 1;

    return left >= right ? left : right;
}