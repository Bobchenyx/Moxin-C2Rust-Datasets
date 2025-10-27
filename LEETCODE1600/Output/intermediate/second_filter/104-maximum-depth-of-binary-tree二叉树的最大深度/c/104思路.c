/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
    int leftcount = maxDepth(root->left);
    int rightcount = maxDepth(root->right);
  if (leftcount > rightcount) {
      return leftcount + 1;
  } else {
      return rightcount + 1;
  }
}