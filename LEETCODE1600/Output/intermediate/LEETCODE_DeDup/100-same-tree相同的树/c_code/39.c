/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        return false;
    }
    if(p == NULL && q == NULL)
    {
        return true;
    }
    if(isSameTree(p->left,q->left))
    {
        if(isSameTree(p->right,q->right))
        {
            if(p->val == q->val)
            {
                return true;
            }
            
        }
    }
    return false;
}