void inorder(struct TreeNode *root, Darry *darr)
{
    if ( root == NULL) return;
    inorder(root->left, darr);
    Append(darr, root->val);
    inorder(root->right, darr);
}