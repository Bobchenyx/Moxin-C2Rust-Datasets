/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define  MAX  10000

void traver(struct TreeNode* root, int* returnSize, int* out)
{
    if (root == NULL) {
        return;
    }

    traver(root->left, returnSize, out);
    out[*returnSize] = root->val;
    *returnSize = *returnSize + 1;
    traver(root->right, returnSize, out);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* out = (int*) malloc(MAX * sizeof(int));
    if (out == NULL) {
        return NULL;
    }
    *returnSize = 0;
    memset(out, 0, MAX * sizeof(int));
    traver(root, returnSize, out);
    return out;
}