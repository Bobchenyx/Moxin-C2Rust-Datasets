int node_depth[10240];
int node_top;
int diameterOfBinaryTree(struct TreeNode* root){
    if (root == NULL) return 0;
    node_top = 0;
    tree_depth(root);
    int max = -1;
    for (int i = 0; i < node_top; ++i) {
        if (node_depth[i] > max) max = node_depth[i];
    }
    return max;
}

int tree_depth(struct TreeNode* root)
{
    if (root == NULL) return 0;
    int l_depth = 1+tree_depth(root->left);
    int r_depth = 1+tree_depth(root->right);
    node_depth[node_top++] = l_depth + r_depth - 2;
    return (l_depth > r_depth ? l_depth : r_depth);
}