//方法一：递归,看左右子树它们的两个是否有相同的值，每个树的右子树都与另一个树的左子树镜像对称。
int  isSymmetricRercursion(struct TreeNode* l,struct TreeNode* r){
    if(!l && !r){
        return 1;
    }else if(l && r && l->val==r->val){
        int i = isSymmetricRercursion(l->left,r->right);  // ll 和 rr
        int j = isSymmetricRercursion(l->right,r->left);  // lr 和 rl
        if(i && j){
            return  1;
        }
    }
    return 0;
}

bool isSymmetric(struct TreeNode* root){
    if(root){
        int i = isSymmetricRercursion(root->left,root->right);
        if(i == 1){
            return true;
        }else{
            return false;
        }   
    }
    return true;
}