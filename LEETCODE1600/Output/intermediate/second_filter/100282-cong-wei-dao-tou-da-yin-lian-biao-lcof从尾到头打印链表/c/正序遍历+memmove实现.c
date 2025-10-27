/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
#define ARR_SIZE    10000
    int *stack = (int *)calloc(ARR_SIZE, sizeof(int));
    int *temp = stack + ARR_SIZE - 1;

    *returnSize = 0;

    while (head)
    {
        *temp-- = head->val;
        head = head->next;
        (*returnSize)++;
    }

    memmove(stack, temp+1, *returnSize * sizeof(int));
    
    return stack;
}