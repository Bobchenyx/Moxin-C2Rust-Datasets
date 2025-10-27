/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    if(root==0)
        return 0;
    else
    {
        int leftHeight=minDepth(root->left);
        int rightHeight=minDepth(root->right);
        if(root->left==0)return rightHeight+1;
        if(root->right==0)return leftHeight+1;
        return leftHeight<rightHeight?leftHeight+1:rightHeight+1;
    }
}