int maxDepth(struct TreeNode* root);
bool isBalanced(struct TreeNode* root){
    if(root == NULL){
        return 1;
    }else if (abs(maxDepth(root->right) - maxDepth(root->left)) > 1){
        return 0;
    }
    return isBalanced(root->right)&&isBalanced(root->left);
}

int maxDepth(struct TreeNode* root){
    if(root == 0) return 0;

    int leftmaxDepth = maxDepth(root->left),
        rightmaxDepth = maxDepth(root->right);

    return(leftmaxDepth < rightmaxDepth? rightmaxDepth + 1 : leftmaxDepth + 1);
}