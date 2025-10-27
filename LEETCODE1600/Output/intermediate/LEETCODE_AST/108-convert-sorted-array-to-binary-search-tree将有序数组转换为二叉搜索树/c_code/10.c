struct TreeNode* sortedArrayToBST(int* nums, int numsSize){

    if(numsSize == 0)
        return NULL;
    struct TreeNode* tree_table[numsSize];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* c = NULL;
    tree_table[0] = root;
    int i = 0, j = 0;

    while(i < numsSize){
        c = tree_table[i];
        if(j < numsSize - 1){
            if(j  < numsSize - 2){
                c->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                c->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                tree_table[j+1] = c->left;
                tree_table[j+2] = c->right;
            }else{
                c->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                c->right = NULL;
                tree_table[j+1] = c->left;
            }
            j = j + 2;
        }else{
            c->left = NULL;
            c->right = NULL;
        }
        i++;
    }

    i = 0;
    j = 0;
    struct TreeNode* loop_table[numsSize];
    loop_table[j] = tree_table[j];
    while(i < numsSize){
        while(loop_table[j]->left != NULL){
            loop_table[j+1] = loop_table[j]->left;
            j++;
        }
        loop_table[j]->val = nums[i++];
        if(loop_table[j]->right != NULL){
            loop_table[j] = loop_table[j]->right;
        }else{
            loop_table[j] = NULL;
            j--;
            while(j >= 0 && loop_table[j]->right == NULL){
                loop_table[j]->val = nums[i];
                loop_table[j] = NULL;
                i++;
                j--;
            }
            if(j < 0)
                break;
            loop_table[j]->val = nums[i++];
            loop_table[j] = loop_table[j]->right;
        }
    }
    return root;
}