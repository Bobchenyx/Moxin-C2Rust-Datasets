/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root, int* sum) {
    if (root == NULL) {
        return;
    }
    if (root->val % 2 == 0) {
        if (root->left != NULL) {
            if (root->left->left != NULL) {
                *sum += root->left->left->val;
            }
            if (root->left->right != NULL) {
                *sum += root->left->right->val;
            }
        }
        if (root->right != NULL) {
            if (root->right->left != NULL) {
                *sum += root->right->left->val;
            }
            if (root->right->right != NULL) {
                *sum += root->right->right->val;
            }
        }
        printf("%d\n", *sum);
    } 
    dfs(root->left, sum);
    dfs(root->right, sum);
    return *sum;
}


int sumEvenGrandparent(struct TreeNode* root){
    int sum = 0;
    int ans = dfs(root, &sum);
    return ans;
}