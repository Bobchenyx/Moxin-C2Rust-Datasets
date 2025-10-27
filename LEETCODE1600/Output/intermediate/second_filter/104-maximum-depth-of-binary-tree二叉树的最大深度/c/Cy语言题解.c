/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void nextDepth(struct TreeNode *root, int *depth)
{
    int depthLeft = *depth;
    int depthRight = *depth;   
    if (root == NULL) {
        return *depth;
    }

    depthLeft++;
    depthRight++;

    nextDepth(root->left, &depthLeft);
    nextDepth(root->right, &depthRight);
    *depth = (depthLeft > depthRight ? depthLeft : depthRight);
}

int maxDepth(struct TreeNode* root){
    int depth = 0;
    nextDepth(root, &depth);

    return depth;
}