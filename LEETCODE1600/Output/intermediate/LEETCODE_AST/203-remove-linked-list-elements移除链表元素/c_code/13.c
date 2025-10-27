struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode)), *q = head, *newHead;
    p -> next = head;
    newHead = p;
    while (q){
        if (q -> val == val)
            p -> next = q -> next;
        else
            p = p -> next; 
        q = q -> next;
    }
    p -> next = NULL;
    return newHead -> next;
}