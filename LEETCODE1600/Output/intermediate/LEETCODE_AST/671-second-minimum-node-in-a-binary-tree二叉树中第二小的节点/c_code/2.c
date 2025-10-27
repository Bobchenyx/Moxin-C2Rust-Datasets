/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void findSecMinProcess(int *minFirst, int *minSecond, struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    if ((root->val > *minFirst) && ((root->val < *minSecond) || (*minSecond == -1))) {
        *minSecond = root->val;
    } else if ((root->val < *minFirst)) {
        *minSecond = *minFirst;
        *minFirst = root->val;
    }
 
    findSecMinProcess(minFirst, minSecond, root->left);  
    findSecMinProcess(minFirst, minSecond, root->right);
}

int findSecondMinimumValue(struct TreeNode* root){
    int minFirst = -1;
    int minSecond = -1;
    
    if (root == NULL) {
        return -1;
    }
    
    minFirst = root->val;
    findSecMinProcess(&minFirst, &minSecond, root->left);
    findSecMinProcess(&minFirst, &minSecond, root->right);
    
    return minSecond;
}