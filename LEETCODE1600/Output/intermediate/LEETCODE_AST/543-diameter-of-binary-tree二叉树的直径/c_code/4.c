/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ans = 0;
int max(int a, int b) {
    return a > b ? a : b;
}

int depth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int L = depth(root->left);
    int R = depth(root->right);
    ans = max(ans, L + R + 1);
    return max(L,R) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    ans = 0;
    if (root == NULL) {
        return 0;
    }
    depth(root);
    return ans - 1;
}