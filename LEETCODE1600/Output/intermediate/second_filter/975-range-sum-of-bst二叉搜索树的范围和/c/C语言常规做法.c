int rangeSumBST(struct TreeNode* root, int L, int R){
    if(root){
        if(root->val<L)
            return rangeSumBST(root->right,L,R);
        else if(root->val>R)
            return rangeSumBST(root->left,L,R);
        else
            return root->val + rangeSumBST(root->left,L,R)+rangeSumBST(root->right,L,R);
    }
    return 0;
}