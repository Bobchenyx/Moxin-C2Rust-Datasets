/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    if (left->val == right->val)
    {
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
    else return false;
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    else return isMirror(root->left, root->right);
}