/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    int leftDepth=1,rightDepth=1;
    if(root==NULL)
        return 0;
    else
    {
        leftDepth+=minDepth(root->left);
        rightDepth+=minDepth(root->right);
    }
    if(root->left==NULL)//根节点的左子树为空
        return rightDepth;
    else if(root->right==NULL)//根节点右子树为空
        return leftDepth;
    else
        return leftDepth<rightDepth?leftDepth:rightDepth;
}