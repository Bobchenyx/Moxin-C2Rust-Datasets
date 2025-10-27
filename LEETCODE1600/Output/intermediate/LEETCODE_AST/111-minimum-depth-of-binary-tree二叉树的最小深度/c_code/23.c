/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct QueueTree{
    struct TreeNode** data;
    int head,end;
};
int minDepth(struct TreeNode* root){
    int min=1;
    int weight;
    struct QueueTree q;
    q.data=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*10000);
    q.data[0]=root;
    if (root==NULL)
        return 0;
    q.head=0;
    q.end=1;
    while (1){
        weight=0;
        while (q.end-weight>q.head){
            if (q.data[q.head]->left==NULL&&q.data[q.head]->right==NULL)
                return min;
            if(q.data[q.head]->left!=NULL){
                q.data[q.end++]=q.data[q.head]->left;
                weight++;
            }
            if (q.data[q.head]->right!=NULL){
                q.data[q.end++]=q.data[q.head]->right;
                weight++;
            }
            q.head++;           
        }
        min++;
    }
    return min;
}