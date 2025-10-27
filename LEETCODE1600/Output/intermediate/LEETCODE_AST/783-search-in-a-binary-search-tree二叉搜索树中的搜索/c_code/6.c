struct TreeNode* searchBST(struct TreeNode* root, int val){
    while(root){
        if(val==root->val)
            return root;
        else if(val>root->val)
            root=root->right;
        else root=root->left;
    }
    return 0;
}