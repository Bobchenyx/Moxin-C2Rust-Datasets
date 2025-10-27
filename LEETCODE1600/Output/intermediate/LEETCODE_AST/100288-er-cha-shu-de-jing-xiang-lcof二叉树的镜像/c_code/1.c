/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void preorder(struct TreeNode *root){
    if(root==NULL)return ;
    if(root->left)preorder(root->left);
    if(root->right)preorder(root->right);
    if(root->left&&root->right){
       struct TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    else if(root->left&&!root->right){
        root->right=root->left;
        root->left=NULL;
    }
    else if(!root->left&&root->right){
         root->left=root->right;
        root->right=NULL;
    }
}

struct TreeNode* mirrorTree(struct TreeNode* root){
    preorder(root);
    return root;
}