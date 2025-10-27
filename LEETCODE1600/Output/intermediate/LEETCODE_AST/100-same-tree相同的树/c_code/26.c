bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p && !q)
        return 1;
    if(!p)
        return 0;
    if(!q)
        return 0;
    if(p->val == q->val) 
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    else
        return 0;
}