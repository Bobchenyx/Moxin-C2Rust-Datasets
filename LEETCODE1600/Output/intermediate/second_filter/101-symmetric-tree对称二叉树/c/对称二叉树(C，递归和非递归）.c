bool isMirror(struct TreeNode* p, struct TreeNode* q)
{
    if(!p && !q)
        return 1;
    if(!p || !q)
        return 0;
    if(p->val == q->val)
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    else
        return 0;
}

bool isSymmetric(struct TreeNode* root){
    return isMirror(root, root);
}