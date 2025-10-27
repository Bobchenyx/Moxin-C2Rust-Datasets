/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int searchDeep(struct TreeNode *root,int *length)//找到该树中能够到达的最深
{
    if(!root)
    return 0;
    if(!root->left&&!root->right)
    return 1;
    int leftl=searchDeep(root->left,length);
    int rightl=searchDeep(root->right,length);
    if(leftl+rightl>*length)
    *length=leftl+rightl;
    return (leftl>rightl?leftl:rightl)+1;
}
int diameterOfBinaryTree(struct TreeNode* root){
    if(!root)
    return 0;
    int length=0;
    int leftl=searchDeep(root->left,&length);
    int rightl=searchDeep(root->right,&length);
    return length>(leftl+rightl)?length:(leftl+rightl);
}