/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int g_max = 0;

int Dfs(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int left = Dfs(root->left);
    int right = Dfs(root->right);

    if (left + right > g_max){
        g_max = left + right;
    }
    
    return (left+1) > (right+1) ? (left+1) : (right+1);
}

int diameterOfBinaryTree(struct TreeNode* root){
    g_max = 0;
    Dfs(root, 0);
    return g_max;
}