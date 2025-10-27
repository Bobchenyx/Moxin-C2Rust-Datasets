/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* helper(int left,int right,int *nums){
    if(left >= right){
        return NULL;
    }
    int midpos = 0;
    midpos = (left+right)/2;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = nums[midpos];
    node->left = helper(left,midpos,nums);
    node->right = helper(midpos+1,right,nums);

    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    int nums[100000],numsSize=0;
    for(;head !=NULL;head = head->next){
        nums[numsSize] = head -> val;
        numsSize++;
    }
    return helper(0,numsSize,nums);
}