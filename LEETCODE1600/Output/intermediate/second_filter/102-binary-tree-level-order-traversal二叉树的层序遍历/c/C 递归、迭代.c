// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000
int** levelOrder(struct TreeNode* root,
                 int* returnSize,
                 int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode *qu[MaxSize], *p;  //环形队列
    int front = 0, rear = 0, k = 0, i, sum;
    int** result = (int**)malloc(sizeof(int*) * MaxSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MaxSize);
    rear = (rear + 1) % MaxSize;
    qu[rear] = root;
    while (front != rear) {
        sum = (rear - front + MaxSize) % MaxSize;
        (*returnColumnSizes)[k] = sum;
        result[k] = (int*)malloc(sizeof(int)*sum);
        for (i = 0; i < sum; i++) {
            front = (front + 1) % MaxSize;
            p = qu[front];
            result[k][i] = p->val;
            if (p->left != NULL) {
                rear = (rear + 1) % MaxSize;
                qu[rear] = p->left;
            }
            if (p->right != NULL) {
                rear = (rear + 1) % MaxSize;
                qu[rear] = p->right;
            }
        }
        k++;
    }
    *returnSize = k;
    return result;
}