/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    struct TreeNode *s1[10],*s2[10];//栈
    int i=-1,j=-1;//初始化栈
    if(p==!q)return false;
    while((p||i>-1)&&(p||j>-1)){
        if(p&&q){
            s1[++i]=p;
            s2[++j]=q;
            p=p->left;
            q=q->left;
        }else if(p==q){
            p=s1[i--];
            q=s2[j--];
            if(p->val!=q->val)return false;
            p=p->right;
            q=q->right;
        }else return false;
    }
    return true;
}