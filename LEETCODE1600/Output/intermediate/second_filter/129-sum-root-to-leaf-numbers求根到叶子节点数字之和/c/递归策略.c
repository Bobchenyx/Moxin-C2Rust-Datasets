/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumNumbers(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int res = 0;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    if (root->left) {
        root->left->val = root->val * 10 + root->left->val;
        res += sumNumbers(root->left);
    }
    if (root->right) {
        root->right->val = root->val * 10 + root->right->val;
        res += sumNumbers(root->right);
    }
    return res;
}