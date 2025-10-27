/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// len(root->left) + len(root->right) + 2;
int dfs(struct TreeNode* root, int *max){
    if( root == NULL ) return 0;
    int leftLen = dfs(root->left, max);
    int rightLen = dfs(root->right, max);
    if( leftLen + rightLen > *max) {
        *max = leftLen + rightLen;
    }
    return leftLen > rightLen ? leftLen + 1 : rightLen + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if( root == NULL ) return 0;
    int max = 0;
    dfs(root, &max);
    return max;
}