/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* convertBST(struct TreeNode* root){
    if(root==NULL) return NULL;
    if(!root->left&&!root->right) return root;
    if(root->right){
        struct TreeNode *p=convertBST(root->right);
        while(p->left) p=p->left;
        root->val+=p->val;
    }
    if(root->left){
        struct TreeNode *q=root->left;
        while(q->right) q=q->right;
        q->val+=root->val;
        convertBST(root->left);
    }
    return root;
}