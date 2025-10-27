/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool Check(struct TreeNode* a,struct TreeNode* b)
{
    if(a==NULL&&b!=NULL||b==NULL&&a!=NULL) return false;
    else if(a==NULL&&b==NULL) return true;
    else
    {
        if(a->val==b->val) return Check(a->left,b->right)&&Check(a->right,b->left);
        else return false;
    }
}

bool isSymmetric(struct TreeNode* root){
    if(root!=NULL)
    return Check(root->left,root->right);
    else return true;
}