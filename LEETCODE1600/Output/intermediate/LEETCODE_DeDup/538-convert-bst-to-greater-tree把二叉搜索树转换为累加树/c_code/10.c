/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int g_num;

void preorder(struct TreeNode* root) {
    if(!root) {
        return;
    }
    preorder(root->right);
    g_num += root->val;
    root->val = g_num;
    preorder(root->left);
}

struct TreeNode* convertBST(struct TreeNode* root){
    g_num = 0;
    preorder(root);
    return root;
}