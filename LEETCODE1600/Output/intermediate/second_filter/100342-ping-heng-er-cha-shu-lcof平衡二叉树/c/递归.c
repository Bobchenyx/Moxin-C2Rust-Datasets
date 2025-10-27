/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isBalanced(struct TreeNode* root){
    int maxdepth(struct TreeNode *root);
    if(!root) return true;
    return isBalanced(root->left)&&isBalanced(root->right)&&abs(maxdepth(root->left)-maxdepth(root->right))<=1; //只需要在后面加上左右子树高度之差小于等于1
}
int maxdepth(struct TreeNode *root){
    if(!root) return 0;
    int l=maxdepth(root->left)+1;
    int r=maxdepth(root->right)+1;
    return l>r?l:r;
}