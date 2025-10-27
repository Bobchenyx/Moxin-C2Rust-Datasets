/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getting_the_numbers_out(struct TreeNode* root,  int** numbers, int* count);
struct TreeNode* increasingBST(struct TreeNode* root){
    
    int *numbers = malloc(sizeof(int)*100), 
        count = 0, 
        index = 0; 
    getting_the_numbers_out(root, &numbers, &count); 
    struct TreeNode *newhead = malloc(sizeof(*newhead)),
                    *next = newhead,
                    *current;
    
    newhead->val = numbers[index++];
    newhead->left = NULL;

    while(index < count){
        current = malloc(sizeof(*current));
        next->right = current;
        next = current;
        current->val = numbers[index++];
        current->left = NULL;
    }
    next->right = NULL;
    return newhead;
}


void getting_the_numbers_out(struct TreeNode* root,  int** numbers, int* count){
    
    if(root == NULL){
        return NULL;
    }
    getting_the_numbers_out(root->left,  numbers, count);
    *(*numbers + (*count)++) = root->val;
    getting_the_numbers_out(root->right, numbers, count);
}