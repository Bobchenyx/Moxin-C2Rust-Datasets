/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define NUM 10000

int minDepth(struct TreeNode* root){
    if(root == NULL)
    {
        return 0;
    }

    int front = 0;
    int rear = 0;
    struct TreeNode *q[NUM];//create a queue
    struct TreeNode *cur;
    int depth = 1;
    int layerNum = 0;
    q[rear++] = root;//root enqueue

    while(rear != front)//Queue is not empty.
    {
        layerNum = rear - front;//Get the number to be processed in each layer
        
        for(int i = 0;i < layerNum;i++)
        {
            cur = q[front++];//the first element of the queue dequeue

            if(cur->left == NULL && cur->right == NULL)
            {
                return depth;
            }

            if(cur->left != NULL)
            {
                q[rear++] = cur->left;
            }

            if(cur->right != NULL)
            {
                q[rear++] = cur->right;
            }
        }

        depth++;
    }

    return depth;
}