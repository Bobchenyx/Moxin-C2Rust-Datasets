/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* construct(int* preorder, int preleft,int preright, int* inorder, int inleft,int inright){
    int i,leftson;
    if(preleft>preright)return NULL;
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=preorder[preleft];
    for(i=inleft;i<=inright;i++){
        if(inorder[i]==root->val)break;
    }
    leftson=i-inleft;
    root->left=construct(preorder,preleft+1,preleft+leftson,inorder,inleft,i-1);
    root->right=construct(preorder,preleft+leftson+1,preright,inorder,i+1,inright);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return construct(preorder, 0, preorderSize - 1, inorder, 0 ,inorderSize - 1);
}