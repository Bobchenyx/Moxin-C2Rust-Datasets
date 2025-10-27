int* postorderTraversal(struct TreeNode* root, int* returnSize){
     struct TreeNode **a=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*100);
    int *b=(int*)malloc(sizeof(int)*100);
    int i=0,top=0;
    struct TreeNode *p=root;
    a[top]=root;
    while(top!=-1){
        while(a[top]!=NULL)   a[++top]=a[top]->left;
        top--;
        if(top!=-1){
        if(a[top]->right==NULL||a[top]->right==p){
            p=a[top];
            b[i++]=a[top]->val;
            a[top]=NULL;
        }
        else a[++top]=a[top]->right;
        }
 }
    *returnSize=i;
    return b;
}