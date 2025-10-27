#define max 1000
struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode *stack[max],*t,*pre=NULL,*new_root=NULL;
    int top=-1;
    t=root;
    while(t||top>=0){
        while(t)
        {
            stack[++top]=t;
            t=t->left;            
        }
        if(top>=0){
            t=stack[top--];
            //确定新的根结点
            if(!new_root)
                new_root=t;
            else{
                //前一点在序列中的位置已经确定 并且已经出栈了 所以可以修改left 和right 指针  而不会影响后续遍历
                pre->right=t;
                pre->left=NULL;
            }
            pre=t;
            t=t->right;
        }
    }
    //修改最后一个节点的left指针
    pre->left=NULL;
    return new_root;    
}