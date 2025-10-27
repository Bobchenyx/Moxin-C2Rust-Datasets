/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL) //base case
        return true;
    if(p == NULL && q != NULL)
        return false;
    if(p != NULL && q == NULL)
        return false;
    if(p->val != q->val) //推动条件
        return false;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); //左右子树同时检查
    
}