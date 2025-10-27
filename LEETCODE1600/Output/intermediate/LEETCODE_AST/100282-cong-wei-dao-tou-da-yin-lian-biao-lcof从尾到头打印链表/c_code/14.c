int* reversePrint(struct ListNode* head, int* returnSize){
    if(head == NULL){
        *returnSize = 0;
        return malloc(sizeof(int) * 10000);
    }
    int *ans = reversePrint(head->next, returnSize);
    ans[(*returnSize)++] = head->val;
    return ans;
}