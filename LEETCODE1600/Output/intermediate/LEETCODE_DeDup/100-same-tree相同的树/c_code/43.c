/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(NULL == p && q == NULL){
        return true;
    }
    
    while(p && q){
        if(p->val == q->val){
            if(p->left == NULL && p->right == NULL && q->left == NULL && q->right == NULL){
                return true;
            }
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }else{
            break;
        }
    }

    return false;
}