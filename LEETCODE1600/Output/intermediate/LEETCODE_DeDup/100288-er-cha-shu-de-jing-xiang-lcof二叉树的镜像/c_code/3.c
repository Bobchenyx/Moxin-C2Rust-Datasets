/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root == NULL) {
        return NULL;
    }

    /* 进行左右交换 */
    struct TreeNode *tmp;
    tmp = root->right;
    root->right  = root->left;
    root->left   = tmp;

    /* 处理子树 */
    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}