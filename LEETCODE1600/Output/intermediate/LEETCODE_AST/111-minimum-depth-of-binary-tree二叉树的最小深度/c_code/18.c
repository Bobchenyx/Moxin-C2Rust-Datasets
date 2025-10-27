/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 int BFS(struct TreeNode* root, int minDepth)
 {
     if (root == NULL) {
         return minDepth;
     }
     int leftDepth = BFS(root->left, minDepth + 1);
     int rightDepth = BFS(root->right, minDepth + 1);

     if (root->left == NULL || root->right== NULL) {
         return ((leftDepth > rightDepth) ? leftDepth : rightDepth);
     }

     return ((leftDepth > rightDepth) ? rightDepth : leftDepth);

 }


int minDepth(struct TreeNode* root){
    int minDepth = 0;    
    return BFS(root, minDepth);
}