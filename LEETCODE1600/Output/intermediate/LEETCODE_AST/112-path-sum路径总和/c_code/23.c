bool g_flag = false;

void dfs(struct TreeNode *root, int val, int sum)
{
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL && val == sum)
       g_flag = true;
    dfs(root->left, val, sum);
    dfs(root->right, val, sum);
}

bool hasPathSum(struct TreeNode* root, int sum){
    g_flag = false;
    dfs(root, 0, sum);
    return g_flag;
}