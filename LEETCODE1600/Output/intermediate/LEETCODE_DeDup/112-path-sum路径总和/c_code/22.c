/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool SubFuncDFS(struct TreeNode* root, int sum, int tmpSum)
{
    bool returnVal = false;
    tmpSum = tmpSum + root->val;
    if ((tmpSum != sum) && (root->left == NULL) && (root->right == NULL)) {
        return false;
    }
    if (tmpSum == sum) {
        if ((root->left == NULL) && (root->right == NULL)) {
            return true;
        }
    }
    if (root->left != NULL) {
        returnVal = SubFuncDFS(root->left, sum, tmpSum);
        if (returnVal == true) {
            return true;
        }
    }
    if (root->right != NULL) {
        returnVal = SubFuncDFS(root->right, sum, tmpSum);
        if (returnVal == true) {
            return true;
        }
    }

    return returnVal;
}

bool hasPathSum(struct TreeNode* root, int sum)
{
    bool returnVal = false;
    int tmpSum = 0;
    if (root == NULL) {
        return false;
    }
    returnVal = SubFuncDFS(root, sum, tmpSum);

    return returnVal;
}