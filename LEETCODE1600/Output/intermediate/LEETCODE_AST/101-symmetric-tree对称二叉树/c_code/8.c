/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* left, struct TreeNode* right);

bool isSymmetric(struct TreeNode* root){
    if(!root)
        return true;
    return isMirror(root->left, root->right);
}

bool isMirror(struct TreeNode* left, struct TreeNode* right){
    if(left && right){
        if(left->val == right->val){
            return isMirror(left->left, right->right) && isMirror(left->right, right->left);
        }
        return false;
    }
    if(!left && !right)
        return true;
    else
        return false;
}