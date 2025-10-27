/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int _caculate(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=_caculate(root->left);
    int right=_caculate(root->right);
    if(left!=-1&&right!=-1&&abs(left-right)<2){
        if(left>right){
            return left+1;
        }else{
            return right+1;
        }
    }else{
        return -1;
    }
}

bool isBalanced(struct TreeNode* root){
    int res=_caculate(root);
    if(res==-1){
        return false;
    }else{
        return true;
    }
}