void inorder(struct TreeNode* root,int* returnSize,int *a)/*中序遍历二叉树*/
{
    if(!root) return;
    inorder(root->left,returnSize,a);
    
    a[(*returnSize)++]=root->val;
    inorder(root->right,returnSize,a);

}
int size(struct TreeNode* root)/*求二叉树数据个数*/
{
    if(!root) return 0;
    return size(root->left)+size(root->right)+1;
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
      int treesize=size(root);
      int *a=(int*)malloc(treesize*sizeof(int));
      memset(a,0,treesize);
      *returnSize=0;
      inorder(root,returnSize,a);
      return a;
}