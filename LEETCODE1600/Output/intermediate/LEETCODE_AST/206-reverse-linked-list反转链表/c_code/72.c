struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode *next, *prev, *t;
    prev = NULL;
    next = head->next;
    for(; next != NULL;){
        t = head;
        head = next;
        next = next->next;
        t->next = prev;
        prev = t;
    }
    head->next = prev;
    return head;
}