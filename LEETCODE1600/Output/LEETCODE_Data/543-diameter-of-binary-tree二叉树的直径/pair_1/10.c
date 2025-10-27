/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int proc(struct TreeNode *root, int *max)
{
    int left, right, cur;
    if (root == NULL) {
        return -1;
    }
    left = proc(root->left, max);
    right = proc(root->right, max);
    cur = left + right + 2;
    *max = *max > cur ? *max : cur;
    return (left > right ? left : right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int max = 0;
    proc(root, &max);
    return max;
}