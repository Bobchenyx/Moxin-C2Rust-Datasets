/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirro(struct TreeNode* left, struct TreeNode* right){

    if(!left && !right)
        return true;
    if((left==NULL && right!=NULL) || (left!=NULL && right ==NULL))
        return false;

    if(left->val!=right->val)
        return false;
    
    return isMirro(left->left, right->right) && isMirro(left->right, right->left);
}



bool isSymmetric(struct TreeNode* root){

    if(root ==NULL)
        return true;
   return isMirro(root, root);
}