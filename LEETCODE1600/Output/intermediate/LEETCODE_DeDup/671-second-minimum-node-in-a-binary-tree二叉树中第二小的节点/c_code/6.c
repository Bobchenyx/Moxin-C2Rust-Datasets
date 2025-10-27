/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int dfs(struct TreeNode* root, int val) {
    if(root == NULL)
        return val;
    if(root->val > val)
        return root->val;
    
    int l, r;
    l = dfs(root->left, val);
    r = dfs(root->right, val);
    //printf("l=%d r=%d val=%d\n",l, r, val);
    if(l > val && r > val)
        return MIN(l, r);
    else
        return MAX(l, r);
}

int findSecondMinimumValue(struct TreeNode* root){
    int l,r;

    if(root == NULL || root->left == NULL)
        return -1;

    l = dfs(root->left, root->val);
    r = dfs(root->right, root->val);

    //printf("l=%d r=%d rootval=%d\n",l, r, root->val);
    if(l == r && l == root->val)    
        return -1;
    if(MIN(l,r) == root->val)   
        return MAX(l,r);
    else  
        return MIN(l,r);
}