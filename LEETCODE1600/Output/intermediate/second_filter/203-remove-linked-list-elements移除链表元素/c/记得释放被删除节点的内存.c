struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *prev = NULL, *cur = head, *t;
    while(cur != NULL){
        if(cur->val == val){
            if(prev == NULL){
                head = cur->next;
            }else{
                prev->next = cur->next;
            }
            t = cur;
            cur = cur->next;
            free(t);
        }else{
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}