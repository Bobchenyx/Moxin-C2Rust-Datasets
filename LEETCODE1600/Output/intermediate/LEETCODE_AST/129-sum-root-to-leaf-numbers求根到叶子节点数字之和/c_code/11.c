/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumNumbers(struct TreeNode* root){
    if(root == NULL)
        return 0;
    int sumLeft=0,sumRight=0;
    if(root->left != NULL)
    {
        root->left->val = root->val*10 + root->left->val;
        sumLeft=sumNumbers(root->left);
    }
    if(root->right != NULL)
    {
        root->right->val = root->val*10 + root->right->val;
        sumRight = sumNumbers(root->right);
    }
    if(root->left == NULL && root->right == NULL)
        return root->val;
    else
        return sumLeft+sumRight;
}