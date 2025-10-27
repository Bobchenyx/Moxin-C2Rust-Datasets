/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(root==NULL) return NULL;
    if(root->val==val){
        return root;
    }else if(root->val<val){//值小时递归右子树
        return searchBST(root->right,val);
    }else{
        return searchBST(root->left,val);
    }
}