struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (n <= 0) {
        return 0;
    }
    struct ListNode *first, *second, *ret;
    ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    first = ret;
    second = ret;
    ret->next = head;
    first->next = head;
    second = head;
    while (n > 0) {
        second = second->next;
        n--;
    }
    while (second != NULL) {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return ret->next;
}