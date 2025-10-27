struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* tail = head;
    int i = 1;
    if (head == NULL) return NULL;
    
    while (i++ < n) {
        if (tail->next != NULL) tail = tail->next;
    }
    
    if (tail != NULL && tail->next == NULL) {
        tail = head;
        head = head->next;
        free(tail);
        return head;
    }
    struct ListNode* pre = head;
    tail = tail->next;
    
    while (tail->next != NULL) {
        tail = tail->next;
        pre = pre->next;
    }
    tail = pre->next;
    pre->next = tail->next;
    free(tail);
    
    return head;
}