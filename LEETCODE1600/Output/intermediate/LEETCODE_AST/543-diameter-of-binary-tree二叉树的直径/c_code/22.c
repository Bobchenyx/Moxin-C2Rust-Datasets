int g_ans = 0;
int deep(struct TreeNode* root) {
    int leftLength = 0;
    int rightLength = 0;
    int ret = 0;

    if (root != NULL) {
        leftLength = root->left ? deep(root->left) + 1 : 0;
        rightLength += root->right? deep(root->right) + 1 : 0;
        g_ans = (g_ans > leftLength + rightLength) ? g_ans : leftLength + rightLength;
        ret = (leftLength > rightLength) ? leftLength : rightLength;
        //printf("root->val = %d, leftLength = %d, rightLength = %d\n", root->val, leftLength, rightLength);
        return ret;
    }
    return 0;
}
int diameterOfBinaryTree(struct TreeNode* root){
    g_ans = 0;
    (void)deep(root);
    return g_ans;
}